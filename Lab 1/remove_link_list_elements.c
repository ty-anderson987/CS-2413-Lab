#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};




struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode tmp_start;
    tmp_start.next = head;
    struct ListNode* tmp = &tmp_start;


    while (tmp->next != NULL) {
        if ((tmp->next)->val == val) {
            struct ListNode* deleteNode = tmp->next;
            tmp->next = (tmp->next)->next;
            free(deleteNode);
        } else {
            tmp = tmp->next;
        }
    }

    head = tmp_start.next;

    return head;
}