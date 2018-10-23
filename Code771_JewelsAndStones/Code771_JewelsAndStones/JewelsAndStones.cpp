/*
https://leetcode.com/problems/jewels-and-stones/description/
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int numJewelsInStones(string J, string S) {
	if (J.size() == 0 || S.size() == 0){
		return 0;
	}
	int num = 0;
	for (int i = 0; i < J.size(); i++){
		int pos = S.find(J[i], 0);
		while (pos != string::npos){
			num++;
			pos = S.find(J[i], pos + 1);
		}
	}
	return num;
}

int main(){
	string J, S;
	cin >> J >> S;
	int num = numJewelsInStones(J, S);
	cout << num << endl;
	system("pause");
	return 0;
}