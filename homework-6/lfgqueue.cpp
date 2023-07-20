#include "lfgqueue.h"
#include "player.h"


	// Constructs a new empty queue with capacity for 100 players
	LFGQueue :: LFGQueue()
{
  count = 0;
  capacity = 100;
  players = new Player* [100];
  for (int i = 0; i < 100; ++i)
    {
      players[i] = nullptr;
    }
}


// Returns the number of players in the queue.
int LFGQueue :: size()
{
  return count;
}


// Adds a (pointer to a) player to the back of the queue.
// If there is no room for the new player it doubles the
// capacity of the queue before adding the player
void LFGQueue :: push_player(Player* p)
{
  if (count >= capacity)
  {
    Player** new_players = new Player* [2*capacity];
    for (int i = 0; i < capacity; ++i)
        new_players[i] = players[i];
    delete[] players;
    players = new_players;
    capacity *= 2;
  }
  players[count] = p;
  ++count;

}


// Returns a pointer to the frontmost player 
// with the specified role. If no such player 
// exists, returns nullptr.
Player* LFGQueue :: front_player(Player::Role r)
{
  for (int i = 0; i < count; ++i)
    {
      if ((*players[i]).role() == r)
        return players[i];
    }
  return nullptr;
}


// Removes the frontmost player with the
// specified role. If no such player exists
// does nothing.
void LFGQueue :: pop_player(Player::Role r)
{
  for (int i = 0; i < count; ++i)
    {
      if ((*players[i]).role() == r)
      {
        for (int j = i; j < count-1; ++j)
          players[j] = players[j+1];
        --count;
        break;
      }
    }
}


// Returns whether the queue contains a complete group
// (a Defender, a Hunter, and a Bard).
//
// If the queue contains a complete group, the method
// sets the first three elements of the array parameter
// equal to the addresses of the frontmost:
// 1. Defender (index 0)
// 2. Hunter (index 1)
// 3. Bard (index 2)
bool LFGQueue :: front_group(Player** group)
{
  group[0] = front_player(Player::Defender);
  group[1] = front_player(Player::Hunter);
  group[2] = front_player(Player::Bard);

if (group[0] != nullptr && group[1] != nullptr && group[2] != nullptr)
    return true;
  else
    return false;
}


// Removes the frontmost Defender, Hunter, 
// and Bard from the queue. If some role
// has no player with that role, then
// no players are removed.
void LFGQueue::pop_group()
{
  Player* defender = front_player(Player::Defender);
  Player* hunter = front_player(Player::Hunter);
  Player* bard = front_player(Player::Bard);

  if(defender != nullptr && hunter != nullptr && bard != nullptr)
  {
    pop_player(Player::Defender);
    pop_player(Player::Hunter);
    pop_player(Player::Bard);
  }
}