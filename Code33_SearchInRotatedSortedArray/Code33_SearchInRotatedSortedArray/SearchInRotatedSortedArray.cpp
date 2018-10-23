/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/
#include <iostream>
#include <vector>
using namespace std;

int turnPoint(vector<int>& nums, int left, int right) {
	if (left > right || right >= nums.size() || left < 0) {
		return -1;
	}
	int mid = (left + right) / 2;
	if (mid >= 1 && nums[mid] < nums[mid - 1]) {
		return mid;
	}
	int leftPoint = turnPoint(nums, left, mid - 1);
	int rightPoint = turnPoint(nums, mid + 1, right);
	if (leftPoint != -1) {
		return leftPoint;
	}
	if (rightPoint != -1) {
		return rightPoint;
	}
	return -1;
}

int findNum(vector<int>& nums, int left, int right, int target) {
	if (left > right || nums[left] > target || nums[right] < target || left < 0 || right >= nums.size()) {
		return -1;
	}
	int mid = (left + right) / 2;
	if (nums[mid] > target) {
		return findNum(nums, left, mid - 1, target);
	}
	if (nums[mid] < target) {
		return findNum(nums, mid + 1, right, target);
	}
	return mid;
}

int search(vector<int>& nums, int target) {
	if (nums.size() == 0)
		return -1;
	if (nums[0] <= nums[nums.size() - 1]) {
		return findNum(nums, 0, nums.size() - 1, target);
	}
	int point = turnPoint(nums, 0, nums.size() - 1);
	int left = findNum(nums, 0, point - 1, target);
	int right = findNum(nums, point, nums.size() - 1, target);
	if (left != -1) {
		return left;
	}
	if (right != -1) {
		return right;
	}
	return -1;
}

int main() {
	int array[] = { 0, 1, 2, 4, 5, 6, 7 };
	vector<int>nums(array, array + 7);
	cout << turnPoint(nums, 0, 6) << endl;
	cout << search(nums, 0) << endl;
	cout << search(nums, 3) << endl;
	system("pause");
	return 0;
}