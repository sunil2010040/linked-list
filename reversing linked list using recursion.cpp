#include<iostream>
using namespace std;

class node                  		     //USER DEFINED
{
    public:
    int data;
    node*next;
    
    node(int value)         		     //TO SPECIFY DATA AND NEXT 
    {
        data=value;
        next=NULL;
    }
};

void insertatend(node*&head,int val)     //TO SPECIFY WHAT FUNCTION OF LINKEDLIST WE ARE GOING TO USE
{
    node*n=new node(val);
    
    if(head==NULL)                       //IF THERE IS NO NODE PRESENT
    {
        head=n;                          //n IS ADDED AT HEAD PLACE
        return;
    }
    
    node*temp=head;                      //TO INITAILIZE TEMP FROM HEAD
    while(temp->next!=NULL)              //ITERATE TEMP TILL NULL
    {
        temp=temp->next;
    }
    temp->next=n;
}


node* reverse_recursive(node*&head)
{
    if(head==NULL|| head->next==NULL)
    {
        return head;
    }
    
    node*newnode=reverse_recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newnode;
}

void display(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node*head=NULL;        
    cout<<"the data added at end of linked list:"<<endl;         
    insertatend(head,1);                 //INSERTING VALUES INSIDE LINKED LIST
    insertatend(head,2);
    insertatend(head,3);
    insertatend(head,4);
    insertatend(head,5);
    display(head);
    
    node*newhead=reverse_recursive(head);
    display(newhead);
}

OUTPUT:

the data added at end of linked list:
1->2->3->4->5->NULL
5->4->3->2->1->NULL
