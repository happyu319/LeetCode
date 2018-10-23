/*
https://leetcode.com/problems/flipping-an-image/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(vector<int>&arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	if (A.size() == 0){
		return A;
	}
	for (int i = 0; i < A.size(); i++){
		for (int j = 0, k = A[i].size() - 1; j <= k; j++, k--){
			if (j != k){
				A[i][j] = A[i][j] ^ 1;
				A[i][k] = A[i][k] ^ 1;
				if (A[i][j] != A[i][k]){
					swap(A[i], j, k);
				}
			}
			else{
				A[i][j] = A[i][j] ^ 1;
			}	
		}
	}
	return A;
}

int main(){
	vector<vector<int>>A = { { 1, 1, 0 }, { 1, 0, 1 }, { 0, 0, 0 } };
	vector<vector<int>>B = flipAndInvertImage(A);
	for (int i = 0; i < B.size(); i++){
		for (int j = 0; j < B[i].size(); j++){
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}