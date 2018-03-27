//problem: http://www.techiedelight.com/find-shortest-safe-route-field-sensors-present/
#include <iostream>
#include <queue>
#define M 10
#define N 10

struct point
{
  int x;
  int y;
  int dist;
};

bool isValid(int r, int c)
{
    // return true if row number and column number
    // is in range
    return (r >= 0) && (r < M) &&
           (c >= 0) && (c < N);
}
int rowNum[] = {-1,0,1,0};
int colNum[] = {0,-1,0,1};
int rowNum_new[] = {-1,0,1,0,-1,1};
int colNum_new[] = {0,-1,0,1,-1,1};

bool is_new_Valid(int a,int matrix[][N],int b = 0)
{
  bool flag = false;
  for(auto i = 0 ;i<6 ;i++)
  {
    int x = a + rowNum_new[i];
    int y = b + colNum_new[i];
    if(isValid(x,y) && matrix[x][y]==0)
    {
      flag = true;
      break;
    }
  }
  if(flag)
  {
    return false;
  }
  else
  {
    return true;
  }
}
bool safe(int a,int matrix[][N],bool visited[M][N],int b = 0)
{
  bool flag = false;
  for(auto i = 0 ;i<6 ;i++)
  {
    int x = a + rowNum_new[i];
    int y = b + colNum_new[i];
    if(isValid(x,y) && matrix[x][y]==0 && !visited[x][y])
    {
      flag = true;
      break;
    }
  }
  if(flag)
  {
    return false;
  }
  else
  {
    return true;
  }
}

int BFS_usingQueue(int matrix[][N])
{
  point start,goal;
  for(auto i = 0;i<M;i++)
  {
    if(matrix[i][0]!=0)
    {
      if(is_new_Valid(i,matrix,0))
      {
        start = {0,i,0};
        break;
      }
    }
  }
  for(auto i = 0;i<M;i++)
  {
    if(matrix[i][9]!=0)
    {
      if(is_new_Valid(i,matrix,0))
      {
        goal = {i,N-1,0};
        break;
      }
    }

  }
  std::cout << "start: " << start.x << " " <<start.y << '\n';
  std::cout << "goal: " << goal.x << " " <<goal.y << '\n';
  if (!matrix[start.x][start.y] || !matrix[goal.x][goal.y])
        return INT_MAX;
  bool visitied[M][N];
  memset(visitied,false,sizeof visitied);
  std::queue<point> my_que;
  my_que.push(start);
  visitied[start.x][start.y] = true;
  while(my_que.empty() == false)
  {
    point first = my_que.front();
    my_que.pop();
  //  std::cout << "first: " << first.x << " " <<first.y << '\n';
    if(first.x == goal.x && first.y == goal.y)
    {
      std::cout << "Distance: " << first.dist << '\n';
      return first.dist;
      break;
    }
    for(auto i = 0 ;i<4 ;i++)
    {
      int x = first.x + rowNum[i];
      int y = first.y + colNum[i];
      if(safe(x,matrix,visitied,y))
      {
        visitied[x][y] = true;
        point temp = {x,y,first.dist + 1};
        my_que.push(temp);
      }

    }

  }
    return INT_MAX;

}


int main()
{
  int mat[M][N] = {
		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};


  BFS_usingQueue(mat);

}
