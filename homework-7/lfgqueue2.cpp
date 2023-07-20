#include "lfgqueue.h"


// Constructs a new empty queue
LFGQueue::LFGQueue()
{
  for (int i = 0; i < 3; ++i) //loops through all queues
    {
      heads[i] = nullptr;
      tails[i] = nullptr;
      counts[i] = 0;
    }
}


// Returns the number of players in the queue.
int LFGQueue::size()
{
  int sum = 0;
  for (int i = 0; i < 3; ++i) //loops through each queue
    sum += counts[i];  //adds all sizes into sum 
  return sum;
}


// Adds a player to the back of the queue.
void LFGQueue::push_player(Player* plyr)
{
  Node* aux = new Node; //creates new Node
  aux -> p = plyr;
  aux -> next = nullptr;

  if (counts[plyr->role()] == 0) //if there is no Nodes prior
  {
    heads[plyr->role()] = aux;
    tails[plyr->role()] = aux;   
  }
  else
  {
    tails[plyr->role()] -> next = aux; //connects node
    tails[plyr->role()] = aux;  //changes tail position
  }
  ++counts[plyr->role()]; //increase count
}


// Returns a pointer to the frontmost player 
// with the specified role. If no such player 
// exists, returns nullptr.
Player* LFGQueue::front_player(Player::Role r)
{
  if (counts[r] == 0) //if no nodes prior
    return nullptr;
  else
    return heads[r]->p; //dereference front player of queue
}


// Removes the frontmost player with the
// specified role. If no such player exists
// does nothing.
void LFGQueue::pop_player(Player::Role r)
{
 if (counts[r] == 0)  //if no nodes prior
 {
   tails[r] = nullptr;
   return;
 }
  Node* aux = heads[r]; //creates aux pointer to keep track
  heads[r] = heads[r] -> next; 
  delete aux; //deletes aux
  --counts[r];
}

//Functions From last HW (copied and pasted):
// Returns whether the queue contains a complete group
// (a Defender, a Hunter, and a Bard).
//
// If the queue contains a complete group, the method
// sets the first three elements of the array parameter
// equal to the addresses of the frontmost:
// 1. Defender (index 0)
// 2. Hunter (index 1)
// 3. Bard (index 2)
bool LFGQueue::front_group(Player** group)
{
  group[0] = front_player(Player::Defender);
  group[1] = front_player(Player::Hunter);
  group[2] = front_player(Player::Bard);

if (group[0] != nullptr && group[1] != nullptr && group[2] != nullptr)
    return true;
  else
    return false;
}

//Functions From last HW (copied and pasted):
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