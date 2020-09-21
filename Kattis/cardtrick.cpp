#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        int shift=n;
        deque<int> dq;
        for(int i=n-1;i>=0;i--){
            dq.push_front(v[i]);
            for(int j=0;j<shift;j++){
                int tmp = dq.back();
                dq.push_front(tmp);
                dq.pop_back();
            }
            shift--;
        }
        for(auto x : dq){
            cout << x << " ";
        }
        cout << "\n";
    }

}
