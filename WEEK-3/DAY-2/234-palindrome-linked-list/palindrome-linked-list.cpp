/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
      }
    ListNode* prev=NULL;
    ListNode* currnt=slow;
      ListNode* forward=NULL;
    while(currnt!=NULL){
         forward=currnt->next;
         currnt->next=prev;
         prev=currnt;
         currnt=forward;
    }
    ListNode*check=prev;
    ListNode*temp=head;
    while(check!=NULL){
        if(check->val==temp->val){
            check=check->next;
            temp=temp->next;
        }
        else{
            return false;
        }
    }
    return true;
    }
};