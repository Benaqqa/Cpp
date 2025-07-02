#include<iostream>
#include<vector>
#include<deque>
#include<cmath>
#define pb push_back
#define pf push_front
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int first=0;
        int carry =0;
        int second=0;
        ListNode* tail = nullptr; 
        ListNode* head = nullptr;
        bool L1 = true;
        bool L2 = true;

        while (L1 || L2){
        
            if(L1 && L2){
                int res = l1->val+l2->val + carry;
                carry = 0;
                if (res>9){
                    res = res - 10;
                    carry = 1;
                }

                ListNode* newNode = new ListNode(res);

                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
                if (l1->next != nullptr){
                    l1 = l1->next;
                }else{
                    L1 = false;
                }
                if (l2->next != nullptr){
                    l2 = l2->next;
                }else{
                    L2 = false;
                }

            }else if (L1 == false){
                int res = l2->val + carry;
                carry = 0;
                if (res>9){
                    res = res - 10;
                    carry = 1;
                }

                ListNode* newNode = new ListNode(res);

                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
                if (l2->next != nullptr){
                    l2 = l2->next;
                }else{
                    L2 = false;
                }
            }else if (L2 == false){
                int res = l1->val+ carry;
                carry = 0;
                if (res>9){
                    res = res - 10;
                    carry = 1;
                }

                ListNode* newNode = new ListNode(res);

                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
                if (l1->next != nullptr){
                    l1 = l1->next;
                }else{
                    L1 = false;
                }
            }
            

        }
        if (carry ==1){
                ListNode* newNode = new ListNode(1);

                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
        }
        
        
               
        return head;
    }
};

main(){

}