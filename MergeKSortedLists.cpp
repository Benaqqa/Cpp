#include<iostream>
#include<vector>
#include<unordered_map>
#include<tuple>
#define pb push_back
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* tail = nullptr; 
        ListNode* head = nullptr;
        bool r = true;
        while(r == true){
            r = false;
            vector<int> compareint;
            vector<int> comparenode;
            for(int i =0;i<lists.size();i++){
                ListNode* node = lists[i];
                if (node==nullptr){
                    continue;
                }else{
                    r = true;
                    compareint.pb(node->val);
                    comparenode.pb(i);
                }
            }
            int m=-1000000;
            int i = NULL;
            for(int j=0;j<compareint.size();j++){
                if(compareint[j]<m){
                    m=compareint[j];
                    i=j;
                }
            }
            ListNode* newnode = new ListNode(m);
            if (head == nullptr) {
                head = newnode;
                tail = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
            lists[i] = lists[i]->next;
            
        }
        return head; 
        
    }
};



