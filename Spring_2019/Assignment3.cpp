#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long long T;
    long long n,l,r;
    cin >> T;
    while(T--){
        cin >> n >> l >> r;
        vector<bool> v;
        v.resize(n+1,false);
        for(int i=0;i<n;i++){
            long long tmp;
            cin >> tmp;
            if(tmp >=l && tmp <=l+n){
                v[tmp-l]=true;
            }
        }
        for(int i=0;i<n+1;i++){
            if(v[i]==false){
                if(i>r-l) goto o;
                cout << i+l;
                goto e;
            }
        }
        o:
        cout << "^v^";
        e:
        cout << "\n";
    }
	return 0;
}
