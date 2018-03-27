//Problem Statement:Given an expression string exp, examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
//For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”
#include <iostream>
#include <string>
#include <stack>

bool checker(std::string &str)
{
  std::stack<char> my_stack;
  bool flag = true;
  //std::cout << "str: " <<str[0]<< '\n';
  for (auto it = 0 ; it < str.size() ;it++)
  {
    if((str[it]=='[' )|| (str[it] == '{')|| (str[it] == '('))
    {
      my_stack.push(str.at(it));
    }
    else if((str[it]==']') || (str[it] == '}') || (str[it] == ')'))
    {
      if(!my_stack.empty())
      {
        char temp = my_stack.top();
        if((temp=='(' && str[it] == ')') || (temp=='[' && str[it] == ']') || (temp=='{' && str[it] == '}'))
        {
          my_stack.pop();
        }
        else
        {
          // std::cout << "not balanced" << '\n';
          // break;
          return false;
        }
      }
      else
      {
      //  my_stack.push(str.at(it));
        // std::cout << "not balanced" << '\n';
        //flag = false;
        return false;
      //  break;

      }


    }
  }
  if(my_stack.empty() && flag)
  {
  //  std::cout << "balanced" << '\n';
  return true;
  }
  else if(my_stack.empty() && flag)
  {
    // std::cout << "not balanced" << '\n';
    return false;
  }

}
int main()
{
  int T;
  std::cin >> T;
  std::string s[100];
  for (size_t i = 0; i < T; i++)
  {
    std::cin >> s[i];
    if(checker(s[i]))
    {
      std::cout << "balanced" << '\n';
    }
    else
    {
      std::cout << "not balanced" << '\n';
    }
  }

}
