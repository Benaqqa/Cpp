#include<string>
#include<vector>
#include<iostream>
#include<typeinfo>
using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    string re;
    int minsize = 300;
    for (int i=0;i<strs.size();i++){
        if (strs[i].size()<minsize){
            minsize = strs[i].size();
        }
    }
    
    for (int j=0;j<minsize;j++){
        char currentchar = strs[0][j];
        
        bool equals = true;
        for (int i=0;i<strs.size();i++){
            if (!equals){
                break;
            }
            if (strs[i][j]!=currentchar){
                equals = false;
            }    

        }   
        if (!equals){
            break;
        }    
        re.push_back(currentchar);
    }
    return re; 

}
    


int main(){
    
    vector<string> strs;
    string temp;
    while (cin >> temp) {
        strs.push_back(temp);
    }
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
};