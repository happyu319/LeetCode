/*
https://leetcode.com/problems/search-in-a-binary-search-tree/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = []() {
	std::ios::sync_with_stdio(false);//设置在每次输入/输出操作后标准C ++流是否与标准C流同步
	std::cin.tie(nullptr);//解除std :: cin和std :: cout之间的绑定，降低IO的负担使效率提升
	return nullptr;
}();

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr){
			return nullptr;
		}
		if (root->val == val){
			return root;
		}
		else{
			if (root->val < val){
				return searchBST(root->right, val);
			}
			else{
				return searchBST(root->left, val);
			}
		}
	}
};

void preOrder(TreeNode* root){
	if (root == nullptr){
		return;
	}
	cout << root->val << " ";
	if (root->left != nullptr){
		preOrder(root->left);
	}
	if (root->right != nullptr){
		preOrder(root->right);
	}
}

int main(){
	TreeNode Node1(4), Node2(2), Node3(7), Node4(1), Node5(3);
	Node1.left = &Node2;
	Node1.right = &Node3;
	Node2.left = &Node4;
	Node2.right = &Node5;
	Solution s;
	TreeNode *node = s.searchBST(&Node1, 2);
	preOrder(node);
	system("pause");
	return 0;
}