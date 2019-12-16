#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *l, *r;
};

struct node* insert(struct node *,int);
struct node* create(int item);
void search(struct node *,int);
struct node* delete(struct node *,int);
void display(struct node *);

void main()
{
    int ch,item;
    struct node *root=NULL;
    do
    {
        printf("\nEnter 1 to insert");
        printf("\nEnter 2 to display");
        printf("\nEnter 3 to search");
        printf("\nEnter 4 to delete");
        printf("\nEnter 0 to exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 0: break;

            case 1: printf("\nEnter the value : ");
                    scanf("%d",&item);
                    root=insert(root,item);
                    break;

            case 2: display(root);
                    break;

            case 3: printf("\nEnter the value : ");
                    scanf("%d",&item);
                    search(root,item);
                    break;

            case 4: printf("\nEnter the value : ");
                    scanf("%d",&item);
                    root=delete(root,item);
                    break;

            default: printf("\nWrong choice....");
                     break;
        }
    } while (ch);
}

struct node* create(int item)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));

    p->data=item;
    p->l=NULL;
    p->r=NULL;

    return p;
}

struct node* insert(struct node *root,int item)
{
    if(root==NULL) root=create(item);

    else if(item<root->data) root->l=insert(root->l,item);

    else root->r=insert(root->r,item);

    return root;
}

void search(struct node *temp,int item)
{
    while(temp!=NULL)
    {
        if(temp->data==item) { printf("\nElement found"); return; }

        else if (item>temp->data) temp=temp->r;

        else if (item<temp->data) temp=temp->l;
    }

    printf("\nElement not found");
    return;
}

struct node* delete(struct node *root,int item)
{
    if(root==NULL) return root;

    else if(item<root->data) root->l=delete(root->l,item);

    else if(item>root->data) root->r=delete(root->r,item);

    else
    {
        if(root->l==NULL)
        {
            struct node *temp;
            temp=root->r;
            free(root);
            return temp;
        }

        else if(root->r==NULL)
        {
            struct node *temp;
            temp=root->l;
            free(root);
            return temp;
        }

        else
        {
            struct node *temp, *par;
            temp=root->r;
            par=root->r;
            while(temp->l!=NULL) 
            {
                par=temp;
                temp=temp->l;
            }
            if(par==temp) 
            {
                par->l=root->l;
                return par;
            }
            else
            {
                par->l=temp->r;
                temp->r=root->r;
                temp->l=root->l;
                return temp;
            }
        }   
    }
}

void display(struct node *root)
{
    if(root==NULL) return;

    else
    {
        display(root->l);
        printf("\n%d",root->data);
        display(root->r);
    }
}