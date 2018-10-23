/*
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
*/

#include <iostream>
#include <vector>
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

void allDepth(Node* root, int depth, vector<int>&Depth) {
	if (root == nullptr) {
		return;
	}
	if (root->children.size() == 0) {
		Depth.push_back(depth + 1);
	}
	for (int i = 0; i < root->children.size(); i++) {
		allDepth(root->children[i], depth + 1, Depth);
	}
}

int maxDepth(Node* root) {
	if (root == nullptr)
		return 0;
	vector<int>Depth;
	int depth = 0;
	allDepth(root, depth, Depth);
	vector<int>::iterator maxDepth = max_element(Depth.begin(), Depth.end());
	return *maxDepth;
}

int main() {
	Node Node1, Node2;
	Node1.children.push_back(&Node2);
	cout << maxDepth(&Node1) << endl;
	system("pause");
	return 0;
}