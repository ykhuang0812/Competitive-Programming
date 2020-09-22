#include<bits/stdc++.h>
using namespace std;

vector<long long> karatsuba(vector<long long> X,vector<long long> Y, int n){
    vector<long long> ans;
    if(n==128){
        for(int i=0;i<n*2;i++){
            ans.push_back(0);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i+j]+=X[i]*Y[j];
            }
        }
        return ans;
    }
    int m = n/2;
    vector<long long> tmp_x;
    vector<long long> tmp_y;
    for(int i=0;i<m;i++){
        tmp_x.push_back(X[i]);
        tmp_y.push_back(Y[i]);
    }
    vector<long long> ac = karatsuba(tmp_x,tmp_y,m);
    for(int i=0;i<m;i++){
        tmp_x[i] += X[i+m];
        tmp_y[i] += Y[i+m];
    }
    vector<long long> ab_cd = karatsuba(tmp_x,tmp_y,m);
    for(int i=0;i<m;i++){
        tmp_x[i] -= X[i];
        tmp_y[i] -= Y[i];
    }
    vector<long long> bd = karatsuba(tmp_x,tmp_y,m);

    for(int i=0;i<n*2;i++) ans.push_back(0);
    for(int i=0;i<n;i++){
        ans[i]+=ac[i];
        ans[i+m]+=ab_cd[i]-ac[i]-bd[i];
        ans[i+n]+=bd[i];
    }
    return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n,m,q;
	cin >> n >> m >> q;
	vector<long long> sword(1<<16,0),shield(1<<16,0);
    sword[0]=1;
    shield[0]=1;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        sword[tmp]+=1;
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        shield[tmp]+=1;
    }
    vector<long long> res = karatsuba(sword,shield,1<<16);

    while(q--){
        int monster;
        cin >> monster;
        if(monster > 100000){ cout << "0\n"; continue;}
        cout << res[monster] << "\n";
    }
    return 0;
}
