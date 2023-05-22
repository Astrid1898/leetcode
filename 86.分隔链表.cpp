/*
 * @Descripttion: 
 * @version: 
 * @Author: Zhao Jiangfeng
 * @Date: 2021-05-16 23:07:54
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2021-05-18 19:37:24
 */
/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *less = new ListNode();
        ListNode *greater = new ListNode();
        ListNode *lessCur = less;
        ListNode *greaterCur = greater;
        ListNode *cur = head;
        while (cur)
        {
            if (cur->val < x)
            {
                lessCur->next = cur;
                lessCur = lessCur->next;
            }
            else
            {
                greaterCur->next = cur;
                greaterCur = greaterCur->next;
            }
            cur = cur->next;
        }
        lessCur->next = greater->next;
        greaterCur->next = nullptr;
        head = less->next;
        delete less, greater;
        return head;
    }
};
// @lc code=end
