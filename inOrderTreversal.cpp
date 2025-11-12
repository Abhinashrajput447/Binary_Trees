#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

static int idx = -1;   
/*if you don't want to use static so remove static 
and do pass by reference*/
Node* buildTree(vector<int> preorder) {   // TC => O(1)
  idx++;

  if(preorder[idx] == -1) return NULL;

  Node* root = new Node(preorder[idx]);
  root -> left = buildTree(preorder);
  root -> right = buildTree(preorder);

  return root;
}

void inOrder(Node* root) {  // TC => O(1)
  if(root == NULL) return;

  inOrder(root -> left);
  cout << root -> data << " ";
  inOrder(root -> right);
}

int main() {
  vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

  Node* root = buildTree(preorder);
  inOrder(root);

  cout << endl;
  return 0;
}