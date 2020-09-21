#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    map<ll,ll> paint;
    ll n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        ll tmp;
        cin >> tmp;
        paint[tmp]++;
    }
    ll res=0;
    for(int i=0;i<m;i++){
        ll tmp;
        cin >> tmp;
        auto it = paint.lower_bound(tmp);
        res+=(it->first-tmp);
    }
    cout << res << "\n";
    return 0;
}
