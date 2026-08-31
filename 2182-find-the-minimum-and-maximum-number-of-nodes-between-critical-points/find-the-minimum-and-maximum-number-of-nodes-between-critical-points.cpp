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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int>critical;
        // if(head==NULL || head->next==NULL || head->next->next==NULL){
        //     return {-1,-1};
        // }

        ListNode* prev=head;
        ListNode* curr=head->next;
        int position=1;
        //int first=-1;

        while(curr->next!=NULL){
            int mid=curr->val;
            int left=prev->val;
            int right=curr->next->val;

            if(mid<left && mid<right || mid>left && mid>right){
                critical.push_back(position);
            }

            prev=curr;
            curr=curr->next;
            position++;     
            
        }
        if(critical.size()<2){
            return {-1,-1};
        }

        int min_dist=INT_MAX;

        for(int i=1;i<critical.size();i++){
            min_dist=min(min_dist,critical[i]-critical[i-1]);
        }

        int max_dist=critical.back()-critical.front();
        return {min_dist,max_dist};
    }
};