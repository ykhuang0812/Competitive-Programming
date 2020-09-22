#include<bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,a,p;
	cin >> n;
	while(n--){
        cin >> a >> p;
        cout << power(a,p-2,p) << "\n";
	}

    return 0;
}
