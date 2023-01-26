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

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    static ListNode* lastAssignedNode;

    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto* head = new ListNode();
        lastAssignedNode = head;
        addTwoNumbersHelper(l1, l2, 0, head);
        return head;
    }

    static void addTwoNumbersHelper(ListNode* l1, ListNode* l2, int carry, ListNode* currentDigit)
    {
        if (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum > 9 ? 1 : 0;
            int digit = sum % 10;
            currentDigit->val = digit;
            currentDigit->next = new ListNode();
            lastAssignedNode = currentDigit;
            return addTwoNumbersHelper(l1->next, l2->next, carry, currentDigit->next);
        }
        if (l1 == nullptr && l2 == nullptr)
        {
            if (carry != 0)
            {
                currentDigit->val = carry;
            }
            else
            {
                // delete lastAssignedNode->next;
                lastAssignedNode->next = nullptr;
            }
            return;
        }
        if (l1 == nullptr)
        {
            int sum = l2->val + carry;
            carry = sum > 9 ? 1 : 0;
            int digit = sum % 10;
            currentDigit->val = digit;
            currentDigit->next = new ListNode();
            lastAssignedNode = currentDigit;
            return addTwoNumbersHelper(nullptr, l2->next, carry, currentDigit->next);
        }
        if (l2 == nullptr)
        {
            int sum = l1->val + carry;
            carry = sum > 9 ? 1 : 0;
            int digit = sum % 10;
            currentDigit->val = digit;
            currentDigit->next = new ListNode();
            lastAssignedNode = currentDigit;
            return addTwoNumbersHelper(l1->next, nullptr, carry, currentDigit->next);
        }
    }
};

ListNode* Solution::lastAssignedNode = nullptr;

int main()
{
    // [2,4,3] + [5,6,4] = [7,0,8]
    auto* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    auto* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    auto* ans = Solution::addTwoNumbers(l1, l2);
    return 0;
}
