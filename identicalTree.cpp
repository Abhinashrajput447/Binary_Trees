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

  return root;
}

bool isSame(Node* p, Node* q) {
  if(p == NULL || q == NULL) return p == q;

  bool isLeftSame = isSame(p->left, q->left);
  bool isRightSame = isSame(p->right, q->right);

  return (isLeftSame && isRightSame) && (p-> data && q ->  data);

  // return (p->data == q->data) && isSame(p->left, q->left) && isSame(p->right, q->right);
}


int main() {
  vector<int> first = {1, 2, -1, -1, 3, -1, -1};
  vector<int> second = {1, 2, -1, -1, 3, -1, -1};

  Node* root1 = buildTree(first);
  Node* root2 = buildTree(second);

  bool same = isSame(root1 , root2);
  cout << (same ? "same tree : " : "Different tree : ");
  return 0;
}