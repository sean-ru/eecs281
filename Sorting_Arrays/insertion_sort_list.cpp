#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        while (temp->next != nullptr) {
            ListNode* a = temp->next;  
            while (a) {
                if (temp->val > a->val) {
                    swap(a->val, temp->val);
                }
                a = a->next;
            }
            temp = temp->next;
       } 
        return head;
    }
};