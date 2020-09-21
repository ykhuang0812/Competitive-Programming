#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n<=2) cout << 1 << "\n";
    else cout << n-2 << "\n";
    return 0;
}
