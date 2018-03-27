#include "astar_wiki.h"
const bool operator < (const point &n1, const point &n2)
{
  return n1.f > n2.f;
}

const bool operator == (const point &n1, const point &n2)
{
  return n1.x == n2.x && n1.y == n2.y;
}

bool isValid(const int &r, const int &c)
{
  // return true if row number and column number is in range
  return (r >= 0) && (r < row) && (c >= 0) && (c < col);
}

double H_value(const int &r, const int &c, const point &pt)
{
  return (static_cast<double>(sqrt(r-pt.x)*(r-pt.x) + (c-pt.y)*(c-pt.y)));
}

bool second_half(const int &k,const int &m)
{
  if((k == 1 && m == 1) ||(k == -1 && m == -1) || (k == 1 && m == -1) || (k == -1 && m == 1))
    return true;
  else
    return false;
}

int astar(int mat[][col],const point &start, const point &end)
{
  if (!mat[start.x][start.y] || !mat[end.x][end.y])
        return INT_MAX;

  std::shared_ptr<std::vector<bool>> temp_vec = std::make_shared<std::vector<bool>>(row,false);
  std::vector<std::vector<bool>> closedSet(col, *temp_vec);
  closedSet[start.x][start.y] = true;
  point cameFrom[row][col];
  for (int i=0; i<row; i++)
  {
      for (int j=0; j<col; j++)
      {
          cameFrom[i][j].f = FLT_MAX;
          cameFrom[i][j].g = FLT_MAX;
          cameFrom[i][j].h = FLT_MAX;
          cameFrom[i][j].x = -1;
          cameFrom[i][j].y = -1;
      }
  }

  // Initialising the parameters of the starting node
  cameFrom[start.x][start.y].f = 0.0;
  cameFrom[start.x][start.y].g = 0.0;
  cameFrom[start.x][start.y].h = 0.0;
  cameFrom[start.x][start.y].x = start.x;
  cameFrom[start.x][start.y].y = start.y;

  std::priority_queue<MyPair, std::vector<MyPair>,std::greater<MyPair> > my_que;
  my_que.push(std::make_pair(0.0,start));

  while(my_que.empty() == false)
  {
    double gNew, hNew, fNew;
    point temp = my_que.top().second;
    //std::cout << "points: " << temp.x <<' ' <<temp.y << '\n';
    if((temp.x == end.x) && (temp.y == end.y))
    {
      std::cout << "FOUND PATH: " << '\n';
      int r = end.x;
      int c = end.y;
      int dist = 0;
      std::cout << "goal: " << r <<' ' <<c << '\n';
      std::stack<std::pair<int,int> > Path;

      while (!(cameFrom[r][c].x == r && cameFrom[r][c].y == c))
      {
          Path.push(std::make_pair (r, c));
          int temp_row = cameFrom[r][c].x;
          int temp_col = cameFrom[r][c].y;
          r = temp_row;
          c = temp_col;
          dist++;
      }

      Path.push (std::make_pair (r, c));
      while (!Path.empty())
      {
          std::pair<int,int> p = Path.top();
          Path.pop();
          std::cout  << p.first << ", " << p.second<< '\n';
      }

      return dist;
    }
    closedSet[temp.x][temp.y] = true;
    my_que.pop();
    for(size_t i = 0; i < 8 ; i++)
    {
      int r = temp.x  + rowNum[i];
      int c = temp.y + colNum[i];

      if(isValid(r, c) && (mat[r][c]) &&(!closedSet[r][c]))
      {
        //std::cout << "r: " << r <<" c: " << c << '\n';
        if(second_half(rowNum[i],colNum[i]))
        {
          gNew = cameFrom[temp.x][temp.y].g + 1.414;
        }
        else
        {
          gNew = cameFrom[temp.x][temp.y].g + 1.0;
        }

        hNew = H_value(r, c, end);
        fNew = gNew + hNew;

        if (cameFrom[r][c].f == FLT_MAX || cameFrom[r][c].f > fNew)
        {

          //closedSet[r][c] = true;
          //point my_temp = {r,c,fNew,gNew,hNew}; // should I use pointer here?
          //std::cout << "my_temp: " << my_temp.x <<' ' <<my_temp.y << '\n';
          my_que.push(std::make_pair(fNew,point({r,c,fNew,gNew,hNew})));
          cameFrom[r][c].f = fNew;
          cameFrom[r][c].g = gNew;
          cameFrom[r][c].h = hNew;
          cameFrom[r][c].x = temp.x;
          cameFrom[r][c].y = temp.y;
        }
      }
     }
  }
  return INT_MAX;
}

int main()
{
  int mat[row][col] = {
          { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
          { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
          { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
          { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
          { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
          { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
          { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
          { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
          { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
  };

  point src,dest;
  src = {8,0,0.0,0.0,0.0};
  dest = {0,0,0.0,0.0,0.0};
  std::cout << "Astar Shortest Distance: "<< astar(mat, src, dest) << std::endl;


}
