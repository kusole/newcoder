#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class InsertValue {
public:
    ListNode *insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
        ListNode *phead = createList(A, nxt);
        if (!phead) {
            phead = new ListNode(val);
            phead->next = phead;
            return phead;
        }
        ListNode *pnode = phead;
        while (val > pnode->val) {
            pnode = pnode->next;
            if (pnode == phead)break;
        }
        ListNode *ptep = new ListNode(pnode->val);
        ptep->next = pnode->next;
        pnode->next = ptep;
        pnode->val = val;
        if (phead == pnode) return (pnode->val > ptep->val ? ptep : phead);
        else return phead;

    }

    ListNode *createList(const vector<int> &val, const vector<int> &nxt) {
        if (val.empty() || nxt.empty() || val.size() != nxt.size())
            return nullptr;
        ListNode *head = new ListNode(val[0]);
        ListNode *node = head;
        vector<int>::size_type index = 0;
        for (index = 0; index < nxt.size(); index++) {
            node->next = new ListNode(val[nxt[index]]);
            node = node->next;
        }
        node->next = head->next;
        ListNode *p = head;
        head = node;
        delete p;
        return head;
    }

    void printList(const ListNode *head) {
        ListNode *p;
        if (head) {
            cout << head->val << endl;
            for (p = head->next; p != head; p = p->next) {
                cout << p->val << endl;
            }
        }
    }

};

int main() {
    vector<int> A = {1, 3, 4, 5, 7};
    vector<int> nxt = {1, 2, 3, 4, 0};
    ListNode *p = nullptr;
    InsertValue ins;
    p = ins.insert(A, nxt, 0);
    ins.printList(p);
    return 0;
}