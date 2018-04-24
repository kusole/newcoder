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
        ListNode *cur = head;//当前值，循环为每一个区段的最后一个值
        ListNode *pre = NULL;//当前区间的前一个值
        ListNode *start = NULL;//当前区间的开始值
        ListNode *next = NULL;//当前值的下一个值，循环为每一个区段的后一个值
        int count = 1;
        while (cur != NULL) {
            next = cur->next;//记录当前值的下一个值，用于循环进行
            if (count == k) {
                start = pre == NULL ? head : pre->next;//如果pre为空，则start为head，否则为pre的next；
                head = pre == NULL ? cur : head;//如果pre为空，head为第一次逆序的头一个值，即为逆序前的最后一个值cur；否则保持head
                resign(pre, start, cur, next);//逆序
                pre = start;//下一个区段的pre为当前区段的start；
                count = 0;
            }
            count++;
            cur = next;
        }
        return head;
    }

    void resign(ListNode *left, ListNode *start, ListNode *end, ListNode *right) {
        ListNode * pre = start;//pre为开始值
        ListNode * cur = start->next;//cur为开始值的next；
        ListNode * next = NULL;
        while(cur != right){
            next = cur->next;//保存cur的next；用于循环
            cur ->next = pre;//当前值的下一个值为前驱节点pre
            pre = cur;//前驱节点调到cur
            cur = next;
        }
        if(left != NULL)//如果存在前段区间，则将前段区间的后一个值为end；
            left -> next = end;
        start->next = right;//start变为当前区段的最后一个值，next指向right；
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
    vector<int> A{1,2,3,4,5,6,7,8};
    KInverse ki;
    p = ki.createList(A);
    ki.printList(p);
    p = ki.inverse(p, 3);
    ki.printList(p);
    return 0;
}