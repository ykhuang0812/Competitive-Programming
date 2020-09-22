#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    map<string,int> m;
    map<int,string> o;
    string tmp;
    int c=0;
    while(cin >> tmp){
        for(int i=0;i<tmp.size();i++){
            if(isalpha(tmp[i])){
                tmp[i] = tolower(tmp[i]);
            }
            else{
                tmp.erase(tmp.begin()+i);
                i--;
            }
        }
        if(tmp.size()!=0){
            if(m.count(tmp)==1){
                m[tmp]+=1;
            }
            else{
                m[tmp]=1;
                o[c]=tmp;
                c++;
            }
        }
    }
    //cout << "GG" << endl;
    for(auto x : o) cout << x.second << " " << m[x.second] << "\n";

    return 0;
}
