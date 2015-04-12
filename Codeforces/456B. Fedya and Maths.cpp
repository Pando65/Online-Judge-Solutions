/*#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int main() {
    int dos[4] = {1,2,4,3};
    int tres[4] = {1,3,4,2};
    int cuatro[4] = {1,4,1,4};
    string n;
    cin >> n;
    int m = n[n.length()-1]-'0';
    m = m%4;
    int acum = 1 + dos[m] + tres[m] + cuatro[m];
    cout << acum%5 << endl;
}*/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
    string n;
    cin >> n;
    if(n.length() < 2) {
        if((n[0] - '0') %4 == 0)
            cout << 4 << endl;
        else
            cout << 0 << endl;
    }
    else {
        int m = atoi(n.substr(n.length()-2).c_str());
        if(m%4 == 0)
            cout << 4 << endl;
        else
            cout << 0 << endl;
    }
    
}
