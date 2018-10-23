/*
https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

int findSecondMinimumValue(TreeNode* root) {
	if (root == nullptr)
		return -1;
	if (root->left == nullptr || root->right == nullptr)
		return -1;
	int secondMinValue = max(root->left->val, root->right->val);
	TreeNode *temp = root;
	while (temp != nullptr&&temp->left != nullptr&&temp->right != nullptr) {
		int tempValue = max(temp->left->val, temp->right->val);
		if (tempValue != root->val) {
			secondMinValue = min(tempValue, secondMinValue);
		}
		if (temp->left->val < temp->right->val) {
			temp = temp->left;
		}
		else if (temp->left->val > temp->right->val) {
			temp = temp->right;
		}
		else {
			if (temp->left->left == nullptr) {
				temp = temp->right;
			}else if (temp->right->left == nullptr) {
				temp = temp->left;
			}
			else {
				int valueLeft = max(temp->left->left->val, temp->left->right->val);
				int valueRight = max(temp->right->left->val, temp->right->right->val);
				temp = valueLeft > valueRight ? temp->right : temp->left;
			}
		}
	}
	if (secondMinValue == root->val) {
		return -1;
	}
	return secondMinValue;
}

int process(TreeNode* root, int value) {
	if (root->left == nullptr&&root->right == nullptr) {
		return root->val;
	}
	int secondMinValue = 0;
	int tempValue = 0;
	if (root->left->val > root->right->val) {
		secondMinValue = root->left->val;
		tempValue = process(root->right, value);
		if (tempValue != value) {
			secondMinValue = min(tempValue, secondMinValue);
		}
	}
	else if (root->left->val < root->right->val) {
		secondMinValue = root->right->val;
		tempValue = process(root->left, value);
		if (tempValue != value) {
			secondMinValue = min(tempValue, secondMinValue);
		}
	}
	else {
		int valueLeft = process(root->left, value);
		int valueRight = process(root->right, value);
		if (valueLeft == value || valueRight == value) {
			secondMinValue = max(valueLeft, valueRight);
		}
		else {
			secondMinValue = min(valueLeft, valueRight);
		}	
	}
	return secondMinValue;
}

int findSecondMinimumValueRecu(TreeNode* root) {
	if (root == nullptr)
		return -1;
	int secondMinValue = process(root, root->val);
	if (secondMinValue == root->val) {
		return -1;
	}
	return secondMinValue;
}

int main() {
	TreeNode Node1(1), Node2(1), Node3(3), Node4(1), Node5(1), Node6(3), Node7(4), Node8(3),
		Node9(1), Node10(1), Node11(1), Node12(3), Node13(8), Node14(4), Node15(8), Node16(3),
		Node17(3), Node18(1), Node19(6), Node20(2), Node21(1);
	Node1.left = &Node2;
	Node1.right = &Node3;
	Node2.left = &Node4;
	Node2.right = &Node5;
	Node3.left = &Node6;
	Node3.right = &Node7;
	Node4.left = &Node8;
	Node4.right = &Node9;
	Node5.left = &Node10;
	Node5.right = &Node11;
	Node6.left = &Node12;
	Node6.right = &Node13;
	Node7.left = &Node14;
	Node7.right = &Node15;
	Node8.left = &Node16;
	Node8.right = &Node17;
	Node9.left = &Node18;
	Node9.right = &Node19;
	Node10.left = &Node20;
	Node10.right = &Node21;
	cout << findSecondMinimumValue(&Node1) << endl;
	cout << findSecondMinimumValueRecu(&Node1) << endl;
	system("pause");
	return 0;
}