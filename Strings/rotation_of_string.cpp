#include <iostream>
#include <string>
bool isRotation(std::string s1,std::string s2)
{
  if(s1.size() != s2.size())
  {
    return false;
  }
  std::string new_string = s1+s1;
  for(int i = 0;i<new_string.size();i++)
  {
    //std::cout << "checks: " <<new_string.substr(i,s2.size())<< '\n';
    if(new_string.substr(i,s2.size()) == s2)
    {
      return true;
    }

  }
  return false;

}
int main()
{
  std::string my_string1,my_string2;
  my_string1 = "waterbottle";
  my_string2 = "erbottlewat";
  std::cout << "isRotation: "<< isRotation(my_string1,my_string2) << '\n';
}
