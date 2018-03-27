#include <iostream>
void tower_of_hanoi(int N, char startPeg,char auxPeg, char endPeg)
{
  if(N == 1)
  {
    std::cout << "Printitng: " << startPeg <<',' << endPeg << '\n';
  }
  else
  {
    tower_of_hanoi(N-1,startPeg,endPeg,auxPeg);
    tower_of_hanoi(1,startPeg,auxPeg,endPeg);
    tower_of_hanoi(N-1,auxPeg,startPeg,endPeg);
  }
}
int main()
{
  tower_of_hanoi(3,'A','B','C');
}
