/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode *preHead = malloc(sizeof(struct ListNode));
    preHead->val = -1;
    preHead->next = head;
    struct ListNode *this = head;
    struct ListNode *pre = preHead;
    struct ListNode *behind = preHead;
    while (this && this->next)
    {
        behind = this->next->next;
        pre->next = this->next;
        pre->next->next = this;
        this->next = behind;
        pre = this;
        this = this->next;
    }

    return preHead->next;
}
// @lc code=end
