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
char mat[55][55];
bool mark[55][55];
int n,m,xpp,ypp;
bool flag = false;
void f(int x, int y, bool primero, int come) {
    if(x < 0 || y < 0 || x >= m || y >= n)
        return;
    if(xpp == x && ypp == y && !primero) {
        flag = true;
        return;
    }
    if(mark[y][x])
        return;
    if(mat[y][x] != mat[ypp][xpp])
        return;
    if(!flag) {
        mark[y][x] = true;
        if(come != 2)
            f(x+1,y,false,4);
        if(come != 4)
            f(x-1,y,false,2);
        if(come != 1)
            f(x,y-1,false,3);
        if(come != 3)
            f(x,y+1,false,1);
        mark[y][x] = false;
    }
    
}
int main() {
    char basura;
    scanf("%d %d", &n, &m);
    scanf("%c", &basura);
    for(int i=0; i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%c", &mat[i][j]);
        }
        scanf("%c", &basura);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            ypp = i;
            xpp = j;
            f(j,i, true, 0);
            if(flag) {
                printf("Yes\n");
                return 0;
            }
        }
    
    printf("No\n");
}