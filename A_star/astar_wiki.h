#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <math.h>
#include <float.h>
#include <memory>
#define row 9
#define col 10

class point;
typedef std::pair<int,point> MyPair;

int rowNum[] = {-1, 0, 0, 1, 1, -1, 1 , -1};
int colNum[] = {0, -1, 1, 0, 1, -1, -1, 1 };

class point
{
public:
  int x;
  int y;
  double f, g, h;
};
const bool operator < (const point &n1, const point &n2);
const bool operator == (const point &n1, const point &n2);
bool isValid(const int &r, const int &c);
double H_value(const int &r, const int &c, const point &pt);
bool second_half(const int &k,const int &m);
int astar(int mat[][col],const point &start, const point &end);
