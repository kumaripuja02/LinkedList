//program to remove duplicate from a linked list
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this-> next=NULL;
    }
};
void insertAtHead(Node* &head, int data)
{
    Node* temp= new Node(data);
    temp->next=head;
    head=temp;
    
}
Node*uniqueSortedList(Node* &head)
{
    if(head==NULL)
    return NULL;
    //non empty list
    Node* curr=head;
    while(curr!= NULL)
    {
        if((curr->next!=NULL)&& curr->data==curr->next->data)
        {
            Node* next_next = curr->next->next;
            Node* nodeToDelete= curr->next;
            delete(nodeToDelete);
            curr->next=next_next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}
Node* removeDuplicate(Node* &head)
{ if(head==NULL)
    return NULL;
    //non empty list
    Node* curr=head;
    Node* temp= head;
    map<Node* , bool>visited;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {
            
            delete(temp);
            //curr->next=next_next;
        }
        else{
            visited[temp]=true;
        }
        temp=temp->next;
    }
    return head;

}
void printLL(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
    cout<<temp->data<<"  ";
    temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* newNode =new Node(10);
    Node* head= newNode;
    insertAtHead(head,45);
    insertAtHead(head,55);
    insertAtHead(head,65);
    insertAtHead(head,65);
    insertAtHead(head,75);
    printLL(head);
   // uniqueSortedList(head);
   removeDuplicate(head);
    printLL(head);
    return 0;
}