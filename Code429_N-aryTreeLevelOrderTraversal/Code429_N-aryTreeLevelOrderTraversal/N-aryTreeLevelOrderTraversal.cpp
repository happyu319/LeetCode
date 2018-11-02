/*
https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Node {
public:
	int val = NULL;
	vector<Node*> children;
	Node() {}
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>>rNode;
		if (root == nullptr){
			return rNode;
		}
		queue<Node*>qNode;
		qNode.push(root);
		while (!qNode.empty()){
			int size = qNode.size();
			vector<int>nums;
			for (int i = 0; i < size; i++){
				Node *temp = qNode.front();
				nums.push_back(temp->val);
				qNode.pop();
				for (int j = 0; j < temp->children.size(); j++){
					qNode.push(temp->children[j]);
				}
			}
			rNode.push_back(nums);
		}
		return rNode;
	}
};

int main(){
	vector<Node*>Children;
	Node Node1(1, Children), Node2(2, Children), Node3(3, Children), Node4(4, Children), Node5(5, Children), Node6(6, Children);
	Node1.children.push_back(&Node3);
	Node1.children.push_back(&Node2);
	Node1.children.push_back(&Node4);
	Node3.children.push_back(&Node5);
	Node3.children.push_back(&Node6);
	Solution s;
	vector<vector<int>>node = s.levelOrder(&Node1);
	for (int i = 0; i < node.size(); i++){
		for (int j = 0; j < node[i].size(); j++){
			cout << node[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}