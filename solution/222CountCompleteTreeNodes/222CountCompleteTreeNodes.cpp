#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int depth(TreeNode *root) {
    int d = 0;
    if (root != nullptr) {
      d++;
      while (root->right != nullptr) {
        d++;
        root = root->right;
      }
    }
    return d;
  }

public:
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int count = 0;
    do {
      int depth_left = depth(root->left);
      int depth_right = depth(root->right);
      // cout<<depth_left<<" "<<depth_right<<endl;
      if (depth_left == depth_right) {
        count += pow(2, depth_right);
        root = root->left;
      } else {
        count += pow(2, depth_left);
        root = root->right;
      }
    } while (root != nullptr);
    return count;
  }
};