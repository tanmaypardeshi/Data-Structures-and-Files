//============================================================================
// Name        : Assignment3.cpp
// Author      : Harsh Sakhrani
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Create binary tree and perform following operations.
 * 1. Insert (rec & non-rec)
 * 2. Display (rec & non-rec)
 * 3. Depth of the tree
 * 4. Display leaf nodes
 * 5. Create a copy of the tree
 */
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

class tree
{
    node* root;


public:
    tree();
    node* getnode(){return root; }
    void  setnode(node* te){root = te; }
    void create();
    node* insert_withoutRec();
    void create_withoutRec();
    node* insert_withRec();
    void inorder(node*);
    void inorder_withoutRec(node*);
    int depth_ofTree(node *);
    void leafNodes(node *);
    void copy();
    node* tcopy(node *);
    ~tree();
};

tree::tree()
{
    root = NULL;
}

void tree::create()
{
    root = insert_withRec();
}

node* tree::insert_withRec()
{
    node *temp;
    char ch;

    temp = new node();

    cout<<"\nEnter data to be added in the tree: ";
    cin>>temp->data;

    temp->left = temp->right = NULL;
    
    cout<<"\nWould you like to add a left child to "<<temp->data<<"?(y/n)";
    cin>>ch;
    if(ch == 'y' || ch == 'Y')
        temp->left = insert_withRec();
    
    cout<<"\nWould you like to add a right child to "<<temp->data<<"?(y/n)";
    cin>>ch;
    if(ch == 'y' || ch == 'Y')
        temp->right = insert_withRec();
    
    return temp;
}

void tree::create_withoutRec()
{
    root = insert_withoutRec();
}

node* tree::insert_withoutRec()
{
    int x;
    queue<node *> q;
    node* temp;
    temp = new node;
    
    cout<<"\nEnter data or -1 to stop: ";
    cin>>x;
    
    if(x == -1)
        return NULL;
   
    temp->data = x;
    q.push(temp);
    
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        cout<<"\nEnter data of left node of "<<temp->data<<" or -1 to stop: ";
        cin>>x;
        if(x!=-1)
        {
            temp->left = new node;
            temp->left->data = x;
            q.push(temp->left);
        }
        cout<<"\nEnter data of right node of "<<temp->data<<" or -1 to stop: ";
        cin>>x;
        if(x!=-1)
        {
             temp->right = new node;
             temp->right->data = x;
            q.push(temp->right);
        }
        
    }
    return temp;
}
void tree::inorder(node* t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}

void tree::inorder_withoutRec(node* t)
{
    stack<node*> s;
    while(t!=NULL)
    {
        s.push(t);
        t = t->left;
    }
    while(!s.empty())
    {
        t = s.top();
        s.pop();
        cout<<t->data<<" ";
        t = t->right;
        while(t!=NULL)
        {
            s.push(t);
            t = t->left;
        }
    }
}
int tree::depth_ofTree(node *t)
{
    int hl, hr;
    if(t == NULL)
        return 0;
    if(t->left == NULL && t->right == NULL)
        return 0;
    hl = depth_ofTree(t->left);
    hr = depth_ofTree(t->right);
    if(hl>hr)
        return (hl+1);
    return (hr+1);
}

void tree::leafNodes(node *t)
{
    if(!t)
        return;
    
    if(!t->left && !t->right)
    {
        cout<<t->data<<" ";
        return;
    }
    
    if(t->left)
        leafNodes(t->left);
    
    if(t->right)
        leafNodes(t->right);
}

void tree::copy()
{
    node *t;
    t = tcopy(root);
    inorder(t);
}

node* tree::tcopy(node* t)
{
    node* p;
    p = NULL;
    if(t != NULL)
    {
        p = new node;
        p->data = t->data;
        p->left = tcopy(t->left);
        p->right = tcopy(t->right);
    }
    return p;
}

tree::~tree()
{
    delete root;
}

int main() {
    tree t;
    int choice;
    while(1)
    {
        cout<<"\n\nChoose from the following options: ";
        cout<<"\n1. Insert element in tree without recursion.";
        cout<<"\n2. Insert element in tree with recursion.";
        cout<<"\n3. Display tree with recursion.";
        cout<<"\n4. Display tree without recursion.";
        cout<<"\n5. Depth of the tree.";
        cout<<"\n6. Display leaf nodes.";
        cout<<"\n7. Create a copy of the tree.";
        cout<<"\n8. Exit.";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1: t.create_withoutRec();
                break;
        case 2: t.create();
                break;
        case 3: cout<<"\nInorder traversal of the tree is: ";
                t.inorder(t.getnode());
                break;
        case 4: cout<<"\nInorder traversal of the tree without recursion is: ";
                t.inorder_withoutRec(t.getnode());
                break;
        case 5: cout<<"\nDepth of tree is: "<<t.depth_ofTree(t.getnode());
                break;
        case 6: cout<<"\nLeaf nodes: ";
                t.leafNodes(t.getnode());
                break;
        case 7: cout<<"\nCopy of the tree: ";
                t.copy();
                break;
        case 8: return 0;

        }
    }
    return 0;
}
