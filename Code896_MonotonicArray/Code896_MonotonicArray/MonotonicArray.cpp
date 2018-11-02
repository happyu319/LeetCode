/*
https://leetcode.com/problems/monotonic-array/description/
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
	bool isMonotonic(vector<int>& A) {
		if (A.size() <= 2){
			return true;
		}
		bool direction;
		bool flag = true;
		for (int i = 1; i < A.size(); i++){
			if (A[i - 1] != A[i]){
				direction = A[i - 1] > A[i];
				flag = false;
				break;
			}
		}
		if (flag){
			return true;
		}
		for (int i = 1; i < A.size(); i++){
			if (direction && (A[i - 1]<A[i])){
				return false;
			}
			else if (!direction && (A[i - 1]>A[i])){
				return false;
			}
			else{
				continue;
			}
		}
		return true;
	}
};

int main(){
	vector<int>A = { 1, 2, 2, 3 };
	vector<int>B = { 6, 5, 4, 4 };
	vector<int>C = { 1, 3, 2 };
	vector<int>D = { 1, 2, 4, 5 };
	vector<int>E = { 1, 1, 1 };
	Solution s;
	cout << s.isMonotonic(A) << endl;
	cout << s.isMonotonic(B) << endl;
	cout << s.isMonotonic(C) << endl;
	cout << s.isMonotonic(D) << endl;
	cout << s.isMonotonic(E) << endl;
	system("pause");
	return 0;
}