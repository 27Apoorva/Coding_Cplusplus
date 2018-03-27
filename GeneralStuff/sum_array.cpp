// Problem Statement : Given an unsorted array of non-negative integers, find a continuous sub-array which adds to a given number.
#include <iostream>
#include <climits>
#include <ctime>
#include <chrono>

void sum_array(int arr[],int size,int &sum)
{
  int temp = 0;
  int start_pos = 1, end_pos = 1;
  bool found = false;
  while(size>0)
  {
    temp = temp + arr[end_pos];
    if(temp < sum)
    {
      end_pos++;
    }
    else if(temp > sum)
    {
      size--;
      start_pos++;
      end_pos = start_pos;
      temp = 0;
    }
    else if(temp == sum)
    {
      std::cout << "start_pos: " << start_pos << '\n';
      std::cout << "end_pos: "   << end_pos << '\n';
      found = true;
      break;
    }
  }
  if(size==0 && found==false)
  {
    std::cout << "size: " << -1 << '\n';
  }

}
int main()
{
//  auto start = std::chrono::high_resolution_clock::now();
  int T;
  std::cout << "Number of Test Cases: " << std::endl;
  std::cin >> T;
  int N[T];
  int sum[T];
  int A[1000];
  for(auto i = 1; i<=T; i++)
  {
    std::cout << "size of array: " << i << std::endl;
    std::cin >> N[i];
    std::cout << "sum to be found: " << i << std::endl;
    std::cin >> sum[i];
    for(auto j = 1; j<=N[i]; j++)
    {
      std::cout << "enter elements of array: " << std::endl;
      std::cin >> A[j];
    }
    sum_array(A,N[i],sum[i]);

  }
//  auto end = std::chrono::high_resolution_clock::now();
 // std::chrono::duration<double> elapsed = start - end;
 // std::cout << "time: " << elapsed.count() << '\n';

}
