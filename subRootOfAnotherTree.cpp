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
Node* buildTree(vector<int>& arr) {
  idx++;
  if(arr[idx] == -1) return NULL;

  Node* root = new Node(arr[idx]);
  root -> left = buildTree(arr);
  root -> right = buildTree(arr);

  return root;
}

bool isSame(Node* p, Node* q) {
  if(p == NULL || q == NULL) return p == q;

  return p->data == q->data && isSame(p->left, q->left) && isSame(p->right, q->right);
}

bool isSubRootTree(Node* root1, Node* subroot) {
  if(root1 == NULL || subroot == NULL) {
    return root1 == subroot;
  }

  if(root1 -> data && subroot -> data && isSame(root1 , subroot)) {
    return true;
  }

  return isSubRootTree(root1 -> left, subroot) || isSubRootTree(root1 -> right, subroot);
}


int main() {
  vector<int> rootArr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  vector<int> subArr  = {2, 4, -1, -1, 5, -1, -1};

 Node* root = 
}
