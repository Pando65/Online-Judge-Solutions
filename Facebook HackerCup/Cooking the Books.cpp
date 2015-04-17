#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int t;
    string n;
    in >> t;
    for(int kase=0;kase<t;kase++) {
        in >> n;
        out << "Case #" << kase+1 << ": ";
        if(n.length() <= 1)
            out << n << " " << n << endl;
        else {
            string copia=n;
            int m,p;
            char aux;
            //search the smallest
            for(int i=0;i<n.length()-1;i++) {
                m = INT_MAX;
                p = n.length();
                for(int j=n.length()-1;j>i;j--) {
                    if(i == 0)
                    {   if(m > n[j]-'0' && n[j] != '0') {
                            m = n[j]-'0';
                            p = j;
                        }
                    }
                    else {
                        if(m > n[j]-'0') {
                            m = n[j]-'0';
                            p = j;
                        }
                    }
                }
                if(m < n[i]-'0')
                {
                    aux = n[i];
                    n[i] = n[p];
                    n[p] = aux;
                    i = n.length()+1;
                }
            }
            out << n << " ";
            
            
            //search the bigger
            for(int i=0;i<copia.length()-1;i++) {
                m = -1;
                p = copia.length();
                for(int j=copia.length()-1;j>i;j--) {
                    if(m < copia[j]-'0') {
                        m = copia[j]-'0';
                        p = j;
                    }
                }
                if(m > copia[i]-'0')
                {
                    aux = copia[i];
                    copia[i] = copia[p];
                    copia[p] = aux;
                    i = copia.length()+1;
                }
            }
            
            out << copia << endl;
            
        }
    }
    
}