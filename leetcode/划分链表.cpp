/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

给出一个链表和一个值x，以x为参照将链表划分成两部分，使所有小于x的节点都位于大于或等于x的节点之前。
两个部分之内的节点之间要保持的原始相对顺序

直接划分就行了。
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode left(x);
        ListNode * left_tail = &left;
        ListNode right(x);
        ListNode * right_tail = &right;
        
        while(head != nullptr){
            if(head->val < x){
                left_tail->next = head;
                head = head->next;
                left_tail = left_tail->next;
                left_tail->next = nullptr;
            }else if(head->val >= x){
                right_tail->next = head;
                head = head->next;
                right_tail = right_tail->next;
                right_tail->next = nullptr;
            }
        }
        
        left_tail->next = right.next;
        return left.next;
    }
};
