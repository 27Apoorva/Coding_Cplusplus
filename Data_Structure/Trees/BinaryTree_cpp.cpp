#include <iostream>
#include <queue>
#include <stack>
class TreeNode
{
  public:
  int data;
  TreeNode *leftNode;
  TreeNode *rightNode;
};
class Tree
{
  private:
    TreeNode *root;
    void add_child(int value,TreeNode *child_node)
    {
      TreeNode *temp = new TreeNode;
      if(value > child_node->data)
      {
        std::cout << "greater" << '\n';
        if (!child_node->rightNode)
        {
          temp->data = value;
          temp->leftNode = NULL;
          temp->rightNode = NULL;
          child_node->rightNode = temp;
        }
        else
        {
          add_child(value,child_node->rightNode);
        }
      }
      else
      {
        std::cout << "lesser" << '\n';
        if (!child_node->leftNode)
        {
          temp->data = value;
          temp->leftNode = NULL;
          temp->rightNode = NULL;
          child_node->leftNode = temp;
        }
        else
        {
          add_child(value,child_node->leftNode);
        }
      }

    }
    void display_tree(TreeNode *temp)
    {
      if(!temp)
      {
        return;
      }
      display_tree(temp->leftNode);
      std::cout << "display_tree: " << temp->data << '\n';
      display_tree(temp->rightNode);
    }
  public:
    Tree()
    {
      root = NULL;
      std::cout << "in Tree Constructor" << '\n';
    }
    void add(int value)
    {
      if(root == NULL)
      {
        TreeNode *temp = new TreeNode;
        std::cout << "root == NULL" << '\n';
        temp->data = value;
        temp->leftNode = NULL;
        temp->rightNode = NULL;
        root = temp;
      }
      else
      {
        this->add_child(value,root);
      }
    }

    void display()
    {
        display_tree(this->root);
      //  std::cout << "my printing: " <<this->root->rightNode->leftNode->leftNode->data << '\n';
    }
    void BFS_usingQueue()
    {
      TreeNode * temp = new TreeNode;
      temp = root;
      if(root == NULL)
      {
        return;
      }
      std::queue<TreeNode *> my_que;
      my_que.push(temp);
      while(my_que.empty() == false)
      {
        TreeNode *temp_node = my_que.front();
        std::cout << "value of BFS:" << my_que.front()->data << '\n';
        my_que.pop();
        if(temp_node->leftNode !=NULL)
        {
          my_que.push(temp_node->leftNode);
        }
        if(temp_node->rightNode !=NULL)
        {
          my_que.push(temp_node->rightNode);
        }
      }
    }
    void DFS_InOrder()
    {
      TreeNode * temp = new TreeNode;
      temp = root;
      bool test = false;
      if(root == NULL)
      {
        return;
      }
      std::stack<TreeNode *> my_stack;
      while(!test)
      {
        if(temp!=NULL)
        {
          my_stack.push(temp);
          temp = temp->leftNode;
        }
        else
        {
          if(my_stack.empty() == false)
          {
            TreeNode *popped_node = my_stack.top();
            std::cout << "DFS_InOrder: " << my_stack.top()->data<< '\n';
            my_stack.pop();
            temp = popped_node->rightNode;
          }
          else
          {
            test = true;
          }
        }
      }
    }
    void DFS_PreOrder()
    {
      TreeNode *temp = new TreeNode;
      temp = root;
      std::stack<TreeNode *> my_stack;
      my_stack.push(temp);
      while(my_stack.empty() == false)
      {
        TreeNode *popped_node = my_stack.top();
        std::cout << "DFS_PreOrder: " << my_stack.top()->data<< '\n';
        my_stack.pop();
        if(popped_node->rightNode != NULL)
        {
          my_stack.push(popped_node->rightNode);
        }
        if(popped_node->leftNode !=NULL)
        {
          my_stack.push(popped_node->leftNode);
        }

      }
    }
      void DFS_PostOrder()
      {
        TreeNode *temp = new TreeNode;
        temp = root;
        std::stack<TreeNode *> my_stack;
        my_stack.push(root);

        do
        {

          while(temp != NULL)
          {
            if(temp->rightNode)
            {
              my_stack.push(temp->rightNode);
            }
            my_stack.push(temp);
            temp = temp->leftNode;
          }
          temp = my_stack.top();
          my_stack.pop();
          if(temp->rightNode && my_stack.top() == temp->rightNode)
          {
            my_stack.pop();
            my_stack.push(temp);
            temp = temp->rightNode;
          }
          else
          {
              std::cout << "DFS_PostOrder: " << temp->data<< '\n';
              temp = NULL;
          }
        }
        while (my_stack.empty() == false );
      }



};
int main()
{
  Tree t1;
  t1.add(5);
  t1.add(8);
  t1.add(4);
  t1.add(0);
  t1.add(9);
  t1.add(7);
  t1.add(6);
  t1.display();
  t1.BFS_usingQueue();
  t1.DFS_InOrder();
  t1.DFS_PreOrder();
  t1.DFS_PostOrder();

}
