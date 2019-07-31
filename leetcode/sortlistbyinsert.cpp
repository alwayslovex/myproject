/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Sort a linked list using insertion sort.
 //用插入法进行排序，那么就是取一个，放到另外一个的合适位置
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode tmp(0);
        if(head == nullptr){
            return head;
        }
        while(head != nullptr){
            ListNode * pre = &tmp;
            //寻找合适的位置，插入
            while(pre->next != nullptr){
                if(head->val > pre->next->val){
                    pre = pre->next;
                }else{
                    ListNode * tail = head->next;
                    head->next = pre->next;
                    pre->next = head;
                    head = tail;
                    break;
                }
            }
            if(pre->next == nullptr)
            {
                pre->next = head;
                head = head->next;
                pre->next->next = nullptr;//断开原来的链
            }
        }
        return tmp.next;
    }
};
