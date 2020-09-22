#include<bits/stdc++.h>
using namespace std;
class vip{
    public:
    double x,y;
};
double dist(vip p1,vip p2){
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) );
}
vip cpos(vip p1,vip p2){
    vip tmp;
    tmp.x = (p1.x+p2.x)/2;
    tmp.y = (p1.y+p2.y)/2;
    return tmp;
}
bool mincircle(vip p1,vip p2,vip p3){
    double r = dist(p1,p2)/2;
    vip c = cpos(p1,p2);
    if(dist(c,p3) <= r){
        return true;
    }
    else{
        return false;
    }
}
bool cocircle(vip p1,vip p2,vip p3,vip &q,double &r)
{
  double x12=p2.x-p1.x;
  double y12=p2.y-p1.y;
  double x13=p3.x-p1.x;
  double y13=p3.y-p1.y;
  double z2=x12*(p1.x+p2.x)+y12*(p1.y+p2.y);
  double z3=x13*(p1.x+p3.x)+y13*(p1.y+p3.y);
  double d=2.0*(x12*(p3.y-p2.y)-y12*(p3.x-p2.x));
  if(abs(d)<1e-5)
     return false;
  q.x=(y13*z2-y12*z3)/d;
  q.y=(x12*z3-x13*z2)/d;
  r=dist(p1,q);
  return true;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    string tmp;
    while(getline(cin,tmp)){
        stringstream ss;
        ss << tmp;
        vip p1,p2,p3;
        ss >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        double r=DBL_MAX;
        vip c;
        if(mincircle(p1,p2,p3)){
            if(dist(p1,p2)/2 < r){
                r = dist(p1,p2)/2;
                c = cpos(p1,p2);
            }
        }
        if(mincircle(p1,p3,p2)){
            if(dist(p1,p3)/2 < r){
                r = dist(p1,p3)/2;
                c = cpos(p1,p3);
            }
        }
        if(mincircle(p3,p2,p1)){
            if(dist(p3,p2)/2 < r){
                r = dist(p3,p2)/2;
                c = cpos(p3,p2);
            }
        }
        vip t;
        double tr;
        if(cocircle(p1,p2,p3,t,tr)){
            if(tr < r){
                r = tr;
                c = t;
            }
        }
        cout << fixed << setprecision(6) << c.x << " " << c.y << " " << r << "\n";
    }
    return 0;
}
