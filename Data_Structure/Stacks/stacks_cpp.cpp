#include<iostream>
template<class T>
class Node
{
public:
  T data;
  Node<T> *next;
};
template<class T>
class Stacks
{
private:
  Node<T> *head;
public:
  Stacks(T data=T())
  {
    head->data = data;
    head->next = NULL;
    std::cout << "constructor: " << head->data << '\n';
  }
  int isEmpty(Node<T> *head)
  {
      return !head;
  }
  void push(T value)
  {
    Node<T> *new_node = new Node<T>;
    new_node->data = value;
    new_node->next = head;
    head = new_node;
  }
  T pop()
  {
    Node<T> *temp = new Node<T>;
    temp = head;
    if(isEmpty(temp))
    {
      return T();
    }
    head = head->next;
    T popped = temp->data;
    delete temp;
    return popped;
  }
  T peek()
  {
    Node<T> *temp = new Node<T>;
    temp = head;
    if(isEmpty(temp))
    {
      return T();
    }
    else
    {
      return temp->data;
    }
  }
  void display()
  {
    Node<T> *temp = new Node<T>;
    temp = head;
    while(temp!=NULL)
    {
      std::cout << "displaying Stacks: "<< temp->data << '\n';
      temp = temp->next;
    }
  }

};
int main()
{
  Stacks<char *> s1("hello");
  s1.push("li");
  s1.push("mi");
  s1.push("chi");
  s1.display();
  std::cout << "After pop: " << s1.pop()<< '\n';
  std::cout << "After pop: " << s1.pop()<< '\n';
  std::cout << "Peek     : " << s1.peek()<< '\n';

  return 0;
}
