#include <iostream>     // std::cout
#include <algorithm>    // std::count
#include <vector>
using namespace std;
vector<string> all_possible;
string blocks[4];
void recurse(string cur, vector<int> used){
    if(cur.size() == 5) return;
    all_possible.push_back(cur);
    for(int i = 0; i < 4; i++){
        if(count(used.begin(), used.end(), i)){
            // we used this already
            continue;
        }
        for(int character = 0; character < 6; character++){
            vector<int> backup = used;
            backup.push_back(i);
            recurse(cur + blocks[i].at(character), backup);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> blank;
    for(int i=0;i<4;i++)cin>>blocks[i];
    recurse("", blank);
    int one = 0;
    for(int i = 0; i < n; i++){
        string in;
        cin>>in;
        if(count(all_possible.begin(), all_possible.end(), in)){
            cout<<"YES"<<"\n"; // contains it
        }
        else cout<<"NO"<<"\n";
    }
}
