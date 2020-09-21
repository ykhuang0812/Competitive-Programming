#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    string s;
    double avg=0;
    int amount=0;
    while(cin >> s){
        if(s=="die"){
            int price;
            cin >> price;
            double tax = (price-avg)*0.3; 
            if(tax < 0) tax=0;
            cout << fixed << setprecision(8) <<  amount*(price-tax) << "\n";
            break;
        }
        else if(s=="buy"){
            int share,crowns;
            cin >> share >> crowns;
            avg=(amount*avg+share*crowns)/(amount+share);
            amount+=share;
        }
        else if(s=="sell"){
            int share,crowns;
            cin >> share >> crowns;
            amount-=share;
        }
        else if(s=="split"){
            int split;
            cin >> split;
            avg/=split;
            amount*=split;
        }
        else if(s=="merge"){
            int merge;
            cin >> merge;
            avg*=merge;
            amount/=merge;
        }
    }
    return 0;
}
