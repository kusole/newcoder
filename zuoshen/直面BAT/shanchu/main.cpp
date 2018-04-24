#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Remove {
public:
    ListNode *removeNode(ListNode *pHead, int delVal) {
        // write code here
        if (!pHead)return pHead;
        if (pHead->val == delVal) {
            ListNode *p = pHead->next;
            pHead->next=NULL;
            delete pHead;
            return p;
        }
        ListNode *cur = pHead->next;
        ListNode *pre = pHead;
        while (cur != NULL) {
            if (cur->val == delVal) {
                pre->next = cur->next;
                cur->next = NULL;
                delete cur;
                break;
            }
            cur = cur->next;
            pre = pre->next;
        }
        return pHead;
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
    vector<int> A{0, 1, 2, 3, 4};
    Remove R;
    ListNode *p = NULL;
    p = R.createList(A);
    R.printList(p);
    p = R.removeNode(p, 0);
    R.printList(p);

    return 0;
}