#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    map<int,int> mx;
    map<int,int> my;
    for(int i=1;i<=n;i++){
        my[i]=1;
    }
    for(int i=1;i<=m;i++){
        mx[i]=1;
    }
    int total = n*m;
    while(q--){
        int x,y;
        cin >> y >> x;
        int eat = 0;
        for(int i = my[y]; i<=x ;i++){
            if(y >= mx[i]){
                eat+= y-mx[i]+1;
            }
            for(int j = mx[i]; j<=y ;j++){
                my[j]=x+1;
            }
            mx[i]=y+1;
        }
        if(eat == 0) cout << "QAQ" << "\n";
        else{
            total-=eat;
            cout << eat << "\n";
        }
    }
    cout << total << "\n";
    return 0;
}
