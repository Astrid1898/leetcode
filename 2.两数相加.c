/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *ans = NULL;
    struct ListNode *pre = NULL;
    int sign = 0, count = 1;
    while (l1 && l2)
    {
        struct ListNode *t = malloc(sizeof(struct ListNode));
        int sum = l1->val + l2->val;
        if (sign)
        {
            sum = sum + 1;
            sign = 0;
        }
        if (sum > 9)
        {
            sum = sum - 10;
            sign = 1;
        }
        if (count)
        {
            ans = pre = t;
            count--;
        }
        else
        {
            pre->next = t;
            pre = pre->next;
        }
        t->val = sum;
        t->next = NULL;
        l1 = l1->next;
        l2 = l2->next;
        t = t->next;
    }
    while (l1)
    {
        struct ListNode *t = malloc(sizeof(struct ListNode));
        int sum = l1->val;
        if (sign)
        {
            sum = sum + 1;
            sign = 0;
        }
        if (sum > 9)
        {
            sum = sum - 10;
            sign = 1;
        }
        if (count)
        {
            ans = pre = t;
            count--;
        }
        else
        {
            pre->next = t;
            pre = pre->next;
        }
        t->val = sum;
        t->next = NULL;
        l1 = l1->next;
        t = t->next;
    }
    while (l2)
    {
        struct ListNode *t = malloc(sizeof(struct ListNode));
        int sum = l2->val;
        if (sign)
        {
            sum = sum + 1;
            sign = 0;
        }
        if (sum > 9)
        {
            sum = sum - 10;
            sign = 1;
        }
        if (count)
        {
            ans = pre = t;
            count--;
        }
        else
        {
            pre->next = t;
            pre = pre->next;
        }
        t->val = sum;
        t->next = NULL;
        l2 = l2->next;
        t = t->next;
    }
    if (sign)
    {
        struct ListNode *t = malloc(sizeof(struct ListNode));
        if (count)
        {
            ans = pre = t;
            count--;
        }
        else
        {
            pre->next = t;
            pre = pre->next;
        }
        t->val = 1;
        t->next = NULL;
    }
    return ans;
}
// @lc code=end
