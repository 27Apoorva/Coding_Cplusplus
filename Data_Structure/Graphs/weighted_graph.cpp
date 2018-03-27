#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
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
    std::pair<int,int> *temp = new std::pair<int,int>;
    temp->first = end;
    temp->second = weight;
    adjList[start].push_back(*temp);
  //  adjMat[start].push_back(end);
  //  adjMat[end].push_back(start);
  //  adjList[end].push_back(start); //UNCOMMENT FOR UNDIRECTED GRAPH
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
  g->printGraph();




}
