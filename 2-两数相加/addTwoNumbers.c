 #include<stdio.h>
 
 struct ListNode {
     long long val;
     struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->val = 0;
    result->next = NULL;
    struct ListNode* tmp = result;
    int sumL1 = 0, sumL2 = 0;
    int tmpSum;
    int cout = 0, cin = 0;
    while(l1 != NULL && l2 != NULL) {
        sumL1 = l1->val; sumL2 = l2->val;
        if(cin + sumL1 + sumL2 >= 10) {
            cout = 1;
            tmpSum = (cin + sumL1 + sumL2) % 10;
        } else {
            cout = 0;
            tmpSum = cin + sumL1 + sumL2;
        }
        cin = cout;
        tmp->val = tmpSum;
        if(l1->next != NULL || l2->next != NULL) {
            tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            tmp->next->val = 0; tmp->next->next = NULL;
            tmp = tmp->next;
        } else {
            tmp->next = NULL;
        }
        l1 = l1->next; l2 = l2->next;
    }
    if(l1 != NULL) {
        while(l1 != NULL) {
            sumL1 = l1->val + cin;
            if(sumL1 >= 10) {
                cout = 1;
                sumL1 %= 10;
            } else {
                cout = 0;
            }
            tmp->val = sumL1;
            cin = cout;
            if(l1->next != NULL) {
                tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next->val = 0; tmp->next->next = NULL;
                tmp = tmp->next;
            } else {
                tmp->next = NULL;
            }
            l1 = l1->next;
        }
    } else if(l2 != NULL) {
        while(l2 != NULL) {
            sumL2 = l2->val + cin;
            if(sumL2 >= 10) {
                cout = 1;
                sumL2 %= 10;
            } else {
                cout = 0;
            }
            tmp->val = sumL2;
            cin = cout;
            if(l2->next != NULL) {
                tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next->val = 0; tmp->next->next = NULL;
                tmp = tmp->next;
            } else {
                tmp->next = NULL;
            }
            l2 = l2->next;
        }
    } 
    if (cin) {
        tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->next->val = 0; tmp->next->next = NULL;
        tmp = tmp->next;
        tmp->val = 1;
    } 
    return result;
}

int main() {
    return 0;
}