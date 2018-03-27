#include <iostream>
#include <string>
void remove_duplicates(std::string &s1)
{
//  std::cout << "string: "<<s1 << '\n';
  if(s1.size() == 0)
  {
    return;
  }
  int temp = 1;
  int length = s1.size();
  if (length < 2)
  {
    return;
  }
  std::cout << "length of string: " << length << '\n';
  for(int i = 1 ;i<length;++i)
  {
    int j;
    for(j = 0;j<temp;++j)
    {
      if(s1[i]==s1[j])
      {

        std::cout << "temp: "<< temp <<' '<<i << ' '<< j<< '\n';
        break;
      }
    }
    if(j == temp)
    {
      s1[temp] = s1[i];
      ++temp;

    }
    else
    {
      s1[temp] = 0;
      ++temp;
    }

  }


}
int main()
{
  std::string *my_string = new std::string;
  *my_string = "ababa";
  remove_duplicates(*my_string);
  std::cout << "removed duplicates: " << *my_string << '\n';
}
