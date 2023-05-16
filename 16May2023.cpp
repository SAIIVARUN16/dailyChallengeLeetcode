class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* tempp=head;
        int count=0;
        while(tempp!=NULL){
            count++;
            tempp=tempp->next;
        }
        if(head==NULL || count==1 ) return head;
        ListNode* p;
        p=head;
        ListNode* startnew;
        startnew=p->next;
        ListNode* temp;
        ListNode* q;
        while(true){
            q=p->next;
            temp=q->next;
            q->next=p;
            if(temp==NULL || temp->next==NULL){
                p->next=temp;
                break;
            }
            p->next=temp->next;
            p=temp;
        }
        return startnew;
    }
};