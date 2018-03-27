#include <iostream>
#include <string>
#include <vector>
bool is_unique(std::string s1)
{
  //std::vector<bool> checker(256,false);
  bool *checker = new bool[256];
  for(auto it = 0;it<s1.length();++it)
  {
    if(checker[s1.at(it)])
    {
      return false;
    }
    checker[s1.at(it)] = true;
  }
  return true;

}
int main()
{
  std::cout << "is_unique: " << is_unique("helo")<<'\n';
}
