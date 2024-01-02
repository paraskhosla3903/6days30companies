#include<bits/stdc++.h>
using namespace std;


vector<int> findTwoElement(vector<int> arr, int n) {
    vector<int> res;
    unordered_map<int,int> freq;
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    int r,m;
    for(int i=1;i<=n;i++){
        if(freq[i]==2){
            r = i;
        } else if(freq[i]==0){
            m = i;
        }
    }
    res.push_back(r);
    res.push_back(m);
    return res;
}

int main(){
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==1){
            cout<<"Insufficient Elements\n";
            continue;
        }
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> res = findTwoElement(arr,n);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}