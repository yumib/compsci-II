#include "sort.h"

//helper function that serves as preliminary check to see if the array is sorted as is:
bool check_sorted (int* A, int len)
{
// loop to go through entire array
for (int i = 1; i < len; i++) 
{
  if (A[i] < A[i - 1]) // if element is less than the number behind it, it is false
    return false; //returns false, saying that list is NOT sorted
} 
  return true; //returns true, saying that list is sorted
}

//merge sort algorithm:
void sort(int *A, int len)
{
if (check_sorted(A,len)) //if list is sorted, stop
  return;

// base case that returns if the array is only sorting less than 2 values
if (len < 2)
  return;

// mergesort left half, called recursively
//passes full array but len in half
sort(A, len / 2);

// mergesort right half, called recusively
//passes the right half of the array and subtracts the length of array minus the length halved 
sort(&(A[len / 2]), len - len / 2);

//merges array together to make it sorted
//works by creating an auxiliary array that will place compared values into the correct place
int i = 0; //at the beginning of the array (left-side)
int j = len / 2; //half of the length value (right-side)
int k = 0; //keeps track of index in the auxiliary array
int *aux_A = new int[len]; //creates auxiliary array, same length as A 
while (i < len / 2 && j < len) 
//while i is less than half (since i is left) and while j is less than length (since j is right)
//basically saying if both indexes are still in their respective areas (i.e. left and right)
{
  if (A[i] <= A[j]) //value at index i is less than or equal to value at index j
  {
      aux_A[k] = A[i]; //copies i into index k 
      i++; //moves i by 1 to the right
  } 
  else //value at index i is greater than value at index j
  {
    aux_A[k] = A[j]; //copies j into index k
    j++; //moves j by 1 to the right 
  }
    k++; //moves k by 1 to the right 
}
//both while loops copy the rest of the sub arrays into the auxiliary array after the initial sort and the variables are increased accordingly
while (i < len / 2) //left-side copy
{
  aux_A[k] = A[i];
  i++;
  k++;
}
while (j < len)  //right-side copy
{
  aux_A[k] = A[j];
  j++;
  k++;
}
  for (int i = 0; i < len; i++) //copies entirety of auxiliary array to the original array
    A[i] = aux_A[i];
  delete[] aux_A; //deletes auxiliary array
}

//Reasons why this algorithm is more efficient than benchmark_sort:
/*
  1) There is a preliminary function that checks if the list is already sorted or not
  2) The first while loop more effectively makes use of the variables and different cases. 
    - For example, benchmark_sort has a noticebly larger amount in if-else statements
  3) The merging of the array is done after sorting and is copied into the auxliary array (done within linear time)
    - As opposed to benchmark_sort, the merging is down WHILE sorting and create less efficient time usage   
*/