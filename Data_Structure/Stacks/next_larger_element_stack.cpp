#include <iostream>
#include <stack>
void next_larger(int A[],int &size)
{
  std::stack<int> my_stack;
  // int j = 1;
  // bool flag = false;
  // int count = 0;
  my_stack.push(A[0]);
  for(auto i = 1;i< size;i++)
  {
    //my_stack.push(A[i]);
    int next = A[i];
    if(my_stack.empty() == false)
    {
      int element = my_stack.top();
      my_stack.pop();
      while(element < next)
      {
        std::cout << element<<"greater: " << next << '\n';
        if (my_stack.empty() == true)
            break;
        element = my_stack.top();
        my_stack.pop();
      }
      if (element > next)
      {
        my_stack.push(element);
      }
    }
    my_stack.push(next);
  }
  while (my_stack.empty() == false)
  {
    std::cout << -1 << std::endl;
    my_stack.pop();
  }
}

int main()
{
  int T;
  std::cout << "Number of Test Cases: " << std::endl;
  std::cin >> T;
  int N[T];
  int A[1000];
  for(auto i = 1; i<=T; i++)
  {
    std::cout << "size of array: " << i << std::endl;
    std::cin >> N[i];
    for(auto j = 0; j<N[i]; j++)
    {
      std::cout << "enter elements of array: " << std::endl;
      std::cin >> A[j];
    }
    next_larger(A,N[i]);

  }
}
