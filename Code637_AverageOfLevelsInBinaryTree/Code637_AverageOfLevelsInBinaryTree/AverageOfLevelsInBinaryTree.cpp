/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double>nums;
		if (root == nullptr){
			return nums;
		}
		queue<TreeNode*>Node;
		Node.push(root);
		int preNum = 1;
		int curNum = 0;
		double sum = 0;
		int num = 0;
		while (!Node.empty()){
			TreeNode *temp = Node.front();
			Node.pop();
			preNum--;
			sum = sum + temp->val;
			num++;
			if (temp->left != nullptr){
				Node.push(temp->left);
				curNum++;
			}
			if (temp->right != nullptr){
				Node.push(temp->right);
				curNum++;
			}
			if (preNum == 0){
				preNum = curNum;
				curNum = 0;
				nums.push_back(sum / num);
				sum = 0;
				num = 0;
			}
		}
		return nums;
	}
};
/*
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		if (!root) return{ 0 };
		queue<TreeNode*> q;
		q.push(root);
		vector<double> ans;

		while (!q.empty()){
			int size = q.size();
			long sum = 0;
			for (int i = 0; i < size; i++){
				TreeNode* cur = q.front();
				sum += cur->val;
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			ans.push_back(double(sum) / size);
		}
		return ans;
	}
};*/

int main(){
	TreeNode Node1(3), Node2(9), Node3(20), Node4(15), Node5(7);
	Node1.left = &Node2;
	Node1.right = &Node3;
	Node3.left = &Node4;
	Node3.right = &Node5;
	Solution s;
	vector<double>nums = s.averageOfLevels(&Node1);
	for (double num : nums){
		cout << num << endl;
	}
	system("pause");
	return 0;
}