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
int main() {
    bool f=false;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n/2;i++) {
        for(int j=0;j<m;j++)
            cout << "#";
        cout << endl;
        if(!f) {
            for(int j=0;j<m-1;j++)
                cout << ".";
            cout << "#" << endl;
        }
        else {
            cout << "#";
            for(int j=0;j<m-1;j++)
                cout << ".";
            cout << endl;
        }
        f = !f;
    }
    
    for(int j=0;j<m;j++)
        cout << "#";
}