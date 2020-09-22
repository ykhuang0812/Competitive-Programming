#include <bits/stdc++.h>
using namespace std;

bool run(vector<int> v, int k,long long word){
    long long tmp=0;
    int t=1;
    long long now=0,nl=0;
    for(int i=0;i<v.size();i++){
        nl++;
        now=max(now,(long long)v[i]);
        if(now*nl > word){
            t++;
            now=v[i];
            nl=1;
        }
    }
    if(t>k) return false;
    else return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,n,k;
        long long sum=0;
        vector<int> v;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            sum += tmp;
            v.push_back(tmp);
        }
        long long l=0,r=(long long)n*1000000000,m;
        while(l<r){
            m=(l+r)/2;
            if(run(v,k,m)){
                r=m;
            }
            else{
                l=m+1;
            }
            //cout << m << " " << l << " " << r << endl;
        }
        cout << r << "\n";
    return 0;
}

