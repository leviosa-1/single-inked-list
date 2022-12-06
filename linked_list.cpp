#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *temp,*p,*q;
class linked_list
{
    private : struct node *start;
    public : linked_list()
             { start=NULL;}
             void inset_at_first(int ele);
             void insert_at_last(int ele);
             void insert_at_mid(int key, int ele);
             int count();
             void search(int key);
             void display();
             void del_by_search(int key);
             void del_by_pos(int pos);
};

void linked_list :: search(int key)
{
    int found=0;
    if(start==NULL)
       cout<<"list is empty"<<endl;
    else
    {
        p=start;
        while(p!=NULL)
        {
            if(p->data==key)
            {
                found=1;
                break;
            }
            p=p->next;
        }
        if(found==0)
          cout<<"element not found"<<endl;
        else
          cout<<"element found"<<endl;
    }
}
void linked_list :: inset_at_first(int ele)
{
    p=new node;
    p->data=ele;
    if(start==NULL)
      p->next=NULL;
    else
      p->next=start;
    start=p;
    cout<<"element inserted"<<endl;
}
void linked_list :: insert_at_last(int ele)
{
    p=new node;
    p->data=ele;
    p->next=NULL;
    if(start==NULL)
       start=p;
    else
    {
        q=start;
        while(q->next!=NULL)
            q=q->next;
            q->next=p;
    }
    cout<<"element inserted"<<endl;
}
void linked_list :: insert_at_mid(int key,int ele)
{
     if(start==NULL || start->next==NULL)
        cout<<"insertion is not possible due to less elements"<<endl;
    else 
    {
        p=start;
        while(p!=NULL)
        {
            if(p->data==key)
              break;
            p=p->next;
        }
        
    } 
    if(p==NULL)
          cout<<"Searched element not found"<<endl;
        else if(p->next==NULL)
            cout<<"element found at the last"<<endl;
    else
    {
        temp=new node;
        temp->data = ele;
        temp->next = p-> next;
        p->next =temp;
        cout<<"element inserted"<<endl;
    }
} 
void linked_list :: display()
{
    if(start==NULL)
       cout<<"The linked list is empty"<<endl;
    else
    {
        p=start;
        while(p!=NULL)
            {
                cout<<p->data<<"->";
                p=p->next; 
            }
        
    }
}

int linked_list :: count()
{
    int c=0;
    if(start==NULL)
       cout<<"The linked list is empty"<<endl;
    else
    {
        p=start;
        while(p!=NULL)
            {
                c++;
                p=p->next;
            }
     return c;   
    }
}
void linked_list :: del_by_search(int key)
{
    if(start==NULL || start->next==NULL || start->next->next==NULL)
      cout<<"Deletion is not possible"<<endl;
    else
    {
        p=start;
        while(p!=NULL)
            {
                if(p->data==key)
                  break;
                q=p;
                p=p->next;
            }
            if(p==NULL)
              cout<<"element not found"<<endl;
            else if(p->next==NULL || p==start)
               cout<<"Deletion is not possible beczuse element found at first and last position"<<endl;
            else
            {
                q->next=p->next;
                cout<<p->data<<"->";
                delete p;
            }
        
    }
       

}
int main()
{
    linked_list l;
    int s,n,choice;
    do
    {
        cout<<"1. Insert at first."<<endl;
        cout<<"2. Insert at last."<<endl;
        cout<<"3. Insert at middle by searching."<<endl;
        cout<<"4. Count the number of elements"<<endl;
        cout<<"5. Display the elements."<<endl;
        cout<<"6. Delete by searching"<<endl;
        cout<<"7. search element"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1: cout<<"enter the element you want to insert at first"<<endl;
                cin>>n;
                l.inset_at_first(n);
                break;
        case 2: cout<<"enter the element you want to insert at last"<<endl;
                cin>>n;
                l.insert_at_last(n);
                break;
        case 3: cout<<"enter the search elemeent after which you want to insert"<<endl;
                cin>>s;
                cout<<"enter the ealement you want you insert after searched element"<<endl;
                cin>>n;
                l.insert_at_mid(s,n);
                break;
        case 4: cout<<"Number of element in linked list:"<<l.count()<<endl;
                break;
        case 5: cout<<"The elements of Linked List are as follows :-"<<endl;
                l.display();
                break;
        case 6: cout<<"enter the element you want to delete"<<endl;
                cin>>s;
                l.del_by_search(s);
        case 7: cout<<"enter the element you want to search"<<endl;
                cin>>s;
                l.search(s);
                break;
        default:
            break;
        }
    }
    while(choice!=8);
    return 0;
}