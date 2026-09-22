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
 class Solution { public: int pairSum(ListNode* head) { if (!head->next->next) { return head->val + head->next->val; } ListNode* slow = head->next; ListNode* fast = head; while (fast && fast->next && fast->next->next) { slow = slow->next; fast = fast->next->next; } // reverse 
 ListNode* prev = NULL;
  ListNode* curr = slow;
   while (curr) {
     ListNode* next = curr->next;
     curr->next = prev; 
     prev = curr; curr = next; } // now add and find max 
     int max = 0; ListNode* revhead = prev; while (head && revhead) { int n = head->val + revhead->val; if (n > max) { max = n; } head = head->next; revhead = revhead->next; } return max; } };