#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<iomanip>
#include<stdlib.h>
#include<set>
#include<map>
using namespace std;
struct point{
    double x,y;
};
int comparaX(const void *a, const void *b) { //return 1 cambia; return -1 no cambia
    if( ((point *)a)-> x < ((point *)b) -> x)
        return -1;
    else
        if( ((point *)a) -> x > ((point *)b) -> x)
            return 1;
        else
            return 0;
}
int comparaY(const void *a, const void *b) { //return 1 cambia; return -1 no cambia
    if( ((point *)a)-> y < ((point *)b) -> y)
        return -1;
    else
        if( ((point *)a) -> y > ((point *)b) -> y)
            return 1;
        else
            return 0;
}
double min(double a, double b) {
    if(a <= b)
        return a;
    return b;
}
double absoluto(double x){
    if(x < 0)
        return x*-1;
    return x;
}
double distancia(point a, point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
point v[10005];
point tira[10005];
double closest(int ini, int fin) {
    if(fin - ini + 1 == 2)
        return distancia(v[fin],v[ini]);
    if(fin - ini +1 < 2)
        return 1000000;
    double dl = closest(ini, (ini+fin)/2);
    double dr = closest((ini+fin)/2 +1, fin);
    double d = min(dl, dr);
    int j=0;
    
    for(int i=ini; i<=fin ;i++) {
        if(absoluto(v[(ini+fin)/2].x - v[i].x) < d)
            tira[j++] = v[i];
    }
    
   // qsort(tira,j,sizeof(tira[0]),comparaY);
    
    for(int i=0;i<j-1;i++) {
        for(int k=i+1; k < j && tira[k].y - tira[i].y < d; k++)
            if(distancia(tira[i],tira[k]) < d)
                d = distancia(tira[i],tira[k]);
    }
    
    return d;
}
int main() {
    int n;
    
    do {
        cin >> n;
        if(n != 0) {
            for(int i=0;i<n;i++)
                cin >> v[i].x >> v[i].y;
            qsort(v,n,sizeof(v[0]),comparaX);
            double r = closest(0,n-1);
            if(r < 10000)
                printf("%.4lf\n", r);
            else
                cout << "INFINITY" << endl;
        }
    } while(n != 0);
    return 0;
    
}