/************
 * Optimal work assignment problem.
 *
 * Implemented by Omar Manjarrez Osornio
 * Github account: Pando65
 * March, 2015
 *
 ****/

#include<iostream>
#include<queue>
#include<fstream>

#define INF 999999

using namespace std;

int mat[30][30];
int n, minimum = INF;

//nodes of the tree
struct node {
    int acum, p, nivel;
    int v[26];
    
    node() {
        p = 0;
        for(int i=0;i<=n;i++)
            v[i] = -1;
    }
    
    //comparation function
    bool operator()(node& a, node& b) {
        if(a.p > b.p)
            return true;
        return false;
    }
};

priority_queue<node, vector<node>, node> heap;

int findMinimumPossible (node u) {
    int acum = 0;
    for (int i=u.nivel+1; i<n; i++) {
        int minp = INF;
        for (int j=0; j<n; j++)
            if (mat[i][j] < minp && u.v[j] == -1)
                minp = mat[i][j];
        acum += minp;
    }
    return acum;
}

int main() {
    //load text file input
    ifstream in;
    string name;
    cout << "Input file name: ";
    cin >> name;
    in.open(name.c_str());
    
    //read input and store
    in >> n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            in >> mat[i][j];
    in.close();
    
    node dad, sol, h;
    
    //initialize dummy root
    dad.acum = 0;
    dad.nivel = -1;
    dad.p = findMinimumPossible(dad);
    
    //insert root into priority queue
    dad.nivel++;
    heap.push(dad);
    
    //branch and bound cycle
    while (!heap.empty()) {
        
        //the best candidate will be my new dad
        node dad = heap.top();
        heap.pop();
        
        //if its minimum is still lower than my current minimum
        if (dad.p < minimum) {
            if (dad.nivel == n - 1) {
                
                //accumulated is equals to possible value if it's the last level
                dad.acum = dad.p;
                
                //change if it's better solution
                if (dad.acum < minimum) {
                    minimum = dad.acum;
                    sol = dad;
                }
            }
            else {
                //generate childs
                for (int i=0; i<n; i++) {
                    h = dad;
                    
                    //if the work 'i' is not yet assigned
                    if (h.v[i] == -1) {
                        h.v[i] = h.nivel;
                        h.acum += mat[h.nivel][i];
                        h.p = h.acum + findMinimumPossible(h);
                        
                        //if the possible value is lower than my current minimum
                        if (h.p < minimum) {
                            h.nivel++;
                            heap.push(h);
                        }
                    }
                }
            }
        }
    }
    
    //iterate over sol.v array to find the optimal path
    for (int i=0;i<n;i++) {
        cout << "Work " << i+1 << " assigned to person ";
        if (sol.v[i] == -1)
            cout << n << endl;
        else
            cout << sol.v[i] + 1 << endl;
    }
    
    cout << "Minimum cost: " << minimum;
    return 0;
    
}