#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long  n,m,q;
	cin >> n >> m >> q;
	map<int,int> mxy;
	map<int,int> myx;
	map<int,int>::iterator it,y_up,y_low,x_up,x_low;
	long long area = 0;
	long long remain = n*m;

	myx[n]=0; mxy[m]=0;
	mxy[0]=n; myx[0]=m;

	while(q--){
	    int y,x;
		long long tmp = 0;
		long long ans = 0;
        cin >> y >> x;
		it = myx.lower_bound(y);
        if(it!= myx.end() && it->second >= x) {cout << "QAQ" << "\n"; continue;}

        if(it->first == y) it++;
        y_up = it;

        it = mxy.lower_bound(x);
        if(it->first > x) it--;
        y_low =myx.lower_bound(it->second);

        x_up = mxy.lower_bound(y_low->second);
        x_low = mxy.lower_bound((--y_up)->second);

        myx.erase(y_low,++y_up);
        mxy.erase(x_low,++x_up);
		myx[y]=x;
		mxy[x]=y;

		for(auto z : myx){
            ans+=(z.first-tmp)*z.second;
            tmp=z.first;
		}
        cout << ans-area << "\n";
        remain -= ans-area;
        area = ans;
	}
	cout << remain << "\n";

    return 0;
}
