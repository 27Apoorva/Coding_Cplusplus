#include <iostream>
#include <future>
#include <thread>

void initializer(std::promise<int>* p_obj)
{
  std::cout<<"initializer"<<std::endl;
  p_obj->set_value(10);

}

int main()
{
  std::promise<int> promise_obj;
  std::future<int> future_obj = promise_obj.get_future();
  std::thread th1(initializer,&promise_obj);
  th1.join();
  int val = future_obj.get();
  std::cout<< val <<std::endl;

}
