#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class KInverse {
public:
    ListNode *inverse(ListNode *head, int k) {
        // write code here
        if (k < 2) return head;
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *start = NULL;
        ListNode *next = NULL;
        int count = 1;
        while (cur != NULL) {
            next = cur->next;
            if (count == k) {
                if(pre == NULL){
                    start = head;
                    head = cur;
                }else{
                    start = pre->next;
                    head;
                }

                count = 0;
            }
            count ++;
            cur = next;
        }
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

    return 0;
}