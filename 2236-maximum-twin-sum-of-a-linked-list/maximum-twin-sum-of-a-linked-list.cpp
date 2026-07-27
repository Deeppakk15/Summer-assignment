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
    int pairSum(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast !=NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *second=slow->next;
        slow->next=NULL;
        
      ListNode *forward=NULL;
      ListNode *prev=NULL;
      
      while(second!=NULL){
        forward=second->next;
        second->next=prev;
        prev=second;
        second=forward;
      }
    ListNode *temp1=head;
    ListNode *temp2=prev;
    int maxsum=0;
    int sum=0;
    while(temp1!=NULL && temp2!=NULL){
       sum=temp1->val+temp2->val;
       maxsum=max(maxsum,sum);
       temp1=temp1->next;
       temp2=temp2->next;
    }

return maxsum;
    }
};
