/*
https://leetcode.com/problems/largest-triangle-area/description/
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
	double largestTriangleArea(vector<vector<int>>& points) {
		if (points.size() < 3){
			return 0;
		}
		double res = 0;
		for (int i = 0; i < points.size() - 2; i++){
			for (int j = i + 1; j < points.size() - 1; j++){
				for (int k = j + 1; k < points.size(); k++){
					//S=(1/2)*(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)
					double temp = abs(points[i][0] * points[j][1] + points[j][0] * points[k][1] + points[k][0] * points[i][1] 
						- points[i][0] * points[k][1] - points[j][0] * points[i][1] - points[k][0] * points[j][1]) / 2.0;
					res = max(res, temp);
				}
			}
		}
		return res;
	}
};

int main(){
	vector<vector<int>>points_01 = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 0, 2 }, { 2, 0 } };
	vector<vector<int>>points_02 = { { 4, 6 }, { 6, 5 }, { 3, 1 } };
	vector<vector<int>>points_03 = { { 8, 3 }, { 5, 6 }, { 3, 5 } };
	vector<vector<int>>points_04 = { { 1, 0 }, { 0, 0 }, { 0, 1 } };
	Solution s;
	cout << s.largestTriangleArea(points_01) << endl;
	cout << s.largestTriangleArea(points_02) << endl;
	cout << s.largestTriangleArea(points_03) << endl;
	cout << s.largestTriangleArea(points_04) << endl;
	system("pause");
	return 0;
}