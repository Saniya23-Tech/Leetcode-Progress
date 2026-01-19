#include <iostream>
using namespace std;


class ListNode {
    public:
    int val;
    ListNode* next;
     
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};
class Solution {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next; //store next node
            curr-> next =prev; //reverse the link

            prev = curr; // move prev
            curr = next; // move curr
        }

        return prev;
    }

};

void printList(ListNode* head) {
    ListNode* temp = head;
    while(temp!= NULL) {
        cout << temp-> val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {

    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);


    Solution s1;
    head = s1.reverseList(head);

    cout << "Reverse Linked List:";
    printList(head);

    return 0;
    
}