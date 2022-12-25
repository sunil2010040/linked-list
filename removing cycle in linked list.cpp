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

void makecycle(node*&head,int pos)
{
    node*temp=head;
    node*startnode;
    
    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool detectcycle(node*&head)
{
    node*hare=head;
    node*turtle=head;
    
    while(hare!=NULL && hare->next!=NULL)
    {
        hare=hare->next->next;
        turtle=turtle->next;
        if(hare==turtle)
        {
            return true;
        }
    }
    return false;
}

void removecycle(node*&head)
{
    node*hare=head;
    node*turtle=head;
    
    do{
        hare=hare->next->next;
        turtle=turtle->next;
    }while(hare!=turtle);
    
    hare=head;
    
    while(hare->next!=turtle->next)
    {
        hare=hare->next;
        turtle=turtle->next;
    }
    
    turtle->next=NULL;
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
    insertatend(head,6);
    insertatend(head,7);
    insertatend(head,8);
    display(head);
    cout<<endl;
    
    makecycle(head,4);
   
    cout<<detectcycle(head)<<endl;      //If the cycle was detected then it return 1 else0 
    
    removecycle(head);
    display(head);                      //function calling to remove cycle
}


OUTPUT:

the data added at end of linked list:
1->2->3->4->5->6->7->8->NULL

1
1->2->3->4->5->6->7->8->NULL
