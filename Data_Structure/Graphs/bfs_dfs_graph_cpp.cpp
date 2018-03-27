#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
class Graph
{
private:
  int Vertex;
  std::vector<std::list<int> > adjList; // vector of lists
//  std::vector<std::vector<int> > adjMat; //vector of vector
public:
  Graph(int const &V)
  {
    this->Vertex = V;
    adjList.resize(V);
  //  adjMat.resize(V);
  }
  void add_Edge(int const &start,int const &end)
  {
    adjList[start].push_back(end);
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
          std::cout << "vector" << this->Vertex << '\n';
          for (auto i:st)
          {
              std::cout << "printing graph: " << i << '\n';
          }
      }
  }
  void BFS_usingQueue(int const &start)
  {
    bool *visitied = new bool[Vertex];
    int current;
    for(int i = 0;i<Vertex;i++)
    {
      visitied[i] = false;
    }
    std::queue<int> my_que;
    visitied[start] = true;
    my_que.push(start);
    while(my_que.empty() == false)
    {
      current = my_que.front();
      std::cout << "BFS: "<< current << '\n';
      my_que.pop();
      for(std::list<int>::iterator it = adjList[current].begin();it != adjList[current].end();++it)
      {
        if(visitied[*it]==false)
        {
          my_que.push(*it);
          visitied[*it] = true;
        }
      }
    }
  }
  void DFS_usingStack(int const &start)
  {
    bool *visitied = new bool [Vertex];
    int current;
    for(int i = 0;i<Vertex;i++)
    {
      visitied[i] = false;
    }
    std::stack<int> my_stack;
    my_stack.push(start);

    while(my_stack.empty() ==false)
    {
      current = my_stack.top();
      my_stack.pop();
      if(!visitied[current])
      {
        std::cout << "DFS: "<< current << '\n';
        visitied[current] = true;
      }
      for(std::list<int>::iterator it = adjList[current].begin();it != adjList[current].end();++it)
      {
        if(!visitied[*it])
        {
          my_stack.push(*it);
          //visitied[*it] = true;
        }

      }
    }

  }


};

int main()
{
  Graph *g1 = new Graph(5);
  g1->add_Edge(0,1);
  g1->add_Edge(0,4);
  g1->add_Edge(1,3);
  g1->add_Edge(1,2);
  g1->add_Edge(1,4);
  g1->add_Edge(2,3);
  g1->add_Edge(3,4);
  g1->printGraph();
  g1->BFS_usingQueue(0);
  g1->DFS_usingStack(0);



}
