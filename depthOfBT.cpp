#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->data = val;
        left=right=NULL;
    }
};

static int idx = -1;
TreeNode* buildTree(vector<int>& nodes) {
    idx++;
    if(nodes[idx] == -1) return NULL;

    TreeNode* root = new TreeNode(nodes[idx]);

    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

void inorder(TreeNode* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;

    int leftHt = maxDepth(root->left);
    int rightHt = maxDepth(root->right);

    return max(leftHt, rightHt)+1;
}

int main() {
    vector<int> nodes = {5, 1, -1, -1, 6, -1, 7, -1, 8, -1, -1};

    TreeNode* root = buildTree(nodes);

    inorder(root);
    cout << endl;
    cout << maxDepth(root) << endl;
    return 0;
}