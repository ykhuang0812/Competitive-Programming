#include<bits/stdc++.h>
using namespace std;

bool next_perm(vector<int>::iterator first,vector<int>::iterator last){
    if(first == last) return false;
    auto i = first;
    i++;
    if(i==last) return false;
    i=last;
    i--;
    for(;;){
        auto ii = i;
        i--;
        if(*i < *ii){
            auto j = last;
            while(!(*i < *--j));
            iter_swap(i,j);
            reverse(ii,last);
            return true;
        }
        if(i==first){
            reverse(first,last);
            return false;
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long  n,k;
	cin >> n >> k;
	vector<int> v;
	for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
	}
	long long tk=k;
	while(next_perm(v.begin(),v.end()) && k--){
        for(auto x : v){
            cout << x << " ";
        }
        cout << endl;
	}
	if(tk==k) cout << "hello world!" << endl;
    return 0;
}
