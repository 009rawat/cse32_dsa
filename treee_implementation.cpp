#include<iostream>
using namespace std;

struct node
{
    int val;
    node* left;
    node* right;

    node(int data)
    {
        val = data;
        left = right = NULL;
    }
};

int CountNode( node* root)
{
    if( root == NULL)
        return 0;

    return 1+ CountNode( root -> left) + CountNode( root -> right);
}

int hight( node* root)
{
    if( root == NULL)   
        return 0;

    else{
        int left = hight( root -> left);
        int right = hight( root -> right);

        if( left > right){
            return 1+left;
        }
        else{
            return 1+right;
        }
    }
}

int CountLeafNode( node* root)
{
     if( root == NULL)   
        return 0;

    if( root -> left == NULL && root -> right == NULL)
        return 1;

    else{
        return CountLeafNode(root -> left) + CountLeafNode(root -> right);
    }
}

int Count2child( node* root)
{
      if( root == NULL){
          return 0;
      }  

     if( root -> left != NULL && root -> right != NULL){
         return 1+ Count2child( root -> left)+ Count2child( root -> right);
     }

    else{
         return  Count2child( root -> left)+ Count2child( root -> right);
    }
}

int Count1child( node* root)
{
    if( root == NULL){
        return 0;
    }

    if( root -> left != NULL && root -> right == NULL){
        return 1+ Count1child( root -> left);
    }
    else if(  root -> left == NULL && root -> right != NULL){
        return 1+ Count1child( root -> right);
    }

    else{
        return Count1child( root -> left) + Count1child( root -> right);
    }
}

int sumNodes( node* root)
{
    if(root == NULL){
        return 0;
    }
    return  root -> val + sumNodes(root -> left)+ sumNodes( root -> right);
}

void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(node* root)
{
    if(root == NULL)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main()
{
    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> right = new node(6);
    root -> right -> right -> left = new node(7);

    cout<<" The no. of nodes = " <<  CountNode(root) << endl;
    cout<<" Height = "  << hight(root) << endl;
    cout<<" Leaf node count = " <<  CountLeafNode(root) << endl;
    cout<<" Count 1 child node = " <<  Count1child(root) << endl;
    cout<<" Count 2 child node = " <<  Count2child(root) << endl;
    cout<<" Sum of nodes = "  << sumNodes(root) << endl;

    cout<<" Inorder traversal = ";
    inorder(root);
    cout<<endl;

    cout<<" Preorder traversal = " ;
     preorder(root) ;
     cout<<endl;
     
    cout<<" Postorder traversal = " ;
    postorder(root) ;
    cout<<endl;
}