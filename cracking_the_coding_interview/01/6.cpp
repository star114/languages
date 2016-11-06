/*
 * =====================================================================================
 *
 *       Filename:  6.cpp
 *
 *    Description:  problem 1.6
 *                  이미지를 표현하는 N x N 행렬이 있다. 이미지의 각 픽셀은 4바이트로 표현된다.
 *                  이때, 이미지를 90도 회전시키는 메서드를 작성하라. 부가적인 행렬을 사용하지
 *                  않고서도 할 수 있겠는가?
 *
 *        Version:  1.0
 *        Created:  08/21/15 18:05:46
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

void print_image(int**, int);
void rotate_image(int** image, int n)
{
  for (int layer = 0 ; layer < n/2 ; layer ++)
  {
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first ; i < last ; i++)
    {
      int index = (i - first);
      int temp = image[first][i];
      image[first][i] = image[last-index][first];
      image[last-index][first] = image[last][last-index];
      image[last][last-index] = image[i][last];
      image[i][last] = temp;
    }
  }
}

// for Debugging
void print_image(int** image, int n)
{
  for(int i =0 ; i < n ; i++)
  {
    for (int j= 0; j < n; j++)
    {
      std::cout << image[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// Tests
int main(int argc, const char *argv[])
{
  int n = 0;
  int* image[5];
  for (int i = 0 ; i < 5 ; i ++)
  {
    image[i] = new int[5];
    for (int j = 0 ; j < 5 ; j++)
      image[i][j] = n++;
  }

  std::cout << "Before processing >> " << std::endl;
  print_image(image, 5);
  std::cout << "Calling rotate_image >> " << std::endl;
  std::cout << std::endl;
  rotate_image(image, 5);
  std::cout << "After processing >> " << std::endl;
  print_image(image, 5);
  
  for (int i = 0; i < 5 ; i ++)
  {
    if (image[i] != NULL) delete[] image[i];
  }
  
  return 0;
}
