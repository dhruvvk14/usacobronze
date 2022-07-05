//by Dhruv Kothari
#include <iostream>
#include <vector>
using namespace std;
vector <int> recipes[100];
int a[100];
bool possible=1;
int n;
void craft(int node){
    if(!possible)return;
    else if(a[node]!=0&&node!=n-1){a[node]--;} // we already have the ingredient
    else if(a[node]==0&&recipes[node].size()==0){possible=0;}//impossible ( no crafting recipe and no ingredient)
    else{
        for(int i:recipes[node]){craft(i);} // craft other metals
    }
}
int main(){
    int k;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>k;
    for(int f=0;f<k;f++){
        int metals, amt;
        cin>>metals>>amt, metals--;
        for(int i=0;i<amt;i++){
            int a;
            cin>>a;
            recipes[metals].push_back(a-1); //construct recipes
        }
    }
    while(1){
        craft(n-1); // craft highest metal
        if(!possible)break; 
        a[n-1]++; 
    }
    cout<<a[n-1]<<endl;
}
