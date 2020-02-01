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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode * p1 = head;
        ListNode * p2 = head;
        ListNode * h1 = head;
        ListNode nhead(0);//用来翻转起始的头
        nhead.next = head;
        int i = 1;
        if(head == nullptr) return head; 
        for(;i < m && p1 != nullptr;++i){
            nhead.next = p1;
            p1 = p1->next;
        }
        if(p1 == nullptr){
            return head;
        }
        h1 =p1;
        p2 = p1->next;
        for(;i < n && p2 != nullptr;++i){
            auto p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        h1->next = p2;
        if(m == 1){//对于从起始位置翻转的
            nhead.next = p1;
            return nhead.next;
        }else{
            nhead.next->next = p1;
        }
        return head;
    }
};
