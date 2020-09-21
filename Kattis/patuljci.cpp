#include <bits/stdc++.h>
using namespace std;

vector<int> res;
void solve(vector<int>&v,vector<int> tmp,int sum,int ind){
    if(sum==100 && tmp.size()==7){
        res=tmp;
        return;
    }
    if(ind >= v.size() || sum>100) return;
    solve(v,tmp,sum,ind+1);
    tmp.push_back(v[ind]);
    solve(v,tmp,sum+v[ind],ind+1);
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    vector<int> v;
    for(int i=0;i<9;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    solve(v,{},0,0);
    for(auto x : res){
        cout << x << "\n";
    }
    return 0;
}
