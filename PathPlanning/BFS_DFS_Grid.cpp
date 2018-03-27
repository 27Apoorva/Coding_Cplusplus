#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#define row 9
#define col 10
class point
{
public:
  int x;
  int y;
};
class data_node
{
public:
  point pt;
  int new_dist;
};
// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
bool isValid(int r, int c)
{
    // return true if row number and column number
    // is in range
    return (r >= 0) && (r < row) &&
           (c >= 0) && (c < col);
}
int BFS(int mat[][col],point start, point end,int &distance)
{
  if (!mat[start.x][start.y] || !mat[end.x][end.y])
        return INT_MAX;
  std::vector<std::vector<bool> > visited(col, std::vector<bool>(row, false));
  visited[start.x][start.y] = true;
  std::queue<data_node> my_que;
  data_node my_node = {start,0};
  my_que.push(my_node);
  point my_temp = {0,0};
  while(my_que.empty() == false)
  {

    data_node current = my_que.front();
    point temp = current.pt;
    std::cout << "points: " <<temp.x <<' ' <<temp.y << '\n';
    if((temp.x == end.x) && (temp.y == end.y))
    {

      return current.new_dist;
    }
    my_que.pop();
    for(int i = 0; i<4 ;i++)
    {
      int r = temp.x + rowNum[i];
      int c = temp.y + colNum[i];
      if(isValid(r, c) && (mat[r][c]) &&(!visited[r][c]))
      {
        visited[r][c] = true;
        data_node temp_node = {{r,c},current.new_dist +1};
        my_que.push(temp_node);
        //distance +=1;
      //  std::cout << "dist: " <<distance << '\n';
      }
    }

  }

  return INT_MAX;

}
int DFS(int mat[][col],point start, point end,int &distance)
{
  if (!mat[start.x][start.y] || !mat[end.x][end.y])
      return INT_MAX;
  std::vector<std::vector<bool> > visited(col, std::vector<bool>(row, false));
  visited[start.x][start.y] = true;
  std::stack<data_node> my_stack;
  data_node my_node = {{start},0};
  my_stack.push(my_node);
  while(my_stack.empty() == false)
  {
    data_node current = my_stack.top();
    point temp = current.pt;
    std::cout << "points: " <<temp.x <<' ' <<temp.y << '\n';
    if((temp.x == end.x) && (temp.y == end.y))
    {

      return current.new_dist;
    }
    my_stack.pop();
    for(int i = 0; i<4 ;i++)
    {
      int r = temp.x + rowNum[i];
      int c = temp.y + colNum[i];
      if(isValid(r, c) && (mat[r][c]) &&(!visited[r][c]))
      {
        visited[r][c] = true;
        data_node temp_node = {{r,c},current.new_dist +1};
        my_stack.push(temp_node);
      }

    }
  }
  return INT_MAX;

}
int main()
{
  int mat[row][col] = {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };

  point src,dest;
  src.x = 0;
  src.y = 0;
  dest.x = 3,
  dest.y = 4;
  int distance = 0;
  std::cout << "BFS Shortest Distance: "<<BFS(mat,src,dest,distance) << std::endl;
//  std::cout << "DFS Shortest Distance: "<<DFS(mat,src,dest,distance) << std::endl;


}
