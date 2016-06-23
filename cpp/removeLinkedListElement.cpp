// Leetcode_removeLinkedListElement.cpp

#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
	ListNode(int x,ListNode *next): val(x),next(next){}
};

ListNode* removeElements(ListNode* head, int val){
	ListNode viHead(0);
	viHead.next = head;
	ListNode *cur = head;
	ListNode *fcur = &viHead;
	while(cur != NULL){
		if((*cur).val == val){
			(*fcur).next = (*cur).next;
			cur = (*cur).next;
		}
		else{
			fcur = cur;
			cur = (*cur).next;
		}
	}
	return viHead.next;
}

int main(){
	ListNode node6(0);
    ListNode node5(1,&node6);
    ListNode node4(1,&node5);
    ListNode node3(4,&node4);
	ListNode node2(3,&node3);
	ListNode node1(1,&node2);
	ListNode *head = &node1;
	head = removeElements(head,1);
	while(head != NULL){
		cout << (*head).val << endl;
		head = (*head).next;
	}
	return 0;
}