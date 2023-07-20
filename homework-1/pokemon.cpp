#include "pokemon.h"

enum Type {Normal, Fighting, Flying, Poison}; //declaration not a function

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
  if (type_count == 2)
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