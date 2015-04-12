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
int v[60];
int main() {
    v[0] = 1;
    v[1] = 1;
    for(int i=2;i<60;i++)
        v[i] = (v[i-1] + v[i-2]) % 10;
    long long n;
    while(cin >> n)
        cout << v[(n-1)%60] << endl;
    return 0;
}