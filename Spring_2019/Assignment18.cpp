#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

void run(vector<int>& v,int n){
    for(int i=0;i<n;i++) v.push_back(0);
    for(int i=0;i<n;i++) v.push_back(1);
    for(int i=n-1;i>0;i--){
        v[i]=gcd(v[i*2],v[i*2+1]);
    }
}

void update(vector<int>& v,int x, int value,int n){
    x+=n;
    v[x]=value;
    while(x > 1){
        x/=2;
        v[x]=gcd(v[x*2],v[x*2+1]);
    }
}

int query(vector<int>& v,int l ,int r,int n){
    l+=n;
    r+=n;
    int m=INT_MAX;
    while(l < r){
        if((l&1)==1){
            if(m==INT_MAX) m=v[l];
            m = gcd(m,v[l]);
            l++;
        }
        if((r&1)==1){
            r--;
            if(m==INT_MAX) m=v[r];
            m = gcd(m,v[r]);
        }
        l>>=1;
        r>>=1;
    }
    return m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,n,q,t,x,k;
    cin >> T;
    while(T--){
        cin >> n >> q;
        vector<int> v;
        run(v,n);
        while(q--){
            cin >> t >> x >> k;
            if(t==1){
                update(v,x-1,k,n);    
            }
            else{
                //for(auto x : v){
                //    cout << x << " ";
                //}
                //cout << "\n";
                int l=x-1,r=n;
                if(query(v,l,r,n)>k){
                    cout << "DOYA!\n";
                    continue;
                }
                while(l<r){
                    int mid=l+(r-l)/2;
                    if(query(v,x-1,mid,n)<=k){
                        r=mid;
                    }
                    else{
                        l=mid+1;
                    }
                }
                cout << r << "\n";
            }
        }
    }

}
