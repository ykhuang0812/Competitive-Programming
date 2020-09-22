#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){

    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    while(getline(cin,s)){
        stringstream ss;
        ss << s;
        string tmp;
        string ans;
        string n;
        while(ss >> tmp){
            int carry=0;
            bool neg=false;
            if(tmp[0]=='-'){neg=true; tmp.erase(0,1);}
            int ts = tmp.size();
            if(!neg){
                if(tmp.size() > ans.size()){ans.insert(ans.begin(),tmp.size()-ans.size(),'0');}
                if(tmp.size() < ans.size()){tmp.insert(tmp.begin(),ans.size()-tmp.size(),'0');}
                for(int i=tmp.size()-1;i>=0;i--){
                    int sum = tmp[i]-'0' +ans[i]-'0'+carry;
                    if(sum == (ans[i]-'0') && ts<0) {break;}
                    ans[i]=sum%10+'0';
                    carry=sum/10;
                    ts--;
                }
                if(carry) ans.insert(ans.begin(),'1');
            }
            else{
                if(tmp.size() > n.size()){n.insert(n.begin(),tmp.size()-n.size(),'0');}
                if(tmp.size() < n.size()){tmp.insert(tmp.begin(),n.size()-tmp.size(),'0');}
                for(int i=tmp.size()-1;i>=0;i--){
                    int sum = tmp[i]-'0' +n[i]-'0'+carry;
                    if(sum == (n[i]-'0') && ts<0) {break;}
                    n[i]=sum%10+'0';
                    carry=sum/10;
                    ts--;
                }
                if(carry) n.insert(n.begin(),'1');
            }
        }
        //123456
        //000029
        int as = ans.size();
        int ns = n.size();
        if(ans.size() > n.size()) {n.insert(n.begin(),ans.size()-n.size(),'0');}
        if(ans.size() < n.size()) {ans.insert(ans.begin(),n.size()-ans.size(),'0');}
        int borrow =0;
        if(ans>=n){
            for(int i=ans.size()-1;i>=0;i--){
                int sum = ans[i]-n[i]-borrow;
                if(sum == (ans[i]-'0') && ns<0) {break;}
                if(sum < 0){
                    borrow=1;
                    ans[i]=sum+10+'0';
                }
                else{
                    borrow=0;
                    ans[i]=sum+'0';
                }
                ns--;
            }
            int c=0;
            for(int i=0;i<ans.size()-1;i++){
                if(ans[i]=='0'){c++;}
                else break;
            }
            ans.erase(0,c);
            cout << ans << endl;
        }
        //000005
        //123456
        else{
            for(int i=n.size()-1;i>=0;i--){
                int sum = n[i]-ans[i]-borrow;
                if(sum == (n[i]-'0') && as<0) {break;}
                if(sum < 0){
                    borrow=1;
                    n[i]=sum+10+'0';
                }
                else{
                    borrow=0;
                    n[i]=sum+'0';
                }
                as--;
            }
            int c =0;
            for(int i=0;i<n.size()-1;i++){
                if(n[i]=='0'){c++;}
                else break;
            }
            n.erase(0,c);
            n.insert(n.begin(),'-');
            cout << n << endl;
        }
    }
	return 0;
}
