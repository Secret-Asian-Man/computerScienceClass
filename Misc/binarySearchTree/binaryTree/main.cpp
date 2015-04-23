#include <iostream>
#include "node.h"
using namespace std;

bool insert(node* &root, int key);
node* search(node *root, int key);
void preOrder(node* root);
void inorder(node* root);
void postOrder(node* root);

int main()
{
    node* test=NULL;

    insert(test,10);
    insert(test,52);
    insert(test,4);
    insert(test,236);
    insert(test,410);
    insert(test,5);

    cout<<"DEBUG preOrder: ";
    preOrder(test);
    cout<<endl;

    cout<<"DEBUG inorder: ";
    inorder(test);
    cout<<endl;

    cout<<"DEBUG postOrder: ";
    postOrder(test);
    cout<<endl;

}

bool insert(node *&root, int key)
{
    if (root==NULL) //
    {
        root=new node(key);
        return true;
    }
    if (root->_item==key) //if it is found already, return false for failure
    {
        return false;
    }
    if (root->_item>key)
    {
        return insert(root->_left,key);
    }
    else
    {
        return insert(root->_right,key);
    }
}

node* search(node* root, int key)
{
    if (root==NULL)
    {
        return NULL;
    }
    if (root->_item==key)
    {
        return root;
    }

    if (root->_item>key)
    {
        return search(root->_left,key);
    }
    else
    {
        return search(root->_right,key);
    }
}

void preOrder(node* root)
{
    if (root!=NULL)
    {
        cout<<root->_item<<" ";
        preOrder(root->_left);
        preOrder(root->_right);
    }

}

void inorder(node* root)
{
    if (root!=NULL)
    {
        inorder(root->_left);
        cout<<root->_item<<" ";
        inorder(root->_right);
    }
}

void postOrder(node* root)
{
    if (root!=NULL)
    {
        postOrder(root->_left);
        postOrder(root->_right);
        cout<<root->_item<<" ";
    }

}
