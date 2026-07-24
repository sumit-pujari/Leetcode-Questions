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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        int n=1;
        ListNode* last=head;
        while(last->next!=NULL){
            n++;
            last=last->next;
        }

        k=k%n;
        if(k==0) return head;

        int c=n-k;
        ListNode *t=head;
        int count=1;
        while(t){
            if(count==c) break; 
            count++;
            t=t->next;
        }
        ListNode* result=t->next;
        last->next=head;
        t->next=NULL;
        return result;
    }
};