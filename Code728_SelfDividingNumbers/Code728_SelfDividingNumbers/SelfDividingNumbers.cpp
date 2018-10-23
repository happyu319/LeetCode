/*
https://leetcode.com/problems/self-dividing-numbers/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> selfDividingNumbers(int left, int right) {
	vector<int>nums;
	if (left > right){
		return nums;
	}
	for (int num = left; num <= right; num++){
		int temp = num;
		bool flag = true;
		while (temp != 0){
			if (temp % 10 == 0 || num % (temp % 10) != 0){
				flag = false;
				break;
			}
			temp = temp / 10;
		}
		if (flag){
			nums.push_back(num);
		}
	}
	return nums;
}

int main(){
	int left = 1, right = 22;
	vector<int>arr = selfDividingNumbers(left, right);
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}