/*
https://leetcode.com/problems/array-partition-i/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int>& nums) {
	int sum = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i += 2){
		sum = sum + nums[i];
	}
	return sum;
}
/*
int arrayPairSum(vector<int>& nums) {
	int bucket[20001] = { 0 };
	int sum = 0;
	for (int i = 0; i < nums.size(); i++){
		bucket[nums[i] + 10000]++;
	}

	bool skipnext = false;
	int numbersinbucket = 0;
	int times = 0;

	for (int i = 0; i < 20001; i++){
		if (bucket[i]){
			numbersinbucket = bucket[i] - (skipnext ? 1 : 0);
			times = numbersinbucket / 2;
			skipnext = numbersinbucket % 2;
			if (skipnext){
				times++;
			}
			sum += (i - 10000) * times;
		}
	}
	return sum;
}*/

int main(){
	vector<int>arr = { 1, 3, 2, 4, 5, 5, 5, 5, 5, 5 };
	int minSum = arrayPairSum(arr);
	cout << minSum << endl;
	system("pause");
	return 0;
}