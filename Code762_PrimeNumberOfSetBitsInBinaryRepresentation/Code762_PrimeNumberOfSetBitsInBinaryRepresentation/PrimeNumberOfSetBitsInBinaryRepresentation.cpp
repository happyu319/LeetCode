/*
https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int countPrimeSetBits(int L, int R) {
		if (L > R){
			return 0;
		}
		int num = 0;
		for (int i = L; i <= R; i++){
			int temp = i;
			int bits = 0;
			while (temp != 0){
				bits = temp & 1 ? bits + 1 : bits;
				temp = temp >> 1;
			}
			num = isPrime(bits) ? num + 1 : num;
		}
		return num;
	}
	bool isPrime(int n){
		return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || 
			n == 13 || n == 17 || n == 19 || n == 23 || n == 29 || n == 31;
	}
};

int main(){
	int L = 6;
	int R = 15;
	Solution s;
	cout << s.countPrimeSetBits(L, R) << endl;
	system("pause");
	return 0;
}