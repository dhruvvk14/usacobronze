//by Dhruv Kothari
#include <iostream>
#include <vector>
#include <set>
using namespace std;
string solve(){
    int n, m;
    cin>>n>>m;
    vector <string> inputs(m);
    vector <char> outputs(m);
    for(int i = 0; i < m; i++)cin>>inputs[i]>>outputs[i];
    vector <bool> didReturn(m);
    for(int i = 0; i < m; i++)didReturn[i] = 0;
    while(1){
        int abcdefg = 0;
        bool isChange = 0;
        for(int i = 0; i < m; i++)if(!didReturn[i])abcdefg++;
        if(abcdefg <= 1)return "OK";
        for(int val = '0'; val <= '1'; val++){
            for(int bit = 0; bit < n; bit++){
                set <char> allOutputs;
                vector <int> validTC;
                for(int testcase = 0; testcase < m; testcase++){
                    if(didReturn[testcase])continue;
                    if(inputs[testcase].at(bit) == val){
                        allOutputs.insert(outputs[testcase]);
                        validTC.push_back(testcase);   
                        //cout<<"HERE"<<endl;
                    }
                }
                if(allOutputs.size() != 2){ // not valid if 0 and 1 is output
                    for(int i : validTC){
                        didReturn[i] = 1;
                        isChange = 1;
                        // cout<<"HERE"<<endl;
                    }
                }
            }
        }
        if(!isChange)break;
    }   
    return "LIE";
}
int main(){
    int t;
    cin>>t;
    while(t--)cout<<solve()<<endl;
}
