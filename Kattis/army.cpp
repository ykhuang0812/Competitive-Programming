#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int ng,nm,tmp;
        map<int,int> g,m;
        vector<int> v;
        cin >> ng >> nm;
        for(int i=0;i<ng;i++){
            cin >> tmp;
            g[tmp]++;
            v.push_back(tmp);
        }
        for(int i=0;i<nm;i++){
            cin >> tmp;
            m[tmp]++;
            v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        int win=0;//1 for g win , 2 for m win, 0 for uncertain
        for(int i=0;i<v.size();){
            if(m.count(v[i])){
                m[v[i]]--;
                if(m[v[i]]==0) m.erase(v[i]);
            }
            if(m.empty() && !g.empty()){
                win=1;
                break;
            }
            if(g.count(v[i])){
                g[v[i]]--;
                if(g[v[i]]==0) g.erase(v[i]);
            }
            if(!m.empty() && g.empty()){
                win=2;
                break;
            }
            if(!m.count(v[i]) && !g.count(v[i])) i++;
        }
        if(win==0) cout << "uncertain\n";
        else if(win==1) cout << "Godzilla\n";
        else cout << "MechaGodzilla\n";
    }
    return 0;
}
