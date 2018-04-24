#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class ClearValue {
public:
    ListNode *clear(ListNode *head, int val) {
        // write code here
        while (head != NULL) {
            if (head->val != val) {
                break;
            }
            head = head->next;
        }
        ListNode *cur = head->next;
        ListNode *pre = head;
        while (cur != NULL) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }

    ListNode *createList(const vector<int> &A) {
        if (A.empty())return nullptr;
        ListNode *phead = new ListNode(A[0]);
        ListNode *pnode = phead;
        for (vector<int>::size_type index = 1; index < A.size(); index++) {
            ListNode *ptmp = new ListNode(A[index]);
            pnode->next = ptmp;
            pnode = ptmp;
        }
        return phead;
    }

    void printList(ListNode *phead) {
        ListNode *p = phead;
        if (p) {
            cout << p->val << endl;
            p = p->next;
            while (p) {
                cout << p->val << endl;
                p = p->next;
            }
        }
        cout << endl;
    }
};

int main() {
    ListNode *p = NULL;
    vector<int> A{1, 2, 3, 4, 5, 6, 7, 8};
    ClearValue CV;
    p= CV.createList(A);
    CV.printList(p);
    p = CV.clear(p,8);
    CV.printList(p);
    return 0;
}