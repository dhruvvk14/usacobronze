#include <iostream>
using namespace std;
int main(){
    char correct[3][3];
    int correct_letters[26]; // letter counter
    int wrong_letters[26]; // letter counter
    for(int i=0;i<26;i++)correct_letters[i]=0, wrong_letters[i]=0;
    char wrong[3][3];
    int n = 3;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){cin>>correct[x][y];
        correct_letters[correct[x][y] - 'A']++; //update
        }
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){cin>>wrong[x][y];wrong_letters[wrong[x][y]-'A']++;} //update
    }
    int green = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(wrong[x][y]==correct[x][y]){green++;
            correct_letters[correct[x][y] - 'A']--; //green letters can't be in yellow
            wrong_letters[correct[x][y] - 'A']--;} //green letters can't be in yellow
        }
    }
    int yellow = 0;
    for(int i=0;i<26;i++){
        yellow += min(correct_letters[i], wrong_letters[i]);// minimum has to be the answer
    }
    cout<<green<<"\n"<<yellow<<endl;
}