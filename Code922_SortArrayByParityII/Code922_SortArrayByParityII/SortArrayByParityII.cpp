/*
https://leetcode.com/problems/sort-array-by-parity-ii/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		if (A.size() < 2){
			return A;
		}
		for (int i = 0, j = 1; i < A.size() && j < A.size(); i += 2, j += 2){
			if (A[i] % 2 == 0 && A[j] % 2 == 1){
				continue;
			}
			else if (A[i] % 2 != 0 && A[j] % 2 == 1){
				i -= 2;
			}
			else if (A[i] % 2 == 0 && A[j] % 2 != 1){
				j -= 2;
			}
			else{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		return A;
	}
};

int main(){
	vector<int>A = { 4, 2, 5, 7 };
	Solution s;
	vector<int>B = s.sortArrayByParityII(A);
	for (int i = 0; i < B.size(); i++){
		cout << B[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}