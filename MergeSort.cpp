#include<bits/stdc++.h>
using namespace std;

class ListNode {
      int val;
    ListNode *next;
     ListNode() {}
     ListNode(int val) { this->val = val; }
     ListNode(int val, ListNode *next) { this->val = val; this->next = next; }
  };

public:
class Solution {
   public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
    
    if(list2==nullptr) return list1;
    if(list1==nullptr) return list2;
    
    if(list1->val < list2->val) {
        return mergeTwoListsUtil(list1, list2);
    }
    return mergeTwoListsUtil(list2, list1);
}

 public ListNode mergeTwoListsUtil(ListNode list1, ListNode list2) {
            
    ListNode curr1 = list1;
    ListNode curr2 = list2;
    ListNode next1 = list1->next;
    ListNode next2 = list2->next;
    
    while(next1!= nullptr && curr2!=nullptr) {
        
        if(curr1->val <= curr2->val && curr2->val <= next1->val) {

            ListNode next_curr2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr2  = next_curr2;                
            curr1 = curr1->next;
            next1 = curr1->next;
        } 
        else {
            curr1 = curr1->next;
            next1 = next1->next;
        }
    }
     
     if(curr2!=nullptr) {
         curr1->next = curr2;
     }
     
     return list1;
 }
 };

int main()
{
   
    
    return 0;
}
