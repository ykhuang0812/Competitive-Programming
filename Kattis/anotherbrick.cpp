#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int h,w,n;
    cin >> h >> w  >> n;
    vector<int> brick;
    int tmpw=w;
    bool ok = true;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        tmpw-=tmp;
        if(h==0) break;
        if(tmpw<0) ok=false;
        else if(tmpw==0){
            tmpw=w;
            h--;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";

}
