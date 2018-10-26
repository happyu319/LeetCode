/*
https://leetcode.com/problems/binary-gap/description/
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
	int binaryGap(int N) {
		if (N <= 0){
			return 0;
		}
		int distance = 0;
		int flag = 1;
		while (N != 0){
			int temp = 0;
			if ((N&flag) != 0){//第一个1
				N = N >> 1;
				if (N == 0){
					break;
				}
				while ((N&flag) == 0){//第二个1的前一位
					temp++;
					N = N >> 1;
				}
				temp++;
			}
			else{
				N = N >> 1;
			}
			distance = max(distance, temp);
		}
		return distance;
	}
};

int main(){
	int N = 8;
	Solution s;
	cout << s.binaryGap(N) << endl;
	system("pause");
	return 0;
}