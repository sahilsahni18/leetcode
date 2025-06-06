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
        return addRecursive(l1, l2, 0);
    }

private:
    ListNode* addRecursive(ListNode* l1, ListNode* l2, int carry) {
        // Base case
        if (!l1 && !l2 && carry == 0) {
            return nullptr;
        }

        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        ListNode* node = new ListNode(sum % 10);
        node->next = addRecursive(l1, l2, sum / 10);
        return node;
    }
};