#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    ll s,c,k;
    cin >> s >> c >> k;
    map<ll,ll> socks;
    for(int i=0;i<s;i++){
        ll tmp;
        cin >> tmp;
        socks[tmp]++;
    }
    ll wash = 0;
    auto l = socks.begin();
    auto r = l;
    ll ans = 0;
    while(r!=socks.end()){
        if(r!=socks.end() && abs(r->first-l->first)<=k){
            wash+=r->second;
            r++;
        }
        else{
            ans += wash/c;
            wash%=c;
            l=(wash==0)?r:prev(r);
            if(abs(r->first-l->first)>k){
                ans+=1;
                wash=0;
                l++;
            }
        }
    }
    ans+= (wash/c) + ((wash%c)!=0);


    cout << ans << "\n";



}
