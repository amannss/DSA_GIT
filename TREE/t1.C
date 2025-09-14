// 
#include<bits/stdc++.h>
using namespace std ;

struct node
{
    int data ;
    node* left ;
    node* right ;

    node(int d)
    {
        this->data = d ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

node* buildTree(node* root)
{
    cout << "enter the data: " << endl ;
    int data ;
    cin >> data ;
    root = new node(data) ;

    if(data == -1) return NULL ;

    cout << "enter data for inserting in left " << endl ;
    root->left = buildTree(root->left) ;
    cout << "enter data for inserting in right " << endl ;
    root->right= buildTree(root->right);

}

void levelOrderTraversal(node* root)
{   
    queue<node*> q;
    q.push(root) ;
    // seperator 
    q.push(NULL) ;
    while(!q.empty())
    {
        node* temp = q.front() ;
       
        q.pop(); 
        
        if(temp == NULL )
        {
            cout << endl ;
            if(!q.empty()){q.push(NULL) ;}
        }
        else
        {    cout << temp->data << " " ;
                if(temp->left) 
                {
                    q.push(temp->left) ;
                }
                if(temp->right) 
                {
                    q.push(temp->right) ;
                }
        }
    }
}

void inOrderTraversal(node* root)
{   // L NODE R
    if(root == NULL )  return ;

    inOrderTraversal(root->left) ;
    cout << root->data << " " ;
    inOrderTraversal(root->right) ;
}

void preOrderTraversal(node* root)
{   // NODE L R
    if(root == NULL )  return ;
    cout << root->data << " " ;
    inOrderTraversal(root->left) ;
    inOrderTraversal(root->right) ;
}

void postOrderTraversal(node* root)
{   // L R NODE
    if(root == NULL )  return ;
    inOrderTraversal(root->left) ;
    inOrderTraversal(root->right) ;
    cout << root->data << " " ;
}

int main()
{   
    node* root = NULL ;
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// creating a tree
    root = buildTree(root) ;
// level order traversal
    cout << "inorder traversal : " << endl ;
    levelOrderTraversal(root) ;
// inorder traversal
    cout << endl <<  "inorder traversal : " ;
    inOrderTraversal(root) ;
// preorder traversal
    cout << endl <<  "preorder traversal : " ;
    preOrderTraversal(root) ;
// postorder traversal
    cout << endl << "preorder traversal : " ;
    postOrderTraversal(root) ;
    return  0 ;
}