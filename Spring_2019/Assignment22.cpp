#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,n,k;
    cin >> T;
    while(T--){
        cin >> n >> k;
        ll total=0;
        map<ll,int> m;
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            m[tmp]++;
            total+=tmp;
        }
        ll need;
        ll g = gcd(100+k,100);
        if(total%((100+k)/g)!=0) {cout << "No\n"; continue;}
        else  need = total/((100+k)/g)*(100/g);
        cout << need << "\n";
        vector<bool> v(need+4,false);
        v[0]=true;
        for(auto x : m){
            for(int i=0;i<x.first;i++){
                ll left = x.second;
                for(int j=i;j<=need;j+=x.first){
                    if(v[j]) left = x.second;
                    else if(left>0){
                        left--;
                        v[j]=true;
                    }
                }
            }
        }
        for(auto x : m){
        cout << x.first << " " << x.second << "\n";
        }
        cout << "\n";
        for(auto x : v){
        cout << x << " ";
        }
        cout << "\n";
        if(v[need]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
