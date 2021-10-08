#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
}*start, *last, *previous, *newnode, *temp;

void initialize(){
    start == NULL;
    last == NULL;
    cout<<endl<<"Linked list is initialized!"<<endl<<endl;
}

void underflow(){
    if (start == NULL)
    {
        cout<<endl<<"Linked list is empty!"<<endl<<endl;
    }
    else{
        cout<<endl<<"The top element of linked list is : "<<start->data<<endl<<endl;
    }
}

void insertion(){
    cout<<endl<<"Enter the data you want to insert : ";
    int a;
    cin>>a;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;
    if (start == NULL)
    {       
        start = temp;
    }
    else{
        last->next = temp;
    }
    last = temp;
    cout<<a<<" is inserted in the linked list!"<<endl<<endl;
}

void before(){
    if (start==NULL)
    {
        cout<<endl<<"Linked list is empty!"<<endl<<endl;
    }
    else{
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode==NULL)
        {
            cout<<endl<<"New node is not allocated!"<<endl<<endl;
        }  
        else{    
        int e, d;
        cout<<endl<<"Enter the element before which you want to insert a new node : ";
        cin>>e;
        temp = start;
        while (temp!= NULL && temp->data!=e)
        {
            previous = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout<<"Element not found!"<<endl<<endl;
        }
        else{
            cout<<"Enter the data you want to store in newnode : ";
            cin>>d;
            newnode->data = d;
            newnode->next = temp;
            if (previous == NULL)
            {
                start = newnode;
            }
            else{
                previous->next = newnode;
            }     
            cout<<d<<" is inserted in the newnode!"<<endl<<endl;    
        }
        } 
    }
}

void after(){
    if (start == NULL)
    {
        cout<<endl<<"Linked list is empty!"<<endl<<endl;
    }
    else{ 
    int e, d;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        cout<<endl<<"New node is not allocated!"<<endl<<endl;
    }
    else{
        cout<<endl<<"Enter the element after which you want to insert a newnode : ";
        cin>>e;
        temp = start;
        while (temp!= NULL && temp->data!= e)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout<<"Element not found!"<<endl<<endl;
        }
        else{
            cout<<"Enter the data you want to insert in the new node : ";
            cin>>d;
            newnode->data = d;
            newnode->next = temp->next;
            if (temp == last)
            {
                last = newnode;
            }
            temp->next = newnode;
            cout<<d<<" is inserted in the newnode!"<<endl<<endl;
        }
    }
    }
}

void deletion(){
    if (start == NULL)
    {
        cout<<endl<<"Linked list is empty!"<<endl<<endl;
    }
    else{
    int e;
    cout<<endl<<"Enter the element you want to delete from the linked list : ";
    cin>>e;
    temp = start;
    previous = NULL;
    while (temp!= NULL && temp->data!=e)
    {
        previous = temp;
        temp = temp->next;
    }
    if (temp==NULL)
    {
        cout<<"Element not found!"<<endl<<endl;
    }
    else if(previous == NULL){
        start = temp->next;
        free(temp);       
        cout<<e<<" is deleted!"<<endl<<endl;
    }
    else{
        previous->next = temp->next;
        if (temp == last)
        {
            last = previous;
        }
        free(temp);       
        cout<<e<<" is deleted!"<<endl<<endl;
    }
    }
}

void display(){
    if (start == NULL)
    {
        cout<<endl<<"Linked list is empty!"<<endl<<endl;
    }
    else{
        temp = start;
        cout<<endl;
        while (temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl<<endl;
    }
}

int main() {
    int n;
    do
    {
        cout<<"For the operations on linked list : "<<endl;
        cout<<"Enter 1 for initialization."<<endl;
        cout<<"Enter 2 for underflow."<<endl;
        cout<<"Enter 3 for insertion."<<endl;
        cout<<"Enter 4 for insertion before an element."<<endl;
        cout<<"Enter 5 for insertion after an element."<<endl;
        cout<<"Enter 6 for deletion of an element."<<endl;
        cout<<"Enter 7 to display."<<endl;
        cin>>n;
        switch (n)
        {
        case 1:
            initialize();
            break;
        case 2:
            underflow();
            break;
        case 3:
            insertion();
            break;
        case 4:
            before();
            break;
        case 5:
            after();
            break;
        case 6:
            deletion();
            break;
        case 7:
            display();
            break;           
        default:
            cout<<"Enter a valid input!"<<endl;
            break;
        }
    } while (n>0 && n<8);
    
    return 0;
}