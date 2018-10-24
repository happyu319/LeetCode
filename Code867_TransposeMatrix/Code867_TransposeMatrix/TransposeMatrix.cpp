/*
https://leetcode.com/problems/transpose-matrix/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		if (A.size() == 0){
			return A;
		}
		int row = A.size();
		int col = A[0].size();
		vector<vector<int>>B(col);
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				B[j].push_back(A[i][j]);
			}
		}
		return B;
	}
};

int main(){
	vector<vector<int>>A = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution s;
	vector<vector<int>>B = s.transpose(A);
	for (int i = 0; i < B.size(); i++){
		for (int j = 0; j < B[i].size(); j++){
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}