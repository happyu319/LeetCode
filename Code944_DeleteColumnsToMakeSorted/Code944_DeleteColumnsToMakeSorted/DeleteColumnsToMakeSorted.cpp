/*
https://leetcode.com/problems/delete-columns-to-make-sorted/
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		if (A.size() == 0){
			return 0;
		}
		int row = A.size();
		int col = A[0].size();
		int num = 0;
		for (int i = 0; i < col; i++){
			for (int j = 1; j < row; j++){
				if (A[j][i] < A[j - 1][i]){
					num++;
					break;
				}
			}
		}
		return num;
	}
};

int main(){
	vector<string>str1 = { "cba", "daf", "ghi" };
	vector<string>str2 = { "a", "b" };
	vector<string>str3 = { "zyx", "wvu", "tsr" };
	Solution s;
	cout << s.minDeletionSize(str1) << endl;
	cout << s.minDeletionSize(str2) << endl;
	cout << s.minDeletionSize(str3) << endl;
	system("pause");
	return 0;
}