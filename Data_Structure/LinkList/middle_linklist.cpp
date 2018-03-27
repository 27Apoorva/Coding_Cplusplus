/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node
struct Node {
    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
   int count = 0;
   if(head == NULL)
   {
       return -1;
   }
   else
   {
       Node *temp = new Node;
       temp = head;
       while(temp!=NULL)
       {
           count++;
           temp = temp->next;

       }
       if(count%2!=0)
       {
           for(auto i = 1; i<(count+1)/2;i++)
           {
            head = head->next;
           }
           return head->data;
       }
       else
       {
           for(auto i = 1; i<(count/2)+1;i++)
           {
            head = head->next;
           }
           return head->data;
       }
   }
}
