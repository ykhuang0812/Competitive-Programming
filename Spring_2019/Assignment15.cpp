#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> v; v.push_back(0);
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        v.push_back((tmp^v.back()));
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << (v[r]^v[l-1]) << "\n";
    }
    return 0;
}
