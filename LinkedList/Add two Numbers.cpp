/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *temp = res;
        int len1 = 0, len2=0;
        ListNode *st1 = l1;
        while(st1 != NULL){
            len1++;
            st1=st1->next;
        }
        ListNode *st2 = l2;
        while(st2 != NULL){
            len2++;
            st2=st2->next;
        }
        int carry = 0;
        int c=0;
        while(c<len1 && c<len2){
            int data = l1->val + l2->val + carry;
            carry = data/10;
            ListNode *node = new ListNode(data%10);
            res->next = node;
            res=res->next;
            l1=l1->next;
            l2=l2->next;
            c++;
        }
        if(len1==len2){
            if(carry>0){
                ListNode *node = new ListNode(carry);
                res->next = node;
                res=res->next;
                res->next=NULL;
            }
        }
        else{
            if(len1>len2){
                while(c<len1){
                    int data = l1->val + carry;
                    carry = data/10;
                    ListNode *node = new ListNode(data%10);
                    res->next=node;
                    res=res->next;
                    l1=l1->next;
                    c++;
                }
                if(carry>0){
                    ListNode *node = new ListNode(carry);
                    res->next = node;
                    res=res->next;
                }
                res->next=NULL;
            }
            else{
                while(c<len2){
                    int data = l2->val + carry;
                    carry = data/10;
                    ListNode *node = new ListNode(data%10);
                    res->next=node;
                    res=res->next;
                    l2=l2->next;
                    c++;
                }
                if(carry>0){
                    ListNode *node = new ListNode(carry);
                    res->next = node;
                    res=res->next;
                }
                res->next=NULL;
            }
        }
        return temp->next;
    }
};