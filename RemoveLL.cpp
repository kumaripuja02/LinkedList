//Program to remove and detect a loop in the given linked list
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
};//to insert at head
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
//function to detect the loop in the given list using map
bool detectLoop(Node* head)
{
    if(head==NULL)
    return false;
    map<Node* , bool>visited;
    Node* temp= head;
    while(temp!=NULL)
    {
        //cycle is present
        if(visited[temp]== true)
        {
            return 1;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
//function to detect the loop in the given list using floyd detection algorithm
Node* floydDetection(Node* head)
{
    if(head==NULL)
    return NULL;
    Node* slow= head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        fast=fast->next;
        slow=slow->next;
        if(slow==fast)
        return slow;
    }
    return NULL;
}
Node* getStartingNode(Node* head)
{
    if(head==NULL)
    return NULL;
    Node* intersection = floydDetection(head);
    Node* slow=head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection = intersection->next;
    }
    return slow;
}
void removeLoop(Node* head)
{
if(head==NULL)
return;
Node* StartOfLoop= getStartingNode(head);
Node* temp= StartOfLoop;
while(temp->next!=StartOfLoop)
{
    temp=temp->next;
}
temp->next=NULL;
}
int main()
{
    Node* n = new Node(10);
//    cout<<n->data<<endl;
Node* head=n;
Node* tail=n;
//print(head);
    insertHead(12,head);
    insertHead(13,head);
    insertHead(14,head);
    insertHead(15,head);
    //print(head);
    insertTail(67,tail);
    //print(head);
    insertposition(34,7,head,tail);
    print(head);
    tail->next=head->next;

    return 0;
}