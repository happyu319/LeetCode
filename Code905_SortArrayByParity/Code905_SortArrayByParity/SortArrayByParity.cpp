/*
https://leetcode.com/problems/sort-array-by-parity/description/
*/
#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

vector<int> sortArrayByParity(vector<int>& A) {
	if (A.empty()){
		return A;
	}
	vector<int>::iterator it_head = A.begin();
	vector<int>::iterator it_tail = A.end() - 1;
	while (it_head <= it_tail){
		if ((*it_head) % 2 != 0){
			swap(*it_head, *it_tail);
			it_tail--;
		}
		else{
			it_head++;
		}
	}
	return A;
}

int main(){
	int array[] = { 3, 1, 2, 4 };
	vector<int>arr(array, array + 4);
	vector<int>res = sortArrayByParity(arr);
	for (int i = 0; i < res.size() - 1; i++){
		cout << res[i] << " ";
	}
	cout << res[res.size() - 1] << endl;
	system("pause");
	return 0;
}