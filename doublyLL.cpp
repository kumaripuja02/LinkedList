#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
int data;
Node* prev;
Node* next;
//constructor
Node(int d)
{
    this->data=d;
    this->prev=NULL;
    this->next=NULL;
}
//DESTRUCTOR
~Node()
{
    int val = this->data;
    if(next!=NULL)
    {
        delete next;
        next= NULL;
    }
    cout<<"Memory free for node with data "<<val<<endl;
}
};
//to print the node
void print(Node* head)
{
    Node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
// to get the length of nodes
int getLength(Node* head)
{
    int len=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
//to insert at head
void insertHead(Node* &tail,Node* &head , int d)
{
    //empty list
    if(head==NULL)
    {
        Node*temp= new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp = new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
}
void insertTail(Node* &tail,Node* &head,int d)
{
    if(tail==NULL){
        Node* temp = new Node(d);
       head= temp;
        tail= temp;
    }
    else{
    Node* temp = new Node(d);
    tail->next= temp;
    temp->prev= tail;
    tail= temp; 
}   
}
//to insert at position
void insertPosition(Node* &head, Node* &tail,int d, int pos)
{
    //insert at start
    if(pos==1)
    {
        insertHead(tail,head,d);
        return;
    }
    Node* temp = head;
    int cnt=1;
    while(cnt<pos-1){
    temp=temp->next;
    cnt++;
    }
    //inserting at last position
    if(temp->next == NULL)
    {
        insertTail(tail,head,d);
        return;
    }
    //to insert at any other position
Node* newnode = new Node(d);
newnode->next=temp->next;
temp->next->prev=newnode;
temp->next=newnode;
newnode->prev=temp;
}
//for deletion of the node
void deleteNode(int pos, Node* &head)
{
    //to delete first node
    if(pos==1)
    {
    Node* temp= head;
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    delete temp;
}
else{
    //delete any middle node or last node
    Node* curr = head;
    Node* prev = NULL;
    int cnt=1;
    while(cnt<pos)
    {
     prev=curr;
     curr=curr->next;
     cnt++;
    }
    curr-> prev=NULL;
     prev->next=curr->next;
     curr->next=NULL;
     delete curr;
}
}
int main()
{
  //  Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
   
    insertHead(tail,head, 11);
    insertHead(tail,head, 12);
    insertHead(tail,head, 13);
    insertHead(tail,head, 14);
    insertHead(tail,head, 15);
        print(head);

    insertTail(tail,head, 34);
   
    insertPosition(head,tail,45,2);
    print(head);
    insertPosition(head,tail,55,1);
    print(head);
    insertPosition(head,tail,50,9);
    print(head);
    
    
    deleteNode(4,head);
 cout<<getLength(head)<<endl;
      cout<<head->data<<endl;
cout<<tail->data<<endl;
    return 0;
}