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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode();
        ListNode* ptr = ret;
        int carry = 0;
        do {
            int val = carry;
            if (l1 != nullptr) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                val += l2->val;
                l2 = l2->next;
            }
            carry = val / 10;
            val %= 10;
            ptr = ptr->next = new ListNode(val);
        } while (l1 != nullptr || l2 != nullptr || carry != 0);
        
        return ret->next;
    }
};
