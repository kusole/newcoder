#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Common {
public:
    vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
        // write code here
        ListNode *maxhead = NULL;
        ListNode *maxtail = NULL;
        ListNode *minhead = NULL;
        ListNode *mintail = NULL;
        ListNode *pnext = NULL;
        while (head) {
            pnext = head->next;
            head->next = NULL;
            if (head->val <= val) {
                if (minhead == NULL) {
                    minhead = head;
                    mintail = head;
                } else {
                    mintail->next = head;
                    mintail = head;
                }
            } else {
                if(maxhead == NULL){
                    maxhead = head;
                    maxtail = head;
                }else{
                    maxtail->next = head;
                    maxtail = head;
                }
            }
            head = pnext;
        }
        if(mintail !=NULL)
            mintail->next = maxhead;
        return minhead!=NULL? minhead: maxhead;
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
    vector<int> A{1,2,3,4,5,6,7};
    vector<int> B{2,4,6,8,10};
    vector<int> C;
    Common ld;
    ListNode *p1 = NULL;
    ListNode *p2 = NULL;
    p1=ld.createList(A);
    p2=ld.createList(B);

    C = ld.findCommonParts(p1,p2);
    for(auto i::C){
        cout << i;
    }
    return 0;
}