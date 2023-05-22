/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode *ptrToNode;

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
    ptrToNode tmp = head, tail = head;
    int cnt = 0;
    while (tmp)
    {
        cnt++;
        tail = tmp;
        tmp = tmp->next;
    }
    k = k % cnt;
    if (k == -0 || k == cnt)
        return head;
    ptrToNode pre = head, newHead = head;
    int move = cnt - k - 1;
    while (move--)
    {
        pre = pre->next;
    }
    newHead = pre->next;
    tail->next = head;
    pre->next = NULL;
    return newHead;
}
// @lc code=end
