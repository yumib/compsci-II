#include "browserhistory.h" 


// Creates a new browser history with only one page visited: default_url
BrowserHistory::BrowserHistory(string default_url)
{
 past.push(default_url); //past.size() == 1
}

// Returns the current page.
string BrowserHistory::current_url()
{
  return past.top();
}
		// Moves the browser to a new page via url,
		// e.g., clicking a link, typing into the address bar, etc. 
void BrowserHistory::go_to_url(string url)
{
  past.push(url);  
while(future.size() > 0)
  {
    future.pop();
  }
  
}

		// Moves back (into the past) by one url.
		// 
		// If there is no past url to move to, does nothing.
void BrowserHistory::back()
{
  if (can_go_back())
  {
    future.push(past.top());
    past.pop();
    past.top();
  }
}

		// Returns whether there is a url in the past,
		// i.e. whether the back button can be pushed. 
bool BrowserHistory::can_go_back()
{
  if (past_url_count() == 0)
    return false;
  else
    return true;
  
}

		// Returns how many urls are in the past,
		// i.e. how many times in a row the back button could be pushed. 
int BrowserHistory::past_url_count()
{
  return past.size() - 1;
}

		// Moves forward (into the future) by one url.
		// 
		// If there is no future url to move to, does nothing.
void BrowserHistory::forward()
{
  if (can_go_forward())
  {
    past.push(future.top());
    future.pop();
    future.top();
  }
}

		// Returns whether there is a url in future,
		// i.e. whether the future button can be pushed. 
bool BrowserHistory::can_go_forward()
{
   if (future_url_count() == 0)
    return false;
  else
    return true; 

}

		// Returns how many urls are in the future,
		// i.e. how many times in a row the forward button could be pushed.
int BrowserHistory::future_url_count()
{
return future.size(); 
}