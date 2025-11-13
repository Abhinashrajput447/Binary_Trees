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

int idx = -1;
Node* createTree(vector<int>& preorder) {
  idx++;

  if(preorder[idx] == -1) return NULL;

  Node* root = new Node(preorder[idx]);

  root -> left = createTree(preorder);
  root -> right = createTree(preorder);

  return root;
}

int sumNodes(Node* root) {
  if(root == NULL) return 0;

  int ls = sumNodes(root -> left);
  int rs = sumNodes(root -> right);
  
  int d = root -> data;
  int sum = rs + d + ls;

  return sum;
}

int main() {
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node* root = createTree(preorder);
  cout << sumNodes(root) ;
  // sumNodes(root);
  return 0;
}