#include <bits/stdc++.h>
using namespace std;

vector<int> b1,b2;
int sum1,sum2;
void solve(vector<int>& box,vector<int> tmp1,vector<int> tmp2,int s1,int s2, int ind){
    if(tmp1.size()==3 && s1==sum1 && tmp2.size()==3 && s2==sum2){
        b1=tmp1;
        b2=tmp2;
        return;
    }
    if(ind >= box.size()) return;
    solve(box,tmp1,tmp2,s1,s2,ind+1);
    tmp1.push_back(box[ind]);
    solve(box,tmp1,tmp2,s1+box[ind],s2,ind+1);
    tmp1.pop_back();
    tmp2.push_back(box[ind]);
    solve(box,tmp1,tmp2,s1,s2+box[ind],ind+1);
    return;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    vector<int> box(6);
    for(int i=0;i<6;i++){
        cin >> box[i];
    }
    sort(box.begin(),box.end(),greater<int>());
    cin >> sum1 >> sum2;
    solve(box,{},{},0,0,0);
    for(auto x : b1){
        cout << x << " ";
    }
    for(auto x : b2){
        cout << x << " ";
    }
    cout << "\n";

}
