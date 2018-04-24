#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Palindrome {
public:
    bool isPalindrome(ListNode *pHead) {
        // write code here
        //方法一：全部压入
//        stack<int> liststack;
//        ListNode *pnode = pHead;
//        while (pnode != NULL) {
//            liststack.push(pnode->val);
//            pnode = pnode->next;
//        }
//        pnode = pHead;
//        while (pnode != NULL) {
//            if (liststack.top() != pnode->val) {
//                return false;
//            };
//            liststack.pop();
//            pnode = pnode->next;
//        }
//        return true;

        //方法二：快慢指针
//        stack<int> liststack;
//        ListNode *pslownode = pHead;
//        ListNode *pfastnode = pHead;
//        int count = 1;
//        while (pfastnode != NULL) {
//            liststack.push(pslownode->val);
//            if (pfastnode->next == NULL)break;
//            if (pfastnode->next->next != NULL) {
//                pfastnode = pfastnode->next->next;
//                pslownode = pslownode->next;
//                count++;
//            } else
//                break;
//        }
//        if(pfastnode->next == NULL)
//            liststack.pop();
//        pslownode = pslownode->next;
//        while(pslownode !=NULL){
//            if(pslownode->val == liststack.top()){
//                pslownode = pslownode->next;
//                liststack.pop();
//            }else return false;
//        }
//        return true;
        //方法三：逆序指针
        ListNode *pslownode = pHead;
        ListNode *pfastnode = pHead;
        ListNode *pnode = pHead;
        while(pfastnode&&pfastnode->next){
            pfastnode = pfastnode->next->next;
            pslownode = pslownode->next;
        }
        ListNode *pre = NULL;
        while(pslownode){
            ListNode *temp = pslownode->next;
            pslownode->next = pre;
            pre = pslownode;
            pslownode = temp;
        }
        while(pre){
            if(pre->val == pnode ->val){
                pre= pre->next;
                pnode = pnode->next;
            }else
                return false;
        }
        return true;
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
    vector<int> A{1, 2, 3, 3, 2, 1};
    Palindrome PD;
    p = PD.createList(A);
    PD.printList(p);
    cout << PD.isPalindrome(p);

    return 0;
}