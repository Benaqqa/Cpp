#include<tuple>
#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
using namespace std;
#define pb push_back


//idea two pointers (sliding window)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> sol;
        int max = 0;
        int size = s.size();
        for (int i = 0;i<size;i++){
            char c = s[i];
            unordered_map<char, int> copy;
            string mini = s.substr(i,size);
            sol.pb(0);
            for (char r:mini){
                if(copy.find(r) == copy.end()){
                    copy[r]=1;
                    sol[i]++;
                    if (max<sol[i]){
                        max = sol[i];
                    }
                }else{
                    if (max<sol[i]){
                        max = sol[i];
                    }
                    break;
                }
            }

        }
        
        
        

        
        /*
        int n = 0;
        int size = s.size();
        cout<<"size: "<<size<<endl;
        int i = 0;
        while(i<size){
            char c = s[i];
            
            if (copy[c]==-1){
                cout<<"if c:"<<c<<" i: "<<i<<endl;
                copy[c] = i;
                n++;
                
                if (max<n){
                    max = n;
                }
                i++;
            }
            else{
                cout<<"else c:"<<c<<" i: "<<i<<" cout[c]: "<<copy[c]<< endl;
                if (max<n){
                    max = n;
                }
                n = 0;
                i = copy[c]+1;
                cout<<"i updated :"<<i<<endl;
                copy = init;
                
            }
        }
            */
        return max;
    }
};



main(){
    Solution sol;
    string s = "abcabcbb";
    cout<<sol.lengthOfLongestSubstring(s)<<endl;
}