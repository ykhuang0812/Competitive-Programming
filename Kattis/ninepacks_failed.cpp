#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,b;
    cin >> h;
    int maxh=0,maxb=0;
    map<int,int> mh,mb;
    for(int i=0;i<h;i++){
        int tmp;
        cin >> tmp;
        maxh+=tmp;
        mh[tmp]++;
    }
    cin >> b;
    for(int i=0;i<b;i++){
        int tmp;
        cin >> tmp;
        maxb+=tmp;
        mb[tmp]++;
    }
    vector<bool> canh(maxh+1,false); canh[0]=true;
    vector<int> mincanh(maxh+1,INT_MAX); mincanh[0]=0;
    vector<bool> canb(maxb+1,false); canb[0]=true;
    vector<int> mincanb(maxb+1,INT_MAX); mincanb[0]=0;
    for(auto x : mh){
        for(int i=0;i<x.first;i++){
            int left = x.second;
            for(int j=i;j<=maxh;j+=x.first){
                if(canh[j]) left = x.second;
                else if(left > 0 &&  j>=x.first && canh[j-x.first]){
                    left--;
                    canh[j]=true;
                    mincanh[j]=min(mincanh[j],mincanh[j-x.first]+1);
                }
            }
        }
    }
    //for(int i=0;i<canh.size();i++){
    //    cout << i << " : " << canh[i] << "\n"; 
    //}
    for(auto x : mb){
        for(int i=0;i<x.first;i++){
            int left = x.second;
            for(int j=i;j<=maxb;j+=x.first){
                if(canb[j]) left = x.second;
                else if(left > 0 &&  j>=x.first && canb[j-x.first]){
                    left--;
                    canb[j]=true;
                    mincanb[j]=min(mincanb[j],mincanb[j-x.first]+1);
                }
            }
        }
    }
    //for(int i=0;i<canb.size();i++){
    //    cout << i << " : " << canb[i] << "\n"; 
    //}
    bool ok = false;
    int i = 1;
    for(;i<=min(maxb,maxh);i++){
        if(canb[i]==1 && canb[i]==canh[i]){
            ok = true;
            break;
        }
    }
    if(ok)cout << mincanb[i]+mincanh[i] << "\n";
    else cout << "impossible\n";
}
