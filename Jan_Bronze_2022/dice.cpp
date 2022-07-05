#include <iostream>
using namespace std;
string win(int a[], int b[]){
    int n = 4;
    int a_win=0, b_win=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t1 = a[i];
            int t2 = b[j];
            if(t1>t2)a_win++;
            if(t1<t2)b_win++;
        }
    }
    // cout<<a_win<<" "<<b_win<<endl;
    if(a_win==b_win)return "tie";
    if(a_win>b_win)return "f";
    return "s";
}
void solve(){
    int n = 4;
    int a[4], b[4];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int n1=1;n1<=10;n1++){
        for(int n2=1;n2<=10;n2++){
            for(int n3=1;n3<=10;n3++){
                for(int n4=1;n4<=10;n4++){
                    int c[] = {n1,n2,n3,n4};
                    if(win(a,b) == "f" && win(a,c) == "s" && win(b,c)=="f"){cout<<"yes"<<endl; return;}
                    if(win(a,b) == "s" && win(a,c) == "f" && win(b,c) == "s"){cout<<"yes"<<endl; return;}
                }
            }
        }
    }
    cout<<"no"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    // int a[] = {4,5,6,7};
    // int b[] = {2,4,5,10};
    // int c[] = {1,4,8,9};
    while(t--){solve();}
}