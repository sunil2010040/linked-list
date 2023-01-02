
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

int length(node*head)
{
    int l=0;
    node*temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}

node*kappend(node*&head, int k)
{
    node*newhead;
    node*newtail;
    node*tail=head;
    
    int l=length(head);
    k=k%l;
    int count=1;
    
    
    while(tail->next!=NULL)
    {
        if(count==l-k)
        {
            newtail=tail;
        }
        
        if(count==l-k+1)
        {
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;
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
    
    node*newhead=kappend(head,3);
    display(newhead);
}


OUTPUT:

the data added at end of linked list:
1->2->3->4->5->NULL
3->4->5->1->2->NULL


