#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    map<int,int> ans;
    for(int i=0;i<256;i++){
        ans[i^((i<<1)%256)]=i;
    }
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        cout << ans[tmp] << " ";
    }
    cout << "\n";
    return 0;

}
