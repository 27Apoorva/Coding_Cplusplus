#include <iostream>

void swap(int &a,int &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}
void bubble_sort(int array[],int const size)
{
//  int size = sizeof(array)/sizeof(array[0]);
  for(int i = 0 ;i<size;i++)
  {
    for(int j = 0; j<size-1;j++)
    {
      if(array[j]>array[j+1])
      {
        swap(array[j],array[j+1]);
      }
    }
  }
}
void selection_sort(int array[],int size)
{
  int min_id;
  for(int i = 0 ;i<size-1;i++)
  {
    min_id = i;
    for(int j = i+1; j<size;j++)
    {
      if(array[min_id] > array[j])
      {
        min_id = j;
      }
    }
    swap(array[min_id], array[i]);
  }
}
void insertion_sort(int array[],int size)
{
  for(int i = 0 ;i<size-1;i++)
  {
    int temp = array[i];
    int j = i;
    while(j>0 && temp<array[j-1])
    {
      array[j] = array[j-1];
      j--;
    }
    array[j] = temp;

  }
}
int main()
{
  int arr[6] = {5,8,3,1,0,9};
  int size = *(&arr + 1) - arr;
/*  bubble_sort(arr,size);
  for(int i = 0 ;i<size;i++)
  {
    std::cout << "bubble_sort: " << arr[i]<< '\n';
  }
*/
/*  selection_sort(arr,size);
  for(int i = 0 ;i<size;i++)
  {
    std::cout << "selection_sort: " << arr[i]<< '\n';
  }
*/
  insertion_sort(arr,size);
  for(int i = 0 ;i<size;i++)
  {
    std::cout << "insertion_sort: " << arr[i]<< '\n';
  }
}
