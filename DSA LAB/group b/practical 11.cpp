/*
Title:Write a c++ program to construct Binary search tree perform insertion,deletion ,searching and its traversal.
Date:05/12/2022
Author:Pranav Kulkarni
*/

#include <iostream>

using namespace std;

struct node{
 int data;
 struct node *left,*right;
};

struct node *newnode(int data){
 node *temp=new node();
 temp->data=data;
 temp->right=NULL;
 temp->left=NULL;
 return temp;
}

struct node *insert(struct node * node,int data){
 if(node==NULL){
  return newnode(data);
  
 }
 if(data<node->data){
  node->left=insert(node->left,data);
 }else{
  node->right=insert(node->right,data);
 }
 return node;
}

void inorder(struct node* root){
 if(root!=NULL){
  inorder(root->left);
  cout<<root->data<<"-->";
  inorder(root->right);
 }
}
void preorder(struct node* root){
 if(root!=NULL){
 	cout<<root->data<<"-->";
	preorder(root->left);
	preorder(root->right);
 }
}
void postorder(struct node* root){
 if(root!=NULL){
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<"-->";
 }
}
int search(struct node* root ,int data){
 int flag=0;
 if(root==NULL){
   return NULL;
 }
 if(root->data==data){
  flag=1;
  return flag;
 }
 if(data<root->data){
   search(root->left,data);
   flag=1;
   return flag;
 }
 if(data>root->data){
  
  search(root->right,data);
  flag=1;
  return flag;
 }
}
// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}
int main()
{
    int choice,ch,key,flag,no;
    struct node* root=NULL;
    do{
     
      cout<<"\n----BINARY SEARCH TREE OPERATIONS----";
      cout<<"\n1.Insert Node\n2.Display All Nodes\n3.Search Node\n4.Delete Node\n5.Exit";
      cout<<"\nEnter Your Choice :";
      cin>>ch;
      switch(ch){
       case 1:
       cout<<"\n Enter Value of node:";
       cin>>key;
        root=insert(root,key);
        break;
       case 2:
        cout<<"\nInorder Traversal...";
        inorder(root);
        cout<<"\nPreorder Traversal...";
        preorder(root);
        cout<<"\nPostorder Traversal...";
        postorder(root);
        break;
       case 3:
        cout<<"\nEnter Node Value to search:";
        cin>>key;
        flag=search(root,key);
        if(flag==1){
         cout<<"\nNode Value Found..";
        }else{
         cout<<"\nData Not Found..";
        }
        break;
       case 4:
       	cout<<"\nEnter Node Value to delete the node:";
       	cin>>no;
       	deleteNode(root,no);
        break;
       case 5:
       
        break;
      }
      cout<<"\nDo You Want to continue press 1:";
      cin>>choice;
    }while(choice==1);

    return 0;
}
