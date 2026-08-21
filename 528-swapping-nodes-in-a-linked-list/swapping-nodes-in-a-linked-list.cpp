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
    ListNode* swapNodes(ListNode* head, int k) {
     ListNode*temp=head;
     int count=1;
     ListNode*first;
     int length=0;
     while(temp!=NULL){
        if(count==k){
         first=temp;
        }
       count++;
       length++;
        temp=temp->next; 
     }
     ListNode*temp2=head;
     int i=length-k;
     while(i!=0){
        temp2=temp2->next;
        i--;
     }
     swap(first->val,temp2->val);
     
        return head;
    }
};