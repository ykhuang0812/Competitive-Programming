#include <bits/stdc++.h>
using namespace std;
#define ll long long

int LIS(vector<pair<int,int>>& v){
    vector<int> tmp;
    tmp.push_back(v[0].second);

    for(int i=1;i<v.size();i++){
        pair<int,int> n = v[i];
        if(n.second >= tmp.back()){
            tmp.push_back(n.second);
        }
        else{
            *upper_bound(tmp.begin(),tmp.end(),n.second)=n.second;
        }
    }
    return tmp.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,n,x,y;
    cin >> T;
    while(T--){
        vector<pair<int,int>> v;
        cin >> n;
        while(n--){
            cin >> x >> y;
            v.push_back({x,y});
        }
        sort(v.begin(),v.end());
        cout << LIS(v) << "\n";
    }
}
