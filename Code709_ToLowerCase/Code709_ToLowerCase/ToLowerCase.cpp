/*
https://leetcode.com/problems/to-lower-case/description/
*/
#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string str) {
	if (str.size() == 0){
		return str;
	}
	for (int i = 0; i < str.size(); i++){
		if (str[i] >= 'A'&&str[i] <= 'Z'){
			str[i] = str[i] + ('a' - 'A');
		}
	}
	return str;
}

int main(){
	string str;
	cin >> str;
	cout << toLowerCase(str) << endl;
	system("pause");
	return 0;
}