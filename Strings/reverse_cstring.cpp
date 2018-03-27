#include <iostream>
#include <cstring>
void reverse_cstring(char *str)
{
  std::cout << "reverse_cstring: "<< strlen(str)<< '\n';
  int size =  strlen(str);
  char *end = new char[size];
  int c = 0;
  for(int i = size ;i>0;i--)
  {
    end[i-1] = *(str+c);
    c++;
  }
  std::cout << "string: "<< end << '\n';

}
int main()
{
  char *test = "asdfghjkl";
  reverse_cstring(test);
}
