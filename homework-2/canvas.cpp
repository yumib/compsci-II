#include "canvas.h"
#include <iostream>
using namespace std;
	// Allocates a canvas of the given width and height 5 that
		// consists entirely of ' ' (space) chars. If the width is 0,
		// the canvas is empty (pointer is NULL and _width is 0)
Canvas::Canvas(int width)
{
  if (width == 0)
  {
      C = NULL;
      _width = 0;
  }
  else  //creation of dynamic structure/canvas
  {
    _width = width;
    C = new char*[width];
    for (int i = 0; i < width; ++i)    
    { 
      C[i] = new char[5];
      for (int j = 0; j < 5; ++j)
        C[i][j] = ' ';
    }
  } 
}


	// Allocates a canvas with width 5 and height 5 that looks like:
		//
		//  ###       ####        ####     ####
		// #   #      #   #      #         #   #
		// #####  or  ####   or  #      or #   #
		// #   #      #   #      #         #   #
		// #   #      ####        ####     ####
		//
		// depending upon which character ('A', 'B', 'C', or 'D') is 
		// given as a parameter. If some other character is given, 
		// allocates a canvas of ' ' chars with width 5 and height 5.
Canvas::Canvas(char x)
{
  _width = 5;
  C = new char*[5];  //creation of 5x5 canvas
  for (int i = 0; i < 5; ++i)
    { 
      C[i] = new char[5];
      for (int j = 0; j < 5; ++j)
        C[i][j] = ' ';
    }
  
  
  if (x == 'A')  //Character A in canvas
  {
    for (int i = 0; i == 0; ++i)
      {
        for (int j = 1; j < 5; ++j)
          C[i][j] = '#';
          
      }
    for (int i = 1; i < 4; ++i)
      {
        for (int j = 0; j == 0; ++j)
          C[i][j] = '#';
      }
    for (int i = 1; i < 4; ++i)
      {
        for (int j = 2; j == 2; ++j)
          C[i][j] = '#';
      }
    for (int i = 4; i == 4; ++i)
      {
        for (int j = 1; j < 5; ++j)
          C[i][j] = '#';        
      }
    
  }
    
  else if (x == 'B')  //Character B in canvas
  {
    for (int i = 0; i == 0; ++i)
      {
        for(int j = 0; j < 5; ++ j)
          C[i][j] = '#';
      }
    for (int i = 1; i < 4; ++ i)
      {
        for (int j = 0; j == 0; ++j)
          C[i][j] = '#';
      }
    for (int i = 1; i < 4; ++ i)
      {
        for (int j = 2; j == 2; ++j)
          C[i][j] = '#';
      }
    for (int i = 1; i < 4; ++ i)
      {
        for (int j = 4; j == 4; ++j)
          C[i][j] = '#';
      }
    for (int i = 4; i == 4; ++i)
      {
        for (int j = 1; j == 1; ++j)
          C[i][j] = '#';
      }
    for (int i = 4; i == 4; ++i)
      {
        for (int j = 3; j == 3; ++j)
          C[i][j] = '#';
      }
  }
    
  else if (x == 'C')  //Character C in canvas
  {
    for (int i = 0; i == 0; ++i)
      {
        for(int j = 1; j < 4; ++ j)
          C[i][j] = '#';
      }
    for (int i = 1; i < 5; ++ i)
      {
        for (int j = 0; j == 0 || j == 4; ++j)
          C[i][j] = '#';
      }
    for (int i = 1; i < 5; ++ i)
      {
        for (int j = 4; j == 4; ++j)
          C[i][j] = '#';
      }
    
  }
  else if (x == 'D')  //Character D in canvas
  {
    for (int i = 0; i == 0; ++i)
      {
        for(int j = 0; j < 5; ++ j)
          C[i][j] = '#';
      }
    for (int i = 1; i < 4; ++ i)
      {
        for (int j = 0; j == 0; ++j)
          C[i][j] = '#';
      }
     for (int i = 1; i < 4; ++ i)
      {
        for (int j = 4; j == 4; ++j)
          C[i][j] = '#';
      }
     for (int i = 4; i == 4; ++i)
      {
        for(int j = 1; j < 4; ++ j)
          C[i][j] = '#';
      }
  
    }
  else  //Creates blank canvas if x is some other character
  {
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; ++j)
        C[i][j] = ' ';
  }
}



		// Returns the width of the canvas.
int Canvas::width()
{
   return _width; 
}

		// Returns the entire canvas as a single string, consisting of each row
		// of the canvas, followed by the newline character ('\n').
		// If the canvas is empty, returns an empty string.
string Canvas::to_string()
{
  string s = "";
if (_width == 0)  //empty canvas returns empty string
  {return s;}
            
  for (int j = 0; j < 5; ++j)  //returns specified string
    {
      for (int i = 0; i < _width; ++i )
        { 
          s = s + C[i][j];
        }
      s = s + "\n";
     
    }
  return s;
}
		
		// Replaces every instance in the canvas of old_char with new_char.
		// For instance, if old_char is '#' and new char is '@', then: 
		// 
		//  ###             @@@
		// #   #           @   @
		// #####  becomes  @@@@@ 
		// #   #           @   @
		// #   #           @   @
		//
void Canvas::replace(char old_char, char new_char)
{
  //checks places of old char and replaces with new char
  for (int i = 0; i < _width; ++i)  
    {
      for (int j = 0; j < 5; ++j)
        {
         if (C[i][j] == old_char) 
         {
            C[i][j] = new_char;
          }
        }
    }   
}



		// Destructor. Deallocates all of the memory allocated by the canvas.
Canvas::~Canvas()
{
  //destroys memory made from dynamic variables
  for (int i = 0; i < _width; ++i)
    {
      delete[] C[i];
    }
  delete[] C;
  C = NULL;
}