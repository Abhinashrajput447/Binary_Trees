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
Node* buildTree(vector<int>& preorder) {
  idx++;

  if(preorder[idx] == -1) return NULL;

  Node* root = new Node(preorder[idx]);
  root -> left = buildTree(preorder);
  root -> right = buildTree(preorder);

  return root;
}


int countNode(Node* root ) {
  if(root == NULL) return 0;

  int leftCount = countNode(root -> left);
  int rightCount = countNode(root -> right);

  return leftCount + rightCount + 1;
}
int main() {
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node* root = buildTree(preorder);
  cout << countNode(root) << endl;
  
  return 0;
}