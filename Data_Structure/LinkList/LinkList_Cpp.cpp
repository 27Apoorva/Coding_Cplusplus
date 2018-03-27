#include<iostream>
#include <ctime>
#include <chrono>

template <class T>
class Node
{
public:
  T data;
  Node *next;

/*  Node()
  {
    data = 0;
    next = NULL;
  }*/

};
template <class T>
class LinkList
{
private:
  Node<T> *head;
public:
  LinkList(T data=T())
  {
    head->data = data;
    head->next = NULL;
    std::cout << "constructor: " << head->data << '\n';
  }
  void add_node(T value)
  {
    Node<T> *new_node = new Node<T>;
    new_node->data = value;
    new_node->next = head;
    head = new_node;
  }
  void display()
  {
    Node<T> *temp1 = new Node<T>;
    temp1 = head;
    while(temp1!=NULL)
    {
      std::cout << "displaying LinkList: "<< temp1->data << '\n';
      temp1 = temp1->next;
    }
  }

  bool delete_node(T value)
  {
    Node <T> *temp = new Node<T>;
    temp = head;
    bool found = false;
    if(temp==NULL || temp->next == NULL)
    {
      return false;
    }
    while(temp->next!=NULL)
    {
      if(temp->data == value)
      {
        found = true;
        break;
      }
      temp = temp->next;
    }
    if(found)
    {
      Node <T> *next = new Node<T>;
      next = temp->next;
      temp->data = next->data;
      temp->next = next->next;
      return true;
    }
    else
    {
      return false;
    }

  }

};
int main()
{
  LinkList<int> l1(9);
  l1.add_node(8);
  l1.add_node(7);
  l1.add_node(6);
  l1.add_node(5);
  l1.add_node(2);
  l1.display();
  std::cout << "delete_node: " << l1.delete_node(2) <<'\n';
  std::cout << "delete_node: " << l1.delete_node(5) <<'\n';
  std::cout << "delete_node: " << l1.delete_node(6) <<'\n';
  std::cout << "delete_node: " << l1.delete_node(0) <<'\n';
  l1.display();
  return 0;
}
