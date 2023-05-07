struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode *next) : val(x), next(next) { }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(0);
        ListNode *cur = res;
        int carry = 0;
        int sum;
        while (l1 || l2){
            sum = carry;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            
        }
        if (carry > 0) {
            cur->next = new ListNode(carry);
        }
        return res->next? res->next : res;
    }
};