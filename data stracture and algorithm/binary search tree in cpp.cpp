#include<iostream>
using namespace std;
struct node{
struct node* ladd;
int data;
struct node* radd;
};
struct node* root=NULL;
struct node* create(struct node* p,int n);
void inorder (struct node* p);
void preorder (struct node* p);
void postorder(struct node* p);
int main(){
int n,ch;
do{
    cout<<"\n1-create\n2-inorder\n3-preorder\n4-postorder\n5-exit\n";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"enter value ,press 0 to quit\t";
        cin>>n;
        while(n!=0)
        {
            root =create(root ,n);
            cout<<"enter next value ,press 0 to quit\t";
              cin>>n;
        }
        break;
        case 2:inorder(root);break;
        case 3:preorder(root);break;
        case 4:postorder(root);break;
        case 5:break;
        default:cout<<"\ninvalid\n";

    }
}
    while(ch!=5);
return 0;
}
struct node*  create(struct node* p,int n)
{
    if (p==NULL)
    {
        p=(struct node*)malloc(sizeof (struct node));
        p->ladd=NULL;
        p->data=n;
        p->radd=NULL;
    }
    else
    {
        if(n<p->data)
            {
          p->ladd=create(p->ladd,n) ;
        }
        else if(n>p->data){
            p->radd=create(p->radd,n);

        }
        else {
           cout<<"\nsame data is not allowed\n";
        }
    }
    return p;

};

void inorder(struct node* p){
if(p!=NULL){
    inorder(p->ladd);
    cout<<p->data<<"\t";

    inorder(p->radd);
}

}
void preorder(struct node* p){
if(p!=NULL)
{
    cout<<p->data<<"\t";

   preorder(p->ladd);
   preorder(p->radd);
}
}
void postorder(struct node* p){
if(p!=NULL)
{

   preorder(p->ladd);
   preorder(p->radd);
   cout<<p->data<<"\t";
}
}



