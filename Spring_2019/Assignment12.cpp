#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin >> n;
	vector<pair<int,int>> building;
	for(int i=0;i<n;i++){
        int x,h,w;
        cin >> x >> h >> w;
        building.push_back({x,h});
        building.push_back({x+w,-h});
	}
	sort(building.begin(),building.end(), [&](pair<int,int> l ,pair<int,int> r){ return (l.first==r.first) ? l.second > r.second : l.first < r.first ;} );
    map<int,int,greater<int>> m;
	int val = 0;
	vector<pair<int,int>> point;
	for(auto x : building){
        if(x.second > 0) m[x.second]++;
        else if(--m[-x.second]==0) m.erase(-x.second);
        int cur = m.empty()? 0 : m.begin()->first;
        if(cur != val){
            val = cur;
            point.push_back({x.first,val});
        }
	}
	long long area = 0;
	long long skyline = 0;
	long long last_y=0;
	for(vector<pair<int,int>>::iterator it=point.begin();it!=point.end()-1;it++){
        vector<pair<int,int>>::iterator next =it; next++;
        area += (long long)(next->first - it->first) * it->second;
        skyline += (next->first-it->first) + llabs(it->second-last_y);
        if(it->second==0) skyline -= (next->first-it->first);
        last_y = it->second;
	}
	skyline += last_y;
	cout << skyline << " " << area << "\n";
    return 0;
}
