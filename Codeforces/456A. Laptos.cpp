#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    pair<int,int> v[100005];
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> v[i].first  >> v[i].second;
    }
    sort(v,v+n);
    for(int i=0;i<n-1;i++) {
        if(v[i].second > v[i+1].second)
        {
            cout << "Happy Alex" << endl;
            return 0;
        }
    }
    cout << "Poor Alex" << endl;
    
}