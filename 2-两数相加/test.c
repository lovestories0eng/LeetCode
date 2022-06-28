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
    struct ListNode* end;

    int sumL1 = 0, sumL2 = 0;
    int tmpSum;

    int flag = 1;
    int cout = 0, cin = 0;
    while(1) {
        if(!flag) break;
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
        printf("%d ", tmpSum);
        end = tmp;
        // 有进位或者和不为零
        if(cin || tmpSum) {
            tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            tmp->next->val = 0; tmp->next->next = NULL;
            tmp = tmp->next;
        } else {
            tmp->next = NULL;
        }

        if(l1->next == NULL || l2->next == NULL) 
            flag = 0;
        l1 = l1->next; l2 = l2->next;
    }

    flag = 1;

    if(l1 != NULL) {
        while(1) {
            if(!flag) break;
            sumL1 = l1->val + cin;
            if(sumL1 >= 10) {
                cout = 1;
                sumL1 = sumL1 % 10;
            } else {
                cout = 0;
            }

            tmp->val = sumL1;
            cin = cout;
            if(cin || sumL1) {
                tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next->val = 0; tmp->next->next = NULL;
                tmp = tmp->next;
            } else {
                tmp->next = NULL;
            }
            if(l1->next == NULL) flag = 0;
            l1 = l1->next;
        }
    } else if(l2 != NULL) {
        while(1) {
            if(!flag) break;
            sumL2 = l2->val + cin;
            if(sumL2 >= 10) {
                cout = 1;
                sumL2 = sumL2 % 10;
            } else {
                cout = 0;
            }

            tmp->val = sumL2;
            cin = cout;
            if(cin || sumL2) {
                tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                tmp->next->val = 0; tmp->next->next = NULL;
                tmp = tmp->next;
            } else {
                tmp->next = NULL;
            }
            if(l2->next == NULL) flag = 0;
            l2 = l2->next;
        }
    } else {
        printf("%d ", cin);
        if (cin) {
            tmp->val = 1;
            tmp->next = NULL;
        } else {
            tmp = NULL;
        }
    }
    return result;
}

int main() {
    return 0;
}