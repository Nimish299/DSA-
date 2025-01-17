
#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {

            if (a == NULL)
                a = headB;
            else
                a = a->next;
            if (b == NULL)
                b = headA;
            else
                b = b->next;
        }
        return a;
    }
};