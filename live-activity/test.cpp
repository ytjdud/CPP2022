#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define TARGET 'e'

int main(int argc, char *argv[]){
    if(argc < 2) { cout << "one command line argument needed\n"; return -1; }
    int n = strlen(argv[1]);
    char *a = new char[n*2+3];
    if(!a) { cout << "allocation failed.\n"; return -1; }
    a[0] = '!';
    
    int j=1;
    for (int i=0;i<n;i++,j++){ // n= strlen(argv[1])
        a[j] = argv[1][i];
        if(argv[1][++i] == TARGET ){
            a[++j] = TARGET; // ++j 해야 할것 같은데... 
        }
    }
    a[j] = '.' ;
    cout << a << endl;

    return 0;
}