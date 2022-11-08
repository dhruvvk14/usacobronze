#include <fstream>
#include <vector>
using namespace std;
int main(){
    ifstream cin ("word.in");
    ofstream cout("word.out");
    vector <string> words;
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        string s; cin>>s; words.push_back(s);
    }
    int i = 0;
    while(i < n){
        int used = 0;
        string cur = "";
        while(i < n && used + words[i].size()<= k){
            cur = cur + words[i] + " ";
            used += words[i].size();
            i++;
        }
        cur.pop_back();
        cout<<cur<<endl;
    }
}
