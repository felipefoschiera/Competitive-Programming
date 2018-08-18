#include <stdio.h>
#include <math.h>

int main(){ 
    double ev1, ev2, at, d;
    while(scanf("%lf %lf %lf %lf", &ev1, &ev2, &at, &d), (ev1+ev2+at+d)){
        ev1 = ceil(ev1 / d);
        ev2 = ceil(ev2 / d);
        double probability;
        if(at == 3){
            probability = ev1 / (ev1 + ev2);
        }else{
            double prob1 = at / 6, prob2 = (6 - at) / 6;
            double divis = prob2 / prob1;
            probability = (1.0 - pow(divis, ev1)) / (1.0 - pow(divis, ev1+ev2));
        }
        printf("%.1f\n", 100.00 * probability);
    }
    return 0;
}