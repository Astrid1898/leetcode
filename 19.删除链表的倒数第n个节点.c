/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    struct ListNode *pre = NULL;
    n--;
    while (n--)
        p1 = p1->next;
    while (p1->next)
    {
        pre = p2;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (pre == NULL && p1 == p2)
        return NULL;
    else if (pre == NULL)
    {
        head = head->next;
        free(p2);
        return head;
    }
    pre->next = p2->next;
    free(p2);
    return head;
}
// @lc code=end
