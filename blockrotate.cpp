#include<bits/stdc++.h>
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
/*void blockRotate(struct node **head,int k,int d,int n)
{
    int i=1;
    struct node *current=*head;


struct node *last1=NULL;
if(k>n||*head==NULL)
    return;
       // struct node *c1=current;
 struct node *c1;
         struct node *prev;
         struct node *temp;

      for(int j=1;j<=n;j=j+k)
        { c1=current;
         prev=NULL;
         temp=NULL;
             while(c1&&i<k)
            {
             prev=c1;
            c1=c1->next;i++;
            }
       if(*head==current)
        {
           if(d<0)
           {
             temp=c1->next;
             prev->next=temp;
             c1->next=current;
            *head=c1;
            last1=prev;
            current=temp;

           }
           else if(d>0)
          {
             temp=c1->next;
             *head=current->next;
             c1->next=current;
             current->next=temp;
             last1=current;
             current=temp;
         }
        }
        else
            {

                if(d<0)
                {
                    temp=c1->next;
                    prev->next=temp;
                    c1->next=current;
                    last->next=c1;
                last=prev;
                current=temp;
                }
                else if(d>0)
                {
                    last->next=current->next;
                    temp=c1->next;
                    c1->next=current;
                    current->next=temp;
                    last1=current;
                    current=temp;

                }
                 current=temp;
                last1=prev;
            }
    }
} */
node* findPrev(node* f,int k){
  int i=1;
  while(i<(k-1)){
    f=f->next;
    i++;
  }
  return f;
}
void blockRotate(node** h,int k,int d,int n){
 node* first,*last,*temp,*prev,*last1;
 for(int i=0;i<n;)
 first=*h;
 prev=findPrev(first,k);
 last=prev->next;
 temp=last->next;
 if(d<0) {
 last->next=first;
 prev->next=temp;
 if(i==0)
 *h=last;
 last1=prev;
 first=temp;
 }
 if(d>0) {
  if(i==0)
   *h=first->next;
 last->next=first;
 first->next=temp;
 last1=first;
 }
 first=temp;
 if(i!=0){
        if(d<0)
    last1->next=first->next;
 }
}
 /*first=temp;
 prev=findPrev(first,k);
 last=prev->next;
 temp=last->next;
*/

}
void print(struct node *head)
{
    if(head==NULL)
        return;
        struct node *current2=head;
    while(current2!=NULL)
    {
        std::cout<<current2->data;
        current2=current2->next;
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

    blockRotate(&head,3,1,6);
    print(head);

}
