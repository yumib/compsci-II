#include "hack.h"
#include <iostream>
#include <string>

// function definitions:
void hack_Dave(EvilComputer *ec, string password);
void hack_MrMean(EvilComputer *ec, string password, int length);
void hack_MsChief(EvilComputer *ec, string password, int length);
void hack_DrEvil(EvilComputer *ec, string password, int length);

// main function call:
void hack(EvilComputer *ec) {
  string combination;
  int length;

  ec->guess("Guest", "passw123"); // Guest account

  combination = "";
  hack_Dave(ec, combination); // guesses Dave, length will always be 4- as per assignment

  // loop that checks through every length of possibilities, checks length 0
  // passowrd first
  length = 0;
  while (ec->is_hacked("Mr. Mean") == false) {
    combination = "";
    hack_MrMean(ec, combination, length); // passes different length size each time
    ++length;
  }

  // starts with length 4 because "haha" is a given
  length = 4;
  while (ec->is_hacked("Ms. Chief") == false) {
    combination = "haha";
    hack_MsChief(ec, combination, length);
    ++length;
  }

  // loop that checks through every length of possibilities, checks length 0
  // passowrd first
  length = 0;
  while (ec->is_hacked("Dr. Evil") == false) {
    combination = "";
    hack_DrEvil(ec, combination, length);
    ++length;
  }
}

void hack_Dave(EvilComputer *ec, string password) {
  if (password.length() == 4) // base case
  {
    ec->guess("Dave", password); // guesses
    return;
  }
  // creates recursive call to go through all possibilities
  for (char i = '0'; i < ':'; ++i) //goes 0-9
    hack_Dave(ec, password + i);
}

void hack_MrMean(EvilComputer *ec, string password, int length) {
  if (password.length() == length) // base case
  {
    ec->guess("Mr. Mean", password); // guesses
    return;
  }
  // only two possible char in password
  hack_MrMean(ec, password + 'g', length);
  hack_MrMean(ec, password + 'r', length);
}

void hack_MsChief(EvilComputer *ec, string password, int length) {
  if (password.length() == length) // base case
  {
    ec->guess("Ms. Chief", password);
    return;
  }

  // checks if hacked then will execute recursive calls
  if (ec->is_hacked("Ms. Chief") == false) {
    for (char i = '0'; i < ':'; ++i) // goes 0-9
      hack_MsChief(ec, password + i, length);

    for (char j = 'a'; j < '{'; ++j) // goes a-z
      hack_MsChief(ec, password + j, length);
  }
}

void hack_DrEvil(EvilComputer *ec, string password, int length) {

  if (password.length() == length) // base case
  {
    string password2 = password;      // copies string
    password = "gato" + password;     // gato...
    password2 = password2 + "gato";   //...gato
    ec->guess("Dr. Evil", password);  // guesses with gato at the front
    ec->guess("Dr. Evil", password2); // guesses with gato at the end
    return;
  }

  if (ec->is_hacked("Dr. Evil") == false) {
    for (char i = '0'; i < ':'; ++i) // goes 0-9
    {
      hack_DrEvil(ec, password + i, length);
    }

    for (char j = 'a'; j < '{'; ++j) // goes a-z
    {
      hack_DrEvil(ec, password + j, length);
    }
  }
}