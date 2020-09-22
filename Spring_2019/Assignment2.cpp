#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    string ans;
    vector<string> v;
    char op;
    while(cin >> s){
            string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='+' && s[i]!='*' && i!=s.size()-1){
                tmp+=s[i];
            }
            else if(s[i]=='+' || s[i]=='*' || i==s.size()-1){
                if(i==s.size()-1) tmp+=s[i];
                v.push_back(tmp);
                if(v.size()==2){
                    if(op == '+'){
                        string l = v[0];
                        string r = v[1];
                        //cout << l << " + " << r << endl;
                        v.clear();
                        if(l.size() > r.size()){r.insert(r.begin(),l.size()-r.size(),'0');}
                        if(l.size() < r.size()){l.insert(l.begin(),r.size()-l.size(),'0');}
                        int carry=0;
                        for(int i=l.size()-1;i>=0;i--){
                            int sum = l[i]-'0' +r[i]-'0'+carry;
                            //if(sum == (l[i]-'0') && ts<0) {break;}
                            l[i]=sum%10+'0';
                            carry=sum/10;
                        }
                        if(carry) l.insert(l.begin(),'1');
                        int c=0;
                        for(int i=0;i<l.size()-1;i++){
                            if(l[i]=='0') c++;
                            else break;
                        }
                        l.erase(0,c);
                        v.push_back(l);
                    }
                    else if(op == '*'){
                        string l = v[0];
                        string r = v[1];

                        //cout << l << " * " << r << endl;
                        v.clear();
                        //if(l.size() > r.size()){r.insert(r.begin(),l.size()-r.size(),'0');}
                        //if(l.size() < r.size()){l.insert(l.begin(),r.size()-l.size(),'0');}
                        vector<int> res(l.size()+r.size(),0);
                        reverse(r.begin(),r.end());
                        reverse(l.begin(),l.end());
                        for(int i=0;i<l.size();i++){
                            for(int j=0;j<r.size();j++){
                            int sum = (l[i]-'0')*(r[j]-'0');
                            res[i+j]+=sum;
                            }
                        }
                        /*
                        for(auto x : res) cout << int(x) << " ";
                        cout << endl;*/
                        for(int i=0;i<res.size();i++){
                            res[i+1] += res[i]/10;
                            res[i] = res[i]%10+'0';
                        }
                        /*
                        if(res[res.size()-1]>=10){
                            res.push_back(res[res.size()-1]/10+'0');
                            res[res.size()-2]=res[res.size()-2]%10+'0';
                        }
                        else{
                            res[res.size()-1]+='0';
                        }*/
                        int c=0;
                        for(int i=res.size()-1;i>0;i--){
                            if(res[i]=='0') c++;
                            else break;
                        }
                        res.erase(res.end()-c,res.end());
                        string ans="";
                        for(int i=res.size()-1;i>=0;i--){
                            ans+=res[i];
                        }
                        v.push_back(ans);
                    }
                }
                op=s[i];
                tmp.clear();
            }
        }
        cout << v[0] << endl;
        v.clear();
    }

	return 0;
}
