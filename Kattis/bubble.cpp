#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    cin >> n;
    vector<int> t;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }
    int res = INT_MAX;
    for(int i=0;i<b.size();i++){
        cin >> n;
        for(int j=0;j<n;j++){
            int tmp;
            cin >> tmp;
            res = min(res,b[i]+t[tmp-1]);
        }
    }
    int money;
    cin >> money;
    if(money/res-1 <= 0){
        res=0;
    }
    else{
        res = money/res-1;
    }
    cout << res << "\n";
}
