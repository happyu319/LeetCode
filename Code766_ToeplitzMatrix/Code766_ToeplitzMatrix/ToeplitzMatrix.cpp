/*
https://leetcode.com/problems/toeplitz-matrix/description/
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
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty()){
			return false;
		}
		bool flag = true;
		for (int i = 0; i < matrix.size() - 1; i++){
			for (int j = 0; j < matrix[i].size() - 1; j++){
				if (matrix[i][j] != matrix[i + 1][j + 1]){
					flag = false;
					break;
				}
			}
			if (!flag){
				break;
			}
		}
		return flag;
	}
};

int main(){
	vector<vector<int>>matrix = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };
	Solution s;
	cout << s.isToeplitzMatrix(matrix) << endl;
	system("pause");
	return 0;
}