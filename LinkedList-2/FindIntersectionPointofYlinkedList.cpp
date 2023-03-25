class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     
         while(headA!=NULL){
             ListNode *temp=headB;
            while(temp!=NULL)
            {
                if(headA==temp)
                {
                    return headA;

                }
                temp=temp->next;
            }
            headA=headA->next;
        }



        return NULL;
    }
    
};    
    