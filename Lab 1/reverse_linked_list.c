#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};




struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* rhead = NULL;
    struct ListNode* tmp = head;

    while (tmp != NULL) {
        struct ListNode* nextNode = tmp->next;
        tmp->next = rhead;
        rhead = tmp;
        tmp = nextNode;
    }

    return rhead;
}