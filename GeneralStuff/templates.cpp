#include<iostream>
//Function template
template<class T>
T template_function_add(T num1,T num2)
{
  T result;
  result = num1 + num2;
  std::cout << "double of num: " << result<< std::endl;
  return T(result);
}
template<typename T>
double average(T *arr,int size)
{
  T Tsum = T(); //Tsum is initialized as zero
  //std::cout << "Tsum: " <<Tsum<< '\n';
  for(int i = 0; i<size; i++)
  {
    Tsum +=arr[i];
  }
  return double(Tsum)/size;
}
template<typename T>
void double_it( T &var)
{
  var = 2*var;
// std::cout << "inside double_it: " <<var<< '\n';
}
template<class T1,class T2>
void template_function_add_different_types(T1 num1,T2 num2)
{

  std::cout << "double of num different types: " << num1 + num2 << std::endl;

}
template<class T>
T max(T t1, T t2)
{
   if (t1 > t2)
      return t1;
   return t2;
}
template<class T>
T SumOfNumbers(int a, int b)
{
   T t = T(); // Call default CTOR for T
   std::cout << "in Function: "<< T(a) << '\n';
   t = T(a)+b;
   return t;
}

int main()
{
  int x = 10;
  template_function_add(10,1);
  float floatarr[5] = {1.0,2.4,3.4,4.4,5.0};
  std::cout << "Average: "   << average(floatarr,5) << std::endl;
  std::cout << "template: "  << template_function_add(3.33,9.0) <<std::endl;
  double_it(x);
  std::cout << "double_it: " << x << std::endl;
  template_function_add_different_types(10,2.22222);
  std::cout << "max: " << max<double>(10,12.5)<< '\n';//explicit template argument specification
  std::cout << "SumOfNumbers: " <<SumOfNumbers<double>(10,20)<< '\n';
}
