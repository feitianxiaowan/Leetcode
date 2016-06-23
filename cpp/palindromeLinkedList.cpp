// Leetcode_palindromeLinkedList.cpp

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
	ListNode(int x,ListNode *next): val(x),next(next){}
};

bool isPalindrome(ListNode* head){
    ListNode *mid = head;
    ListNode *tail = head;

    if(head == NULL || (*head).next == NULL)
        return true;
    // cout << 2333 << endl;
    int count = 0;
    while(tail != NULL){
    	mid = (*mid).next;
    	tail = (*tail).next;
    	count++;
    	if(tail != NULL)
    		tail = (*tail).next;
    }

    ListNode *right = mid;
    ListNode *left = mid;
    ListNode *temp;
    while((*left).next != NULL){
        temp = right;
        right = (*left).next;
        (*left).next = (*right).next;
        (*right).next = temp;
    }

    bool flag = true;
    ListNode *cursora = head;
    ListNode *cursorb = right;
    while(cursora != NULL && cursorb != NULL){
        if((*cursora).val != (*cursorb).val){
            flag = false;
            break;
        }
        // cout << 2333 << endl;
        cursorb = (*cursorb).next;
        cursora = (*cursora).next;
    }

    return flag;
    // return 0;
}

int main(){
	ListNode node6(0);
    ListNode node5(1,&node6);
    ListNode node4(1,&node5);
    ListNode node3(4,&node4);
	ListNode node2(3,&node3);
	ListNode node1(1,&node2);
	cout << isPalindrome(&node5) << endl;
}