class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int>st;
        int count=0;
        ListNode *temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            count++;
            temp=temp->next;
        }
        int maxi=INT_MIN;
        ListNode *cur=head;
        for(int i=1;i<=count/2;i++){
            maxi=max(maxi,cur->val+st.top());
            st.pop();
            cur=cur->next;
        }
        return maxi;
    }
};