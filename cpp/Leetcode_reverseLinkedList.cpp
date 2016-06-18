// Leetcode_reverseLinkedList.cpp

#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
	ListNode(int x,ListNode *next): val(x),next(next){}
};

ListNode* reverseList(ListNode* head){
	ListNode *right,*left,*temp;
	right = left = head;
	if(head == NULL)
		return NULL;
	while((*left).next != NULL){
		temp = right;
		right = (*left).next;
		(*left).next = (*right).next;
		(*right).next = temp;
	}
	return right;
}

int main(){
	ListNode node6(0);
    ListNode node5(1,&node6);
    ListNode node4(1,&node5);
    ListNode node3(4,&node4);
	ListNode node2(3,&node3);
	ListNode node1(1,&node2);
	ListNode *head = &node1;
	head = reverseList(head);
	while(head != NULL){
		cout << (*head).val << endl;
		head = (*head).next;
	}
	return 0;
}