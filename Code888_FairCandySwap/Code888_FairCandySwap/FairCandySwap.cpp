/*
https://leetcode.com/problems/fair-candy-swap/
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int sumA = accumulate(A.begin(), A.end(), 0);
		int sumB = accumulate(B.begin(), B.end(), 0);
		int distance = (sumA - sumB) / 2;
		vector<int>res;
		for (int i = 0; i < A.size(); i++){
			for (int j = 0; j < B.size(); j++){
				if (A[i] - B[j] == distance){
					res.push_back(A[i]);
					res.push_back(B[j]);
					break;
				}
			}
			if (!res.empty()){
				break;
			}
		}
		return res;
	}
};

int main(){
	vector<int>A1 = { 1, 1 };
	vector<int>B1 = { 2, 2 };
	vector<int>A2 = { 1, 2 };
	vector<int>B2 = { 2, 3 };
	vector<int>A3 = { 2 };
	vector<int>B3 = { 1, 3 };
	vector<int>A4 = { 1, 2, 5 };
	vector<int>B4 = { 2, 4 };
	Solution s;
	cout << s.fairCandySwap(A1, B1)[0] << " " << s.fairCandySwap(A1, B1)[1] << endl;
	cout << s.fairCandySwap(A2, B2)[0] << " " << s.fairCandySwap(A2, B2)[1] << endl;
	cout << s.fairCandySwap(A3, B3)[0] << " " << s.fairCandySwap(A3, B3)[1] << endl;
	cout << s.fairCandySwap(A4, B4)[0] << " " << s.fairCandySwap(A4, B4)[1] << endl;
	system("pause");
	return 0;
}