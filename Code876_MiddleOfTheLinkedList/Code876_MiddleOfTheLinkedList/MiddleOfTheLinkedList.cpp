/*
https://leetcode.com/problems/middle-of-the-linked-list/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr){
			return head;
		}
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr&&fast->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};

int main(){
	ListNode Node1(1), Node2(2), Node3(3), Node4(4), Node5(5), Node6(6);
	Node1.next = &Node2;
	Node2.next = &Node3;
	Node3.next = &Node4;
	Node4.next = &Node5;
	Node5.next = &Node6;
	Solution s;
	ListNode *Node = s.middleNode(&Node1);
	while (Node != nullptr){
		if (Node->next != nullptr){
			cout << Node->val << "->";
		}
		else{
			cout << Node->val;
		}
		Node = Node->next;
	}
	cout << endl;
	system("pause");
	return 0;
}