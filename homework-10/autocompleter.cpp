#include "autocompleter.h"

// Creates a new, empty autocompleter. Initial capacity is 100 elements.
Autocompleter :: Autocompleter() 
{
  A = new string[100];
  capacity = 100;
  count = 0;
  for (int i = 0; i < capacity; ++i) // initializes empty array
    A[i] = "";
}

// Adds x to the list of potential suggestions in the Autocompleter in the
// position that will keep Autocompleter sorted after the insertion. MUST double
// the capacity when necessary. If the word is already in the Autocompleter,
// does nothing.
//
// MUST run in O(n) time.
void Autocompleter :: insert(string x) 
{
 int index = index_of(x, A, count); //where x is or where it should be
  
//SPECIAL CASES:
if (A[index] == x) //if already in array
  return;
else if (count == 0) //if empty array
  {
    A[0] = x; //adds and updates count
    ++count;
    return;
  }
else if (A[index] == "") //if needs to be placed in empty string
  {
    A[index] = x; //adds and updates count
    ++count;
    return;
  }
else if (count >= capacity || index >= capacity) //doubles array if x needs to be added in last index or further
  {
    string *new_A = new string[capacity * 2];
    for (int i = 0; i < count; ++i)
      new_A[i] = A[i]; //copies old array into new array
    delete[] A; //delete old array
    A = new_A;  //assign old array the new array
    capacity *= 2; //updates capacity

    if (index > capacity) //needs to be added AFTER everything in array
    {
      A[index] = x; //adds and updates count
      ++count;
      return;
    }
  }

  //IF SPECIAL CASES ARE FALSE:
  string* temp_A = new string[capacity]; //creates a temp array
  for (int i = 0; i < capacity; ++i) //initializes w/ empty string
    temp_A[i] = "";
  for (int i = 0; i < count; ++i) //copies elements into temp array from old array
      temp_A[i] = A[i];
  
  for (int i = index; i < count; ++i)
      temp_A[i+1] = A[i]; //moves strings to the right by 1
  temp_A[index] = x; //inserts new string
  delete[] A; //deletes content of old array
  A = temp_A; //assigns new array to old one
  ++count; //update count
}

// Returns the number of strings in the Autocompleter.
int Autocompleter :: size() 
{ 
  return count; 
}

// Returns the number of strings that are completions of
// the parameter string x.
//
// MUST run in O(log(n)) time.
int Autocompleter :: completion_count(string x) 
{
if (x == "") //special case
 return count;
  
int completions = 0; //number of completed autocorrect
int string_size = x.size(); //loop purposes
int comparison = 0; //comparison purposes
string start = "";
start = start + x[0]; //take the first char of x 
int index = index_of(start, A, count); //indicates start of comparison
  
 for (int i = index; i < count; ++i) //decides what string to start comparing
   {
     comparison = 0;
     string compare = A[i];
    for (int j = 0; j < string_size; ++j) //compares character by character
      {
        if (x[j] == compare[j]) //comparison is used as a way to keep track if the entire string was compared and correct
          ++comparison;

        if (comparison == string_size) //if entire compare string was equal to x
        {
          ++completions; //if all tests pass then completion counted
          comparison = 0;
        }
      }
   }
  return completions;
}

// Takes a string (parameter x) and string array of length 5 (parameter
// suggestions) Sets the first five elements of suggestions equal to the first
// five (in lexicographic order) strings in the Autocompleter that start with x.
//
// If there are less than five such strings, the remaining
// entries of the suggestions array are set to "" (the empty string)
//
// MUST run in O(log(n)) time.
void Autocompleter :: completions(string x, string *suggestions) 
{
  int auto_count = completion_count(x); //number of autocompletes available for string x
  int index = index_of(x, A, count); //needed info to know which strings to access in array A
  for (int j = 0; j < 5; ++j) //initializes to empty strings
    suggestions[j] = "";

  if (auto_count >= 5) // if there is more than 5 strings
  {
    for (int i = 0; i < 5; ++i) //fills all 5 spaces in sggestions
      suggestions[i] = A[index+i];
  }
  else //if there is less than 5 strings 
  {
  for(int i = 0; i < auto_count; ++i) //fills as many strings that are available to suggestions
    suggestions[i] = A[index+i]; //leaves the rest ""
  }
}



// string get(int x) {return A[x];}		// Uncomment this statement only
// if you need it for debugging purposes

// Helper method.
//
// Assumes A is SORTED.
// If x is in A, returns the index of A containing x.
// Otherwise, returns the index of A where x should be inserted
// (that is, the position where it would be after calling insert(x)).
//
// MUST run in O(log(n)) time (use binary search).
int Autocompleter :: index_of(string x, string *A, int n)
{
  int l = 0, r = n-1, m; //left, right, and middle markers

  while (l <= r) //makes sure markers dont cross over
  {
    m = (l+r)/2;
    if (A[m] == x) //returns if m is equal to string
      return m;
    else if (A[m] < x) //search right
      l = m + 1;
    else //(A[m] > x) -> search left
      r = m - 1;
  }
  return l; 
  //if x not found in array, return index of where it SHOULD be
  //works in cases where index of insertion in within capacity and beyond capacity 
}