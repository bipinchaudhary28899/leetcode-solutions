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
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || head->next==NULL) return true;

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* first = head;
        ListNode* second = reverse(slow->next);

        while(second){
            if(first->val != second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};