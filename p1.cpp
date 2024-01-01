#include<bits/stdc++.h>
using namespace std;

void reverse(int& count){
    int reverseNum = 0;
    while(count!=0){
        reverseNum = reverseNum * 10 + (count%10);
        count /= 10;
    }
    count = reverseNum;
}

string encode(string s) {     
    if(s.size()==1){
        return s;
    }
    int i=1;
    char ch = s[0];
    int count = 1;
    string r = "";
    while(i < s.size()){
        if(s[i] == ch){
            count++;
        } else {
            r += ch;
            if(count == 1){
                ch = s[i];
                i++;
                continue;
            }
            while(count!=0){
                r += (char)((count%10)+'0');
                count /= 10;
            }
            ch = s[i];
            count = 1;
        }
        i++;
    }
    r += ch;
    if(count > 1){
        while(count!=0){
            r += (char)((count%10)+'0');
            count /= 10;
        }
    }
    int k = 1;
    int j = k;
    while(j < r.size()){
        if(isdigit(r[j])){
            j++;
        } else {
            reverse(r.begin()+k,r.begin()+j);
            j++;
            k = j;
        }
    }
    reverse(r.begin()+k,r.begin()+j);
    return r;
}     

int main(){
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        cout << encode(s) << "\n";
    }
    return 0;
 }
