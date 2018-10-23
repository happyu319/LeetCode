/*
https://leetcode.com/problems/projection-area-of-3d-shapes/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int topViewArea(vector<vector<int>>& grid){
		int area = 0;
		for (int i = 0; i < grid.size(); i++){
			for (int j = 0; j < grid[i].size(); j++){
				if (grid[i][j] != 0){
					area++;
				}
			}
		}
		return area;
	}
	int frontViewArea(vector<vector<int>>& grid){
		int area = 0;
		for (int i = 0; i < grid[0].size(); i++){
			int temp = 0;
			for (int j = 0; j < grid.size(); j++){
				if (temp < grid[j][i]){
					temp = grid[j][i];
				}
			}
			area = area + temp;
		}
		return area;
	}
	int leftViewArea(vector<vector<int>>& grid){
		int area = 0;
		for (int i = 0; i < grid.size(); i++){
			int temp = 0;
			for (int j = 0; j < grid[i].size(); j++){
				if (temp < grid[i][j]){
					temp = grid[i][j];
				}
			}
			area = area + temp;
		}
		return area;
	}
	int projectionArea(vector<vector<int>>& grid) {
		if (grid.size() == 0){
			return 0;
		}
		int topArea = topViewArea(grid);
		int frontArea = frontViewArea(grid);
		int leftArea = leftViewArea(grid);
		return topArea + frontArea + leftArea;
	}
};

int main(){
	vector<vector<int>>grid = { { 1, 2 }, { 3, 4 } };
	Solution s;
	int area = s.projectionArea(grid);
	cout << area << endl;
	system("pause");
	return 0;
}