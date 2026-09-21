#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data = val;
         left = right = NULL;
    }
};

node* insertNode( node* root, int key){

    if( root == NULL){
        root = new node(key);
        return root;
    }

    queue<node*> q;
        q.push(root);

    while( !q.empty()){
        node* curr = q.front();
        q.pop();

        if( curr -> left != NULL){
            q.push(curr -> left);
        }
        else{
            curr -> left = new node(20);
            return root;
        }

        if( curr -> right != NULL){
            q.push(curr -> right);
        }
        else{
            curr -> right = new node(20);
            return root;
        }
    }
    return root;
};

void inorder(node* curr){
    if( curr == NULL){
        return ;
    }

    inorder(curr -> left);
    cout<< curr-> data<<" ";
    inorder(curr -> right);
}

int main(){

    node* root = new node(20);
    root -> left = new node(11);
    root -> right = new node(9);
    root -> left -> left = new node(16);
    root -> left -> right = new node(17);
    root -> right -> left = new node(18);

    int key = 20;
    root =  insertNode(  root,  key);
   inorder(root);

}
