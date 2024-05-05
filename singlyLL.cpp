#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
int data;
Node* next;
 Node(int data)
 {
  this-> data= data;
   this->next=NULL;
 }
 //destructor
 ~Node()
 {
    int value = this ->data;
    //memory free
    if(this->next != NULL)
    {delete next;
    this->next = NULL;
    }
    cout<<"Memory is free for node with value "<<value<<endl;
 }
};
//to insert at head
void insertHead(int data,Node* &head)
{
Node* temp = new Node(data);
temp->next=head;
head= temp;
}
//to print the data
void print(Node* &head)
{
Node* temp= head;
while(temp!=NULL)
{
    cout<<temp->data<<"  ";
    temp=temp->next;
}
cout << endl;
}
//to insert at tail
void insertTail(int d, Node* &tail)
{
 Node* temp = new Node(d);
 tail->next= temp;
 tail= temp;
}
//to insert at position
void insertposition(int d,int pos,Node* &head,Node* &tail)
{ //to insret at first position
if(pos==1){
insertHead(d,head);
return;
}
   Node* temp = head;
   int cnt=1;
   while(cnt<pos-1)
   {
    temp=temp->next;
    cnt++;
   } 
   Node* newnode= new Node(d);
   newnode->next= temp->next;
   //cout<<"sahi hai";
   temp->next=newnode;
   if(temp->next==NULL)
   {
    insertTail(d,tail);
   }
}
void deleteNode(int pos, Node* &head)
{
    //to delete first node
    if(pos==1)
    {
        Node* temp =head;
        head=head->next;
        //memory free start node
        temp->next=NULL;
        delete temp;
    }
    else
    {
        //delete any middle node or end node
        Node* curr = head;
        Node* prev = NULL;
        int cnt=1;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
           
        }
         prev->next=curr->next;
         curr->next=NULL;
         delete curr;
    }
}
int main()
{
    Node* n = new Node(10);
//    cout<<n->data<<endl;
Node* head=n;
Node* tail=n;
print(head);
    insertHead(12,head);
    insertHead(13,head);
    insertHead(14,head);
    insertHead(15,head);
    print(head);
    insertTail(67,tail);
   print(head);
    insertposition(34,7,head,tail);
    print(head);
    deleteNode(3,head);
    print(head);
    return 0;
}