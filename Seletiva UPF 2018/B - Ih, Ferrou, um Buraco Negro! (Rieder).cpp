#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define abs(x) (((x)<0)?-(x):(x))
#define sz(a) int((a).size())
#define fr first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define tr(c,i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())

using namespace std;

#define eps 1e-6

struct point{
    double x, y;
};

int main(){
    int t,caso=1;
    double a1, b1, c1, a2, b2, c2, D, D1, D2;
    double X,Y;
    point a,b,c,d;
    point ab, cd, o;
    bool x_neg,y_neg;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf",&a.x,&a.y);
        scanf("%lf%lf",&c.x,&c.y);
        scanf("%lf%lf",&b.x,&b.y);
        scanf("%lf%lf",&d.x,&d.y);
        ab.x = (a.x+b.x)/2.0, ab.y = (a.y+b.y)/2.0;
        cd.x = (c.x+d.x)/2.0, cd.y = (c.y+d.y)/2.0;

        a1 = a.x-b.x, b1 = a.y-b.y;
        c1 = a1*ab.x + b1*ab.y;
        a2 = c.x-d.x, b2 = c.y-d.y;
        c2 = a2*cd.x + b2*cd.y;

        D = (a1*b2-a2*b1);

        if(D < eps and D > -eps){
		  X = 0.00;
		  Y = 0.00;
		}else{
        	D1 = (c1*b2-c2*b1);
        	if(D1 < eps and D1 > -eps){
		    	X = 0.00;
			}
			else
		    	X = (D1/D);
        	D2 = (a1*c2-a2*c1);
        	if(D2 < eps and D2 > -eps){
        		Y = 0.00;
			}else
				Y = (D2/D);
        }

        printf("Caso #%d: %.2f %.2f\n",caso++, X, Y);
    }
    return 0;
}
