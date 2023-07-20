#include "browserhistory.h"

// Creates a new browser history with only one page visited: default_url
BrowserHistory :: BrowserHistory(string default_url)
{
  Node * p = new Node;
  p -> prev = p -> next = nullptr; //creates node
  p -> url = default_url;  //initilizes all info
  head = tail = current = p;  //sets pointers to null
}

// Returns the current page.
string BrowserHistory :: current_url()
{ 
  return current -> url; //current url dereferenced and returned
}

// Moves the browser to a new page url via,
// e.g., clicking a link, typing into the address bar, etc. 
void BrowserHistory :: go_to_url(string url)
{
  if (current -> next != nullptr) //replaces url in special case
  {
    Node * aux = current;  //creation of node
    while (aux -> next != nullptr) //pops nodes that are cut out through special case 
      {
        Node * pop = tail;
        tail = tail -> prev;
        tail -> next = pop -> prev = nullptr;
        delete pop;
      }
  }
  Node * p = new Node;  //creation of node
  p -> next = p -> prev = nullptr; //initializes info
  p -> url = url;

  p -> prev = tail;  //pushes new node through the back
  tail -> next = p;
  tail = p;
  current = tail; 
}

// Moves back (into the past) by one url.
void BrowserHistory :: back()
{
  if (current -> prev != nullptr) //if can_go_back()
    current = current -> prev; 
}

// Returns whether there is a url in the past,
// i.e. whether the back button can be pushed. 
bool BrowserHistory :: can_go_back()
{
  if (current -> prev != nullptr) 
    return true;
  return false;
}

// Returns how many urls are in the past,
// i.e. how many times in a row the back button could be pushed. 
int BrowserHistory :: past_url_count()
{
  Node * aux = current; //creates aux pointer to count nodes
  int count = 0;
  while (aux != head) //loops through past nodes
    {
      ++count;
      aux = aux -> prev;
    }
  return count;
}

// Moves forward (into the future) by one url.
void BrowserHistory :: forward()
{
  if (current -> next != nullptr) //if can_go_forward
    current = current -> next;
  
}

// Returns whether there is a url in future,
// i.e. whether the future button can be pushed. 
bool BrowserHistory :: can_go_forward()
{
  if (current -> next != nullptr)
    return true;
  return false;
}

// Returns how many urls are in the future,
// i.e. how many times in a row the forward button could be pushed.
int BrowserHistory :: future_url_count()
{
  Node * aux = current; //creates aux pointer
  int count = 0;
  while (aux != tail) //loops through forward nodes
    {
      aux = aux -> next;
      ++count;
    }
  return count;
}