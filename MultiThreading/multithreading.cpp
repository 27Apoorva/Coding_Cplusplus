#include <iostream>
#include <thread>
class myFunctor
{
public:
  //Initialize thread with object of a class by operator overoading
  void operator () ()
  {
    std::cout << "this is my functor" << '\n';
  }
  void publicFunction()
  {
	   std::cout << "public function of myFunctor class is called" << std::endl;
   }
   void changeSign(int* arr, int length)
  {
  	std::cout << "An arrray of length " << length << "is passed to thread" << std::endl;
  	for (int i = 0; i != length; ++i)
  		std::cout << arr[i] << " ";
  	std::cout << "Changing sign of all elements of initial array" << std::endl;
  	for (int i = 0; i != length; ++i)
  	{
  		arr[i] *= -1;
  		std::cout << arr[i] << " ";
  	}
}
};
void printSomeValues(int val, char* str, double dval)
{
	std::cout << val << " " << str <<" " << dval << std::endl;

}
void threadfunc()
{
  std::cout <<"multithreading" <<std::endl;
}

int main()
{
  char *stri = "hello";
  int arr[3] = {1,2,3};
  myFunctor functor;
  //std::thread mythread(functor); //Initialize thread with object of a class by operator overoading
//  std::thread mythread(&myFunctor::publicFunction,functor); //Initialize thread with member function of class
  //std::thread mythread(printSomeValues,5,stri,3.4); //Initialize using function with arguments (passing arguments to thread)
  std::thread mythread(&myFunctor::changeSign,&functor,arr,3);
  //std::thread mythread(threadfunc);
  //mythread.detach();
  if (mythread.joinable())
  {
    std::cout << "the thread is joinable \n" << std::endl;
    mythread.join();
  }
  else
  {
    std::cout << "the thread is NOT joinable \n" << std::endl;
  }
}
