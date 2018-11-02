/*
https://leetcode.com/problems/surface-area-of-3d-shapes/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		int area = 0;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (grid[i][j] != 0){
					area = area + grid[i][j] * 6 - (grid[i][j] - 1) * 2;
				}
			}
		}
		for (int i = 1; i < row; i++){
			for (int j = 0; j < col; j++){
				int temp = min(grid[i - 1][j], grid[i][j]);
				area = area - temp * 2;
			}
		}
		for (int j = 1; j < col; j++){
			for (int i = 0; i < row; i++){
				int temp = min(grid[i][j - 1], grid[i][j]);
				area = area - temp * 2;
			}
		}
		return area;
	}
};

int main(){
	vector<vector<int>>grid1 = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
	vector<vector<int>>grid2 = { { 1, 0 }, { 0, 2 } };
	Solution s;
	cout << s.surfaceArea(grid1) << endl;
	cout << s.surfaceArea(grid2) << endl;
	system("pause");
	return 0;
}