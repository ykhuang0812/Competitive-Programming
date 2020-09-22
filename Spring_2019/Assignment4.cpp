#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int testcase;
    cin >> testcase;
    while(testcase--){
        int n;
        cin >> n;
        vector<int> a;
        a.reserve(n);
        for(int i = 0 ; i < n ; i++){
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        int ans = 0;
        stack<int> s;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!s.empty() && a[i] > s.top()){
                s.pop();
            }
            s.push(a[i]);
            ans=max((int)s.size(),ans);
        }
        cout << ans << "\n";
    }
    return 0;
}
