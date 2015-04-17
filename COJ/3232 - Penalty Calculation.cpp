#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, string> > v;
int main() {
    int n,min,contPenalty=0;
    string verdict;
    cin >> n;
    for(int i=0;i<n;i++) {
        pair<int,string> aux;
        cin >> aux.first >> aux.second;
        v.push_back(aux);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        if(v[i].second == "AC") {
            cout << v[i].first + contPenalty * 20;
            return 0;
        }
        contPenalty++;
    }
    cout << 0;
    return 0;
}