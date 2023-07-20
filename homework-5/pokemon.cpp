#include "pokemon.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
//From Homework 5:

//This function works by creating an array of chars that holds the summary string. For loops look for the commas and add everything before comma to respective string variable.
Pokemon :: Pokemon(string summary)  
{
 int size = summary.size(); //returns size of string
 char A[size]; //declares array w/ index of string size
 int comma1, comma2, comma3;  //will note the position of commas
 string ndex="", type1="", type2=""; //stores the ndex and types as a string 


 for (int i = 0; i < size; ++i)  //puts every character into array
     A[i] = summary.at(i);

for (int j = 0; j < size; ++j) //finds comma and assigns string to _name
  {
    if (A[j] == ',')
    {
      comma1 = j;
      for (int i = 0; i < j; ++i)
          _name += A[i];
      type_count = 1;
      break;
    }
  }

for (int j = comma1 + 1; j < size; ++j) //finds comma and assigns string to _ndex
  {
    if (A[j] == ',')
    {
      comma2 = j;
      for (int i = comma1 + 3; i < j; ++i)
          ndex += A[i];
      _ndex = stoi(ndex); //converts ndex to an int and stores in private data member 
      break;
    }
  }

for (int j = comma2 + 1; j < size; ++j) //finds comma and assigns string to type1
  {
    type_count = 1;
    if (A[j] == ',')
    {
      comma3 = j;
      for (int i = comma2 + 2; i < j; ++i)
          type1 += A[i];
      types[0] = string_to_type(type1);
      break;
    }
  }

if (comma3 + 1 < size) //executes if there is a type2 to construct 
  {
  type_count = 2;
  for (int j = comma3 + 1; j < size; ++j) //finds comma and assigns string to type2
      {
        if (A[j] == ',')
        {
          for (int i = comma3 + 2; i < j; ++i)
            type2 += A[i];
        types[1] = string_to_type(type2);
        break;      
        }
      }
  }

}

// Returns the summary string of the Pokemon. Works by assigning ostringstream summary the contents of the private data members and formats text correctly.
string Pokemon :: summary()
{
  ostringstream summary("");

if (is_multitype() == 0) //if there is only type1
  {
  summary << _name << ", " << '#' << setfill('0') << setw(3) << _ndex << ", " << type_to_string(types[0]) << ',';
  return summary.str();
  }
  else //executes if there is type2
  {
    summary << _name << ", " << '#' << setfill('0') << setw(3) << _ndex << ", " << type_to_string(types[0]) << ", " << type_to_string(types[1]) << ',';
    return summary.str();
  }
}

//Auxilarry functions:

// Returns a string corresponding to the type. Examples:
// 1. type_to_string(Pokemon::Poison) returns "Poison".
// 2. type_to_string(Pokemon::Normal) returns "Normal". 
string type_to_string(Pokemon::Type t)
{
  switch(t)
  {
  case Pokemon::Poison:
    return "Poison";
  case Pokemon::Normal:
    return "Normal";
  case Pokemon::Flying:
    return "Flying";
  case Pokemon::Fighting:
    return "Fighting";
    }
}
// Returns the type corresponding to a string. Examples:
// 1. string_to_type("Poison") returns Pokemon::Poison.
// 2. string_to_type("Flying") returns Pokemon::Flying.
// 3. If the given string doesn't correspond to a Pokemon type
//    return Pokemon::Normal
Pokemon::Type string_to_type(string s)
{
  if (s == "Fighting")
    return Pokemon::Fighting;
  else if (s == "Flying")
    return Pokemon::Flying;
  else if (s == "Poison")
    return Pokemon::Poison;
  else
    return Pokemon::Normal;
}



//From Homework 1:

// Initializes a single-type Pokemon using the information provided
Pokemon::Pokemon(string name, int ndex, Type type1)
{
  _name = name;
  _ndex = ndex;
  types[0] = type1;
  type_count = 1;
}

// Initializes a multi-type Pokemon using the information provided
Pokemon::Pokemon(string name, int ndex, Type type1, Type type2)
{
_name = name;
_ndex = ndex;
types[0] = type1;
types[1] = type2;
type_count = 2;
}

// Returns the name of the pokemon 
string Pokemon::name()
{
  return _name;
}

// Returns the Ndex (national index) of the Pokemon
int Pokemon::Ndex()
{
  return _ndex;
}

// Returns the first (and possibly only) type of the Pokemon
Pokemon::Type Pokemon::type1()
{
  return types[0];  
}

// Returns whether the Pokemon has multiple types
bool Pokemon::is_multitype()
{
  if (type_count == 2 && types[0] != types[1])
    return true;
  else
    return false;
}

// If the Pokemon has two types, returns the second type of the Pokemon.
// Otherwise returns the Pokemon's only type.
Pokemon::Type Pokemon::type2()
{
  if (type_count == 2)
   return types[1];
  else 
    return types[0];
}

float Pokemon::damage_multiplier(Type attack_type)
{
  float dmg1, dmg2;
  float grid[4][4];
  //creation of damage grid stored in array grid[4][4]
  grid[0][0] = 1.;        
  grid[0][1] = 1.;
  grid[0][2] = 1.;
  grid[0][3] = 1.;
  
  grid[1][0] = 2.;
  grid[1][1] = 1.;
  grid[1][2] = 0.5;
  grid[1][3] = 0.5;

  grid[2][0] = 1.;
  grid[2][1] = 2.;
  grid[2][2] = 1.;
  grid[2][3] = 1.;

  grid[3][0] = 1.;
  grid[3][1] = 1.;
  grid[3][2] = 1.;
  grid[3][3] = 0.5;
  
  //checks if there are two defend types
  if(is_multitype() == 0)     
  {
    int atk = attack_type, def1 = type1();
    float poke[atk][def1];
    //returns if atack type and defend type1() are equivalent to grid
    for (int row = 0; row < 4; ++ row)
      {
        if (atk == row)
        {
          for (int col = 0; col < 4; ++col)
            {
              if (def1 == col)
                return grid[row][col];
            }
        }
      }
  }

  //executes if there are two defend types
  else
  {
    int atk = attack_type, def1 = type1(), def2 = type2();
    //returns if atack type and defend type1() are equivalent to grid
    for (int row = 0; row < 4; ++ row)
      {
        if (atk == row)
        {
          for (int col = 0; col < 4; ++col)
            {
              if (def1 == col)
                dmg1 = grid[row][col];
            }
        }
      }
    //returns if atack type and defend type2() are equivalent to grid
    for (int row = 0; row < 4; ++ row)
      {
        if (atk == row)
        {
          for (int col = 0; col < 4; ++col)
            {
              if (def2 == col)
                dmg2 = grid[row][col];
            }
        }
      }
  }
  //multiplies and returns the numbers from above for loops 
  return dmg1 * dmg2;  
}