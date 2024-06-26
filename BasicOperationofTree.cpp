#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void displayTree(Node* root){
  if(root==NULL) return ;
  cout<<root->val<<" ";
  displayTree(root->left);
  displayTree(root->right);
}

int sum(Node* root){
    if(root==NULL) return 0;
    return root->val+sum(root->left)+sum(root->right);
    
}

int size(Node* root){
    if(root==NULL) return 0;
    return 1+size(root->left)+size(root->right);
}
int maxval(Node* root){
    if(root==NULL) return 0;
    return max(root->val,max(maxval(root->left),maxval(root->right)));
}

int product(Node* root){
    if(root==NULL) return 1;
    return root->val*product(root->left)*product(root->right);
}
  
  int levels(Node* root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
  }

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(5);
    Node* e=new Node(6);
    Node* f=new Node(7);
    Node* g=new Node(8);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    displayTree(a);
    cout<<"  ";
    cout<<sum(a)<<" ";
    cout<<size(a)<<" ";
    cout<<maxval(a)<<" ";
    cout<<product(a)<<" ";
    cout<<levels(a)<<" ";

}