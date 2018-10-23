/*
https://leetcode.com/problems/unique-morse-code-words/description/
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string>str = { 
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
	"....", "..", ".---", "-.-", ".-..", "--", "-.",
	"---", ".--.", "--.-", ".-.", "...", "-", 
	"..-", "...-", ".--", "-..-", "-.--", "--.."
};

int uniqueMorseRepresentations(vector<string>& words) {
	if (words.empty()){
		return 0;
	}
	set<string>morseWords;
	for (int i = 0; i < words.size(); i++){
		string temp = "";
		for (int j = 0; j < words[i].size(); j++){
			temp = temp + str[words[i][j] - 'a'];
		}
		morseWords.insert(temp);
	}
	return morseWords.size();
}

int main(){
	vector<string>words = { "gin", "zen", "gig", "msg" };
	cout << uniqueMorseRepresentations(words) << endl;
	system("pause");
	return 0;
}