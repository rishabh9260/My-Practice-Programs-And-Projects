#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *right;
    node *left;
    int height;
    node(int x)
    {
        data=x;
        right=NULL;
        left=NULL;
        height=1;
    }
};

node* newnode(int x);
node* insert(node *root,int x);
void display(node *root);
node* del(node *root,int x);

int main()
{
    int ch;
    node *root;
    root=NULL;
    do
    {
        cout<<endl;
        cout<<"Enter 1 to insert"<<endl;
        cout<<"Enter 2 to display"<<endl;
        cout<<"Enter 3 to delete"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cout<<"Enter you choice : ";
        cin>>ch;

        switch(ch)
        {
            case 0: exit(0);

            case 1: int x;
                    cout<<endl<<"Enter the element you want to insert : ";
                    cin>>x;
                    root=insert(root,x);
                    break;
            case 2: cout<<endl;
                    display(root);
                    break;

            case 3: cout<<endl<<"Enter the element you want to delete : ";
                    cin>>x;
                    root=del(root,x);
                    break;
            default: cout<<"Wrong Choice...."<<endl;
                     break;
        }
    }while(ch);
}

node* newnode(int x)
{
    node *p;
    p=new node(x);
    return p;
}

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int getheight(node *root)
{
    if(root==NULL) return 0;
    else return root->height;
}

node* rightrotate(node *root)
{
    node *l = root->left;
    node *r = l->right;

    l->right=root;
    root->left=r;

    root->height = 1 + max(getheight(root->left),getheight(root->right));
    l->height = 1 + max(getheight(l->left),getheight(l->right));

    return l;
}

node* leftrotate(node *root)
{
    node *r = root->right;
    node *l = r->left;

    r->left=root;
    root->right=l;

    root->height = 1 + max(getheight(root->left),getheight(root->right));
    r->height = 1 + max(getheight(r->left),getheight(r->right));

    return r;
}

node* insert(node *root,int x)
{ 
    if(root==NULL)
    {
        root=newnode(x);
        return root;
    }
    else
    {
        if(x<root->data) root->left=insert(root->left,x);
        else root->right=insert(root->right,x);

        root->height = 1 + max(getheight(root->left),getheight(root->right));
        
        int bf;
        bf = getheight(root->left) - getheight(root->right);
        cout<<bf;

        if(bf>1)
        {
            if(x<root->left->data) root=rightrotate(root);
            else
            {
                root->left=leftrotate(root->left);
                root=rightrotate(root);
            }
        }

        if(bf<-1)
        {
            if(x>root->right->data) root=leftrotate(root);
            else
            {
                root->right=rightrotate(root->right);
                root=leftrotate(root);
            }
        }

        return root;
    }
}

node* del(node *root,int x)
{
    if(root==NULL) return root;
    else
    {
        if(x<root->data) root->left=del(root->left,x);
        else if(x>root->data) root->right=del(root->right,x);
        else
        {
            node *temp;
            if(root->left==NULL)
            {
                temp=root->right;
                delete root;
            }

            else if(root->right==NULL)
            {
                temp=root->left;
                delete root;
            }

            else
            {
                node *par;
                temp=root->right;
                par=root->right;
                while(temp->left!=NULL) 
                {
                    par=temp;
                    temp=temp->left;
                }
                if(par==temp) 
                {
                    temp->left=root->left;
                    temp->height = 1 + max(getheight(root->left),getheight(root->right));
                }
                else
                {
                    par->left=temp->right;
                    par->height--;
                    temp->right=root->right;
                    temp->left=root->left;
                    root->height = 1 + max(getheight(root->left),getheight(root->right));
                }
            }
            return temp;
        }
        root->height = 1 + max(getheight(root->left),getheight(root->right));
        int bf;
        bf = getheight(root->left) - getheight(root->right);

        if(bf>1)
        {
            if(x<root->left->data) root=rightrotate(root);
            else
            {
                root->left=leftrotate(root->left);
                root=rightrotate(root);
            }
        }

        if(bf<-1)
        {
            if(x>root->right->data) root=leftrotate(root);
            else
            {
                root->right=rightrotate(root->right);
                root=leftrotate(root);
            }
        }

        return root;
    }
}

void display(node *root)
{
    if(root==NULL) return;
    cout<<"\t"<<root->data;
    display(root->left);
    display(root->right);
}