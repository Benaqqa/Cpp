#include<unordered_map>
#include<cmath>
#include<vector>
#include<iostream>
#include<typeinfo>
using namespace std;
#define pb push_back





class Solution {
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> ara1;

        int max = 0;

        for (int i =0;i<arr1.size();i++){
            string a = to_string(arr1[i]);
            for (int i =0;i<a.size();i++){
                string sub = a.substr(0,i+1);
                if (ara1.find(sub) == ara1.end()) {
                    ara1[sub]=1;
                }
            }
        }

        for (int i =0;i<arr2.size();i++){
            string a = to_string(arr2[i]);
            for (int i =0;i<a.size();i++){
                string sub = a.substr(0,i+1);
                if (ara1.find(sub) == ara1.end()) {
                    break;
                }
                else if(ara1[sub]==1){
                    cout<<sub<<endl;
                    ara1[sub]==2;
                    if (max<i+1){
                        max=i+1;
                    }
                }
            }
        }
        
        
        return max;
    }
};


int main(){
    Solution sol;
    vector<int> arr1 = {1,2,3};
    vector<int> arr2 = {4,4,4};
    cout<< sol.longestCommonPrefix(arr1,arr2)<<endl;
    return 1;
}