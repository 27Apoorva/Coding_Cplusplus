#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex m;
std::vector<int> vec;
void push()
{
  m.lock();
  for (int i = 0; i<9; i++)
  {
    std::cout << "push" << i << std::endl;
    vec.push_back(i);
  }
  m.unlock();
}
void pop()
{
  m.lock();
  for (int i = 0; i<9; i++)
  {
    if (vec.size() > 0)
		{
			int val = vec.back();
			vec.pop_back();
			std::cout << "Pop " << val << std::endl;
		}
  }
  m.unlock();
}

int main()
{
  std::thread t1(push);
  std::thread t2(pop);
  if (t1.joinable())
  {
    t1.join();
  }
  if(t2.joinable())
  {
    t2.join();
  }
}
