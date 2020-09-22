include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n,m,x,y,z;
        cin >> m >> n >> x >> y >> z;
        string s1,s2;
        cin >> s2 >> s1;
        long long dp[n+1][m+1];
        dp[0][0]=0;
        for(int i=1;i<n+1;i++){
            dp[i][0]=dp[i-1][0]+y;
        }
        for(int i=1;i<m+1;i++){
            dp[0][i]=dp[0][i-1]+x;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i][j-1]+x,dp[i-1][j]+y,dp[i-1][j-1]+z});
                }
            }
        }
        cout << dp[n][m] << "\n";
       /* 
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                 cout << dp[i][j] << " ";
            }
            cout << "\n";
        }*/
    }
    return 0;
}
