#include<bits/stdc++.h>
void add(struct node *,struct node *,struct node *);
using namespace std;
struct node
{
    int data;
    node *next;
}; struct node *last=NULL;
void insert(struct node **head,int element)
{
     struct node *temp=new node;
     temp->data=element;
     temp->next=NULL;
     if(*head==NULL)
     {
         *head=temp;
         last=temp;
     }
     else
     {
         last->next=temp;
         last=temp;
     }
}
void print(struct node *head)
{
    if(head==NULL)
        return;
        struct node *current=head;
    while(current!=NULL)
    {
        std::cout<<current->data;
        if(current!=last)
            cout<<"->";
        current=current->next;
    }
}
struct node *sortNumber(struct node *headref)
{
    struct node *result=NULL;
    struct node *current,*prev;
    int i=0;
    while(i<3)
    {
        current=headref;
        while(current!=NULL)
        {
            prev=NULL;
            if(current->data!=i){
                prev=current;
                    current=current->next;}
                    else{
                        if(current==headref)
                        {
                            headref=current->next;
                            add(result,current,prev);
                        }
                        else
                        {
                            add(result,current,prev);
                        }

                    }

        }
    i++;}
    return result;
}
void add(struct node *r,struct node *c,struct node *prev)
{
    struct node *last2;
    if(prev!=NULL){
    if(r==NULL)
    {
        prev->next=c->next;
             r=c;
             c=prev->next;
             last2=r;
    }
    else{
             prev->next=c->next;
        last2->next=c;
         last2=c;
         c=prev->next;

    }
    }
    else{
        if(r==NULL)
        {
            r=c;
            c=c->next;
            last2=r;
        }
        else{
            last2->next=c;
            last2=c;
            c=c->next;
        }
    }
}
int main()
{
    struct node *head=NULL;
    cout<<"enter the number of elements you are going to insert:";
    int num;
    cin>>num;
    int element;
    for(int i=1;i<=num;i++)
    {
        cout<<"enter"<<i<<"element:";
        cin>>element;
        insert(&head,element);
        cout<<"\n";
    }
     print(head);
    struct node *res=sortNumber(head); print(res);


}

