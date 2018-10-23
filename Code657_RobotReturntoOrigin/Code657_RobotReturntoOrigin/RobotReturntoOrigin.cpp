/*
https://leetcode.com/problems/robot-return-to-origin/description/
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool judgeCircle(string moves) {
	if (moves.empty()){
		return false;
	}

	int numL = count(moves.begin(), moves.end(), 'L');
	int numR = count(moves.begin(), moves.end(), 'R');
	int numU = count(moves.begin(), moves.end(), 'U');
	int numD = count(moves.begin(), moves.end(), 'D');

	if (numL == numR&&numU == numD){
		return true;
	}
	return false;
}

int main(){
	string moves;
	cin >> moves;
	cout << judgeCircle(moves) << endl;
	system("pause");
	return 0;
}