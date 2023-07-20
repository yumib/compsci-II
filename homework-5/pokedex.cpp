#pragma once
#include "pokemon.h"
#include "pokedex.h"
#include <iostream>
#include <fstream>
#include <cassert>
// Constructs an empty pokedex.
Pokedex :: Pokedex()
{
  for (int i = 0; i < 1000; ++i)
    A[i] = nullptr;
}


// Constructs a Pokedex with the Pokemon found in
// the specified file. 
Pokedex :: Pokedex(string filename)
{
  for (int i = 0; i < 1000; ++i)
    {
    A[i] = nullptr;
    }
ifstream inFile;
inFile.open(filename);
assert(inFile.is_open());
string input;
while(getline(inFile,input))
  {
  Pokemon *p = new Pokemon(input);
    A[p ->Ndex()] = p;
  }
 inFile.close(); 
}

// Writes the Pokedex to the file.
void Pokedex :: save(string filename)
{
  ofstream oFile;
  oFile.open(filename);
  for (int i = 0; i < 1000; ++i)
    {
    if(A[i] != nullptr)
    {
      oFile << A[i] -> summary() << endl;
    }
      }
  oFile.close();
}

// Adds a pokemon to the pokedex.
void Pokedex :: add(Pokemon* p)
{
  if (size() < 1000)
    A[p -> Ndex()] = p;
}

// Removes a pokemon from the pokedex.
void Pokedex :: remove(Pokemon* p)
{
  for (int i = 0; i < 1000; ++i)
  {
    if (A[i] != nullptr && (*A[i]).name() == (*p).name())
    {
      A[i] = nullptr;
      return;
    }
  }
}

// Returns a (pointer to a) pokemon in the pokedex with the given name.
// If none exists, returns nullptr.
//
// Hint: loop through all of A, searching for a Pokemon with
// the given name. Return the first one found.
Pokemon* Pokedex :: lookup_by_name(string name)
{
  for (int i = 0; i < 1000; ++i)
    if (A[i] != nullptr && A[i]->Pokemon::name() == name)
      return A[i];
  return nullptr;
}

// Returns a (pointer to a) pokemon in the pokedex with the given Ndex.
// If none exists, returns nullptr.
//
// Hint: look in A[ndex]. 
Pokemon* Pokedex :: lookup_by_Ndex(int ndex)
{
  for (int i = 0; i < 1000; ++i)
    if (A[i] != nullptr && A[i]->Pokemon::Ndex() == ndex)
      return A[i];
  return nullptr;

}

// Returns the number of pokemon in the pokedex.
int Pokedex :: size()
{
int s = 0;
   for (int i = 0; i < 1000; ++i)
     {
    if (A[i] != nullptr)
    {
      s++;
    }
      }
    return s;
}