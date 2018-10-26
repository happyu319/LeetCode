/*
https://leetcode.com/problems/island-perimeter/description/
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
	int islandPerimeter(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		int perimeter = 0;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (grid[i][j] == 0){
					continue;
				}
				int up = i - 1;
				int down = i + 1;
				int left = j - 1;
				int right = j + 1;
				if (up < 0 || grid[up][j] == 0){
					perimeter++;
				}
				if (down == row || grid[down][j] == 0){
					perimeter++;
				}
				if (left < 0 || grid[i][left] == 0){
					perimeter++;
				}
				if (right == col || grid[i][right] == 0){
					perimeter++;
				}
			}
		}
		return perimeter;
	}
};

int main(){
	vector<vector<int>>grid = { { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 1, 0, 0 }, { 1, 1, 0, 0 } };
	Solution s;
	cout << s.islandPerimeter(grid) << endl;
	system("pause");
	return 0;
}