#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& v,vector<int>& pos){
    if(v.size()==0) return 0;
    vector<int> tmp;
    map<int,int> match;
    tmp.push_back(v[0]);
    pos[0]=1;
    match[v[0]]=1;
    for(int i=1;i<v.size();i++){
        int n = v[i];
        if(n>tmp.back()){
            tmp.push_back(n);
            pos[i] = tmp.size();
            match[n]=pos[i];
        }
        else{
            auto it = lower_bound(tmp.begin(),tmp.end(),n);
            pos[i] = match[*it];
            *it = n;
            match[n]=pos[i];
        }
    }
    return tmp.size();
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n){
        vector<int> v(n,0);
        vector<int> pos(n,0);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int len = LIS(v,pos);
        vector<int> ans(len,0);
        cout << len << "\n";
        for(int i=pos.size()-1;i>=0;i--){
            if(pos[i]==len){
                ans[len-1]=i;
                len--;
            }
        }
        for(auto x : ans){
            cout << x << " ";
        }
        cout << "\n";
    }



}
