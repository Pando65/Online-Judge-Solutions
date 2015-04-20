#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
int main() {
    int t,aux, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        priority_queue<int, vector<int>, greater<int> > heap;
        for(int i=0;i<n;i++) {
            scanf("%d", &aux);
            heap.push(aux);
        }
        
        int max;
        set<int> mark;
        while(heap.size() > 0) {
            max = heap.top();
            heap.pop();
            if(mark.find(max) != mark.end()) {
                mark.erase(max);
                heap.push(max*2);
            }
            else
                mark.insert(max);
        }
        
        printf("%d\n", max);
    }
    
    
}