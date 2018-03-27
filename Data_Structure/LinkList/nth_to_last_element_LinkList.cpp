#include<iostream>
#include <ctime>
#include <chrono>

template <class T>
class Node
{
public:
  T data;
  Node *next;
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
  T nth_element_from_last(int n)
  {
    if(head == NULL || n<1)
    {
      return T();
    }
    Node<T> *temp1 = new Node<T>;
    Node<T> *temp2 = new Node<T>;
    temp1 = head;
    temp2 = head;
    for(int i = 0; i<n-1;i++)
    {
      if(temp2 == NULL)
      {
        return T();
      }
      temp2 = temp2->next;
    }
    while(temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1->data;


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
   //auto start = std::chrono::system_clock::now();

   //std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
   LinkList<int> l1;
   l1.add_node(8);
   l1.add_node(7);
   l1.add_node(6);
   l1.add_node(5);
   l1.add_node(2);
   l1.display();
   std::cout << "nth value: "<< l1.nth_element_from_last(2) << '\n';
   std::cout << "delete_node: " << l1.delete_node(2) <<'\n';
   std::cout << "delete_node: " << l1.delete_node(5) <<'\n';
   std::cout << "delete_node: " << l1.delete_node(6) <<'\n';
   std::cout << "delete_node: " << l1.delete_node(0) <<'\n';
   l1.display();
  // auto end = std::chrono::system_clock::now();
  // std::clock_t end = std::clock();
  // // std::chrono::duration<double> elapsed = start - end;
  // double elapsed = start - end;
  // // std::cout << "time: " << elapsed.count() << '\n';
  // std::cout << "time: " << elapsed/CLOCKS_PER_SEC << '\n';
  return 0;
}
