#include<iostream>
template<class T>
class Node
{
public:
  T data;
  Node<T> *next;
};
template<class T>
class queues
{
private:
  Node<T> *front;
  Node<T> *rear;
public:
  queues()
  {
    front = NULL;
    rear  = NULL;
    std::cout << "constructor: " << '\n';
  }
  inline bool isEmpty( ) const
  {
    return front == NULL;
  }

  void enqueue(T value)
  {
    Node<T> *new_Node = new Node<T>;
    new_Node->data = value;
    new_Node->next = NULL;
    if(isEmpty())
    {
      front = new_Node;
      rear = front;
    }
    else
    {
      rear->next = new_Node;
      rear = rear->next;
    }

  }
  T dequeue()
  {
    Node<T> *temp = new Node<T>;
    temp = front;
    T dequeueed;
    if(!isEmpty())
    {
      dequeueed = temp->data;
      front = front->next;
      delete temp;

    }


    return dequeueed;
  }

  void display()
  {
    Node<T> *temp = new Node<T>;
    temp = front;
    while(temp!=NULL)
    {
      std::cout << "displaying queues: "<< temp->data << '\n';
      temp = temp->next;
    }
  }

};
int main()
{
  queues<int> q1;
  q1.enqueue(111);
  q1.enqueue(11);
  q1.enqueue(1);
  q1.display();
  std::cout << "dequeue : "<< q1.dequeue() << '\n';
  q1.display();
  std::cout << "dequeue : "<< q1.dequeue() << '\n';
  q1.display();
  return 0;
}
