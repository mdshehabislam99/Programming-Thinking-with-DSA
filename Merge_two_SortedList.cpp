
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int val) {
        this->val = val;
        next = nullptr;
    }

    ListNode(int val, ListNode* next) {
        this->val = val;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        return dummy.next;
    }
};

void display(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
     ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);


    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution obj;

    ListNode* result = obj.mergeTwoLists(list1, list2);

    cout << "Merged linked list: ";
    display(result);

    return 0;
}
