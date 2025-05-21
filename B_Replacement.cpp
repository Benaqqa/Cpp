#include <vector>
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int _=0;_<t;_++){
        int n;
        cin>>n;
        vector<char> s;
        vector<char> r;
        
        while (char c = getchar()!= EOF){
            s.push_back(c);
        }
        while (char c = getchar()!= EOF){
            r.push_back(c);
        }
        for (int i=0;i<s.size();i++){
            cout<<s[i];
        }
        cout<<' '<<endl;
        for (int i=0;i<r.size();i++){
            cout<<r[i];
        }
        int index=0;
        /*
        for (int i=0;i<n-1;i++){
            int j=index;
            while(j<s.size()){
                if (s[j]!=s[j+1]){

                }
            }
        }*/
    }
}