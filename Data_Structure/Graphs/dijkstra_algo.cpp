#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

class Graph
{
private:
  int Vertex;
  std::vector<std::list<std::pair<int,int> > > adjList; // vector of lists
//  std::vector<std::vector<int> > adjMat; //vector of vector
public:
  Graph(int const &V)
  {
    this->Vertex = V;
    adjList.resize(V);
  //  adjMat.resize(V);
  }
  void add_Edge(int const &start,int const &end,int const &weight)
  {
    // std::pair<int,int> *temp = new std::pair<int,int>;
    // temp->first = end;
    // temp->second = weight;
    adjList[start].push_back(std::make_pair(end,weight));
  //  adjMat[start].push_back(end);
  //  adjMat[end].push_back(start);
    adjList[end].push_back(std::make_pair(start,weight)); //UNCOMMENT FOR UNDIRECTED GRAPH
  }
  void printGraph()
  {
      //int v;
      //list<int>::iterator begin, end;

      for (auto st : this->adjList)
      {
        //  std::cout << "vector" << this->Vertex << '\n';
          for (auto i:st)
          {
              std::cout <<"printing graph: " << i.first << " " << i.second << '\n';
          }
      }
  }
  void dijkstra(int const &source)
  {
    int *distances = new int[Vertex];
    std::pair<int,int> current;
    for(int i = 0;i<Vertex;i++)
    {
      distances[i] = std::numeric_limits<int>::max();
    }
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int> >, std::greater<std::pair<int,int>> > my_que;  //https://www.geeksforgeeks.org/implement-min-heap-using-stl/
  //  std::queue<std::pair<int,int> > my_que;
    distances[source] = 0;
    my_que.push(std::make_pair(distances[source],source));
    while(my_que.empty() == false)
    {
      current = my_que.top();
      std::cout << "Dijkstra: " << current.first <<" " << current.second << '\n';
      int current_weight= current.first;
      int current_vertex = current.second;
      my_que.pop();
      for(std::list<std::pair<int, int> >::iterator it = adjList[current_vertex].begin();it != adjList[current_vertex].end();++it)
      {
      //  std::cout << "FOR : " << it->first <<" " << it->second << '\n';
        int adjacent_vertex = it->first;
        int adjacent_weight = it->second;
        if(distances[adjacent_vertex] > adjacent_weight + distances[current_vertex])
        {
          distances[adjacent_vertex] = adjacent_weight + distances[current_vertex];
          my_que.push(std::make_pair(distances[adjacent_vertex],adjacent_vertex));
        }
      }
    }
    for (int i = 0; i < Vertex; ++i)
    {
         std::cout << "Vertex: " <<i << " Distance: " << distances[i] << '\n';
    }
  }



};

int main()
{
  Graph *g = new Graph(9);
  g->add_Edge(0, 1, 4);
  g->add_Edge(0, 7, 8);
  g->add_Edge(1, 2, 8);
  g->add_Edge(1, 7, 11);
  g->add_Edge(2, 3, 7);
  g->add_Edge(2, 8, 2);
  g->add_Edge(2, 5, 4);
  g->add_Edge(3, 4, 9);
  g->add_Edge(3, 5, 14);
  g->add_Edge(4, 5, 10);
  g->add_Edge(5, 6, 2);
  g->add_Edge(6, 7, 1);
  g->add_Edge(6, 8, 6);
  g->add_Edge(7, 8, 7);
  g->dijkstra(0);
//  g->printGraph();




}
