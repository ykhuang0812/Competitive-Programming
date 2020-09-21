#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    bool dirtypush[367]{};
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        dirtypush[tmp]=true;
    }
    int cnt=0;
    int total=0;
    int res=0;
    for(int i=1;i<=365;i++){
        if(total>20){
            cnt = dirtypush[i-1];
            total = dirtypush[i-1];
            res++;
        }
        if(dirtypush[i]){
            cnt++;
        }
        total+=cnt-dirtypush[i-1];
    }
    if(total>0) res++;
    cout << res << "\n";
}
