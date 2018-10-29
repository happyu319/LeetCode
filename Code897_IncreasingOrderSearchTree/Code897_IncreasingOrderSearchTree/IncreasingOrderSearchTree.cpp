/*
https://leetcode.com/problems/increasing-order-search-tree/description/
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*--------------leetcode´úÂë
class Solution {
public:
	TreeNode* DFS(TreeNode* node, TreeNode* last) {
		if (!node)
			return last;
		TreeNode* new_root = DFS(node->left, node);
		node->left = NULL;
		node->right = DFS(node->right, last);

		return new_root;
	}

	TreeNode* increasingBST(TreeNode* root) {
		return DFS(root, NULL);
	}
};*/

class Solution {
public:
	TreeNode* increasingBST(TreeNode* root) {
		if (root == nullptr){
			return nullptr;
		}
		stack<TreeNode*>Nodes;
		queue<TreeNode*>newNodes;
		TreeNode *temp = root;
		while (!Nodes.empty()||temp!=nullptr){
			if (temp != nullptr){
				Nodes.push(temp);
				temp = temp->left;
			}
			else{
				newNodes.push(Nodes.top());
				temp = Nodes.top()->right;
				Nodes.pop();
			}
		}
		TreeNode *head = newNodes.front();
		while (!newNodes.empty()){
			TreeNode *temp = newNodes.front();
			newNodes.pop();
			if (newNodes.empty()){
				temp->right = nullptr;
				temp->left = nullptr;
			}
			else{
				temp->right = newNodes.front();
				temp->left = nullptr;
			}	
		}
		return head;
	}
	void BFS(TreeNode* root){
		if (root == nullptr)
			return;
		queue<TreeNode*>Nodes;
		Nodes.push(root);
		int preNum = 1;
		int curNum = 0;
		while (!Nodes.empty()){
			TreeNode *temp = Nodes.front();
			Nodes.pop();
			preNum--;
			cout << temp->val;
			if (temp->left != nullptr){
				Nodes.push(temp->left);
				curNum++;
			}
			if (temp->right != nullptr){
				Nodes.push(temp->right);
				curNum++;
			}
			if (preNum == 0){
				cout << endl;
				preNum = curNum;
				curNum = 0;
			}
			else{
				cout << " ";
			}
		}
	}
};

int main(){
	TreeNode Node1(1), Node2(2), Node3(3), Node4(4), Node5(5),
		Node6(6), Node7(7), Node8(8), Node9(9);
	Node5.left = &Node3;
	Node5.right = &Node6;
	Node3.left = &Node2;
	Node3.right = &Node4;
	Node2.left = &Node1;
	Node6.right = &Node8;
	Node8.left = &Node7;
	Node8.right = &Node9;
	Solution s;
	TreeNode *root = s.increasingBST(&Node5);
	s.BFS(root);
	system("pause");
	return 0;
}