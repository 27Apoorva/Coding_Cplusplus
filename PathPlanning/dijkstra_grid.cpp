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
int dijkstra(int mat[][col],point start, point end,int &distance)
{
  if (!mat[start.x][start.y] || !mat[end.x][end.y])
        return INT_MAX;
  std::vector<std::vector<bool> > visited(col, std::vector<bool>(row, false));
  visited[start.x][start.y] = true;
  std::priority_queue<std::pair<int,std::pair<int,int> >, std::vector<std::pair<int,std::pair<int,int>> >,std::greater<std::pair<int,std::pair<int,int>> >> my_que;

  my_que.push(std::make_pair(0,std::make_pair(start.x,start.y)));
  point my_temp = {0,0};
  while(my_que.empty() == false)
  {

    //data_node current = my_que.top().second;
    int dist = my_que.top().first;
    point temp = {my_que.top().second.first,my_que.top().second.second} ;
    std::cout << "points: " << temp.x <<' ' <<temp.y << '\n';
    if((temp.x == end.x) && (temp.y == end.y))
    {
      return dist;
    }
    my_que.pop();
    for(int i = 0; i<4 ;i++)
    {
      int r = temp.x + rowNum[i];
      int c = temp.y + colNum[i];
      if(isValid(r, c) && (mat[r][c]) &&(!visited[r][c]))
      {
        visited[r][c] = true;
        data_node temp_node = {{r,c},dist +1};
        my_que.push(std::make_pair(temp_node.new_dist,std::make_pair(temp_node.pt.x,temp_node.pt.y)));
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
  std::cout << "Dijkstra Shortest Distance: "<< dijkstra(mat,src,dest,distance) << std::endl;
//  std::cout << "DFS Shortest Distance: "<<DFS(mat,src,dest,distance) << std::endl;


}
