/*
 * =====================================================================================
 *
 *       Filename:  7.cpp
 *
 *    Description:  problem 1.7
 *                  M x N 행렬의 한 원소가 0일 경우, 해당 원소가 속한 행과 열의 모든 원소를 0으로
 *                  설정하는 알고리즘을 작성하라.
 *
 *        Version:  1.0
 *        Created:  08/21/15 18:10:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heesik Shin (star114), star114.shin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>

// for Debugging
template <typename T>
void print_array(T** array, int row_size, int column_size)
{
  for(int i =0 ; i < row_size ; i++)
  {
    for (int j= 0; j < column_size; j++)
    {
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void setZeros(int ** matrix, int M, int N)
{
  bool* row = new bool[M];
  bool* col = new bool[N];
  for (int i = 0 ; i < M; i ++)
  {
    for (int j = 0 ; j < N; j++)
    {
      if (matrix[i][j] == 0)
      {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  for (int i =0 ; i < M; i++)
  {
    for (int j = 0 ; j < N; j++)
    {
      if (row[i] || col[j]) matrix[i][j] = 0;
    }
  }
  if (NULL != row) delete[] row;
  if (NULL != col) delete[] col;
}

int main(int argc, const char *argv[])
{
  int* test[5];
  for (int i = 0 ; i < 5; i ++)
  {
    test[i] = new int[5];
    for (int j = 0 ; j < 5 ; j++)
      test[i][j] = (i+1)*(j+1);
  }
  //set zero for testing.
  test[0][0] = 0;
  test[3][2] = 0; 

  print_array<int>(test, 5,5);
  setZeros(test, 5,5);
  print_array<int>(test, 5,5);
  return 0;
}

