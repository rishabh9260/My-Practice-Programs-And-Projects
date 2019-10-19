#include<bits/stdc++.h>
using namespace std;

//Node Class
class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int a)
    {
        this->data=a;
        this->left=NULL;
        this->right=NULL;
    }
};

//BinaryTree class 
class binaryTree
{
    public:
    node *root;
    binaryTree() //Initializes the root of the binary tree
    {
        root = NULL;
    }

    void create(int n) //Creates the binary tree by initializing the root node
    {
        if(root!=NULL)
        {
            cout<<"\nBinary Tree already exists!\n";
        }
        else
        {
            root = new node(n);
        }
        
    }

    void insert(node *rootNode, int x) //inserts at the desired leaf position in the binary tree
    {
        int ch;
        if(rootNode==NULL)
        {
            cout<<"\nFirst create the root Node!\n";
        }
        else
        {
            cout<<"\nEnter 0 to insert left or 1 to insert right of "<<rootNode->data<<": ";
            cin>>ch;
            if(ch==0)
            {
                if(rootNode->left!=NULL)
                {
                    cout<<"\nElement "<<rootNode->left->data<<" exists in left!\n";
                    insert(rootNode->left, x);
                }
                else
                {
                    node *p = new node(x);
                    rootNode->left = p;
                }
            }
            else if(ch==1)
            {
                if(rootNode->right!=NULL)
                {
                    cout<<"\nElement "<<rootNode->right->data<<" exists in right!\n";
                    insert(rootNode->right, x);
                }
                else
                {
                    node *p = new node(x);
                    rootNode->right = p;
                    cout<<"\nElement Inserted!\n";
                }
            }
            else
            {
                cout<<"\nInvalid Input!!\n";
            }
        }
    }

    node* search(int x)
    {
        stack<node*> st;
        node * init = new node(INT_MIN);
        st.push(init);
        node *ptr = root;
        int flag = 0;
        while(ptr!=init)
        {
            if(ptr->data == x)
            {
                flag = 1;
                return ptr;
            }
            if(ptr->right != NULL)
            {
                st.push(ptr->right);
            }
            if(ptr->left != NULL)
            {
                ptr=ptr->left;
            }
            else
            {
                ptr=st.top();
                st.pop();
            } 
        }
        if(flag==0)
        {
            cout<<"\nElement not Found!!\n";
            return NULL;
        }
    }

    void deleteNode(int x)
    {
        node *rootNode = root;
        if(rootNode==NULL)
        {
            cout<<"\nThe tree is empty!\n";
        }
        else
        {
            rootNode = search(x);
            if(rootNode->left!=NULL && rootNode->right!=NULL)
            {
                cout<<"\nThe element cannot be deleted as it has 2 child nodes!\n";
            }
            else if(rootNode->left==NULL || rootNode->right==NULL)
            {
                if(rootNode->left==NULL && rootNode->right==NULL)
                {
                    rootNode=NULL;
                    free(rootNode);
                }
                else if(rootNode->left != NULL)
                {
                    node *temp = rootNode->left;
                    rootNode->data = temp->data;
                    rootNode->left = temp->left;
                    free(temp);
                }
                else if(rootNode->right != NULL)
                {
                    node *temp = rootNode->right;
                    rootNode->data = temp->data;
                    rootNode->right = temp->right;
                    free(temp);
                }
            }
        }
    }
};

int main()
{
    int ch;
    int data;
    binaryTree b1;
    cout<<"\nBinary Tree Program!\n";
    cout<<"\n1.Create\n";
    cout<<"2.Insert\n";
    cout<<"3.Search\n";
    cout<<"4.Delete\n";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    switch (ch)
    {
        case 1: cout<<"\nEnter root node data: ";
                cin>>data;
                b1.create(data);
                break;
        case 2: cout<<"\nEnter data for insertion: ";
                cin>>data;
                b1.insert(b1.root,data);
                break;
        case 3: cout<<"\nEnter data to search: ";
                cin>>data;
                node * temp = b1.search(data);
                if(temp!=NULL)
                {
                    cout<<"\nData Found!!";
                }
                break;
        case 4: cout<<"\nEnter data for insertion: ";
                cin>>data;
                b1.deleteNode(data);
                break;
        default:
                break;
    }
    return 0;
}