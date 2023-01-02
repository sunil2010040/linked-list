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

void intersect(node*&head1, node*&head2, int pos)
{
    node*temp1=head1;
    pos--;
    while(pos--)
    {
        temp1=temp1->next;
    }
    
    node*temp2=head2;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int main()
{
    node*head1=NULL;
    node*head2=NULL;
    
    insertatend(head1,1);
    insertatend(head1,2);
    insertatend(head1,3);
    insertatend(head1,4);
    insertatend(head1,5);
    insertatend(head1,6);
    insertatend(head2,9);
    insertatend(head2,10);
    intersect(head1,head2,3);
    display(head1);
    display(head2);
}

OUTPUT:

1->2->3->4->5->6->NULL
9->10->3->4->5->6->NULL
