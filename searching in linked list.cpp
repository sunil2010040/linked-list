#include<iostream>
using namespace std;

class node                 					 //USER DEFINED
{	
    public:
    int data;
    node*next;
    
    node(int value)         					//TO SPECIFY DATA AND NEXT 
    {
        data=value;
        next=NULL;
    }
};

void insertatend(node*&head,int val) 			//TO SPECIFY WHAT FUNCTION OF LINKEDLIST WE ARE GOING TO USE
{
    node*n=new node(val);
    
    if(head==NULL)                  			//IF THERE IS NO NODE PRESENT
    {
        head=n;                     			//n IS ADDED AT HEAD PLACE
        return;
    }
    
    node*temp=head;                 			//TO INITAILIZE TEMP FROM HEAD
    while(temp->next!=NULL)         			//ITERATE TEMP TILL NULL
    {
        temp=temp->next;
    }
    temp->next=n;
}

void insertatbegin(node*&head,int val)              	//TO SPECIFY WHAT FUNCTION OF LINKEDLIST WE ARE GOING TO USE
{
    node*n=new node(val);                           
    n->next=head;
    head=n;
}

bool search(node*head,int key)				//TO SEARCH FOR VALUIE IN LINKED LIST
{
    node*temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void display(node*head)						//TO DISPLAY THE LINKED LIST
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
    cout<<"the data added at end in linked list:"<<endl;             
    insertatend(head,1);            //INSERTING VALUES INSIDE LINKED LIST
    insertatend(head,2);
    insertatend(head,3);
    display (head);
    cout<<endl;


    cout<<"the data added at beginning of linked list:"<<endl;
    insertatbegin(head,4);
    insertatbegin(head,5);
    display(head);
    cout<<endl;

    cout<<"searching element in linked list"<<endl;
    cout<<search(head,3)<<endl;
    cout<<endl;
}


OUTPUT:

the data added at end in linked list:
1->2->3->NULL

the data added at beginning of linked list:
5->4->1->2->3->NULL

searching element in linked list
1
