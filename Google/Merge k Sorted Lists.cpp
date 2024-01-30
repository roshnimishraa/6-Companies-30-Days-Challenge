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
struct MyCmp{
    bool operator() (ListNode *a,ListNode *b)
    {
        // [3,5,7] [6,8,10]
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
//   Min-Heap
    priority_queue<ListNode*,vector<ListNode*>,MyCmp> pq;
    int n = lists.size();
for(int i=0;i<n;i++){
    if(lists[i] != NULL)
        pq.push(lists[i]);
}
ListNode *head = NULL;
ListNode *tail = NULL;

while(!pq.empty())
{
    ListNode *node = pq.top();
    pq.pop();

    if(head == NULL){
        head = node;
        tail = node;
    }
    else{
        // 5-> 6
        tail->next = node;
        tail = node;
    }
    if(node->next != NULL)
    {
        pq.push(node->next);
    }
}
return head;
    }
};
