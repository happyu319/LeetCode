/*
https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	/*
	vector<int> postorder(Node* root) {
		vector<int>vNode;
		if (root == nullptr){
			return vNode;
		}
		stack<Node*>sNode;
		sNode.push(root);
		while (!sNode.empty()){
			Node *temp = sNode.top();
			sNode.pop();
			vNode.push_back(temp->val);
			for (int i = 0; i < temp->children.size(); i++){
				sNode.push(temp->children[i]);
			}
		}
		reverse(vNode.begin(), vNode.end());
		return vNode;
	}*/

	void postorder_help(Node* root, vector<int>&node){
		for (int i = 0; i < root->children.size(); i++){
			postorder_help(root->children[i], node);
		}
		node.push_back(root->val);
	}

	vector<int> postorder(Node* root) {
		vector<int>vNode;
		if (root == nullptr){
			return vNode;
		}
		postorder_help(root, vNode);
		return vNode;
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
	vector<int>node = s.postorder(&Node1);
	for (int i = 0; i < node.size(); i++){
		cout << node[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}