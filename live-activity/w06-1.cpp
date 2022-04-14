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
    for(int i=0; i<n;i++){ 
        if (argv[1][i] == TARGET){
            a[j++] = argv[1][i];
            a[j++] = TARGET;
        }
        else 
            a[j++] = argv[1][i] ;
    }
    a[j] = '.' ;
    cout << a << endl;
    
    string s = "!";
    s += argv[1];
    s += ".";
    int pos =0;
    while((pos = s.find("e",pos)) != string::npos){
        s.replace(pos, 1,"ee");
        pos +=2;
    }

    /*
    int pos = s.find(TARGET,0);
    while(pos != string::npos){
        s.insert(pos,1, 'e');
        pos +=2;
        pos = s.find(TARGET,pos);
    }
    씨발 그리고 insert(pos, 개수, s2) 임 썅
    */
    cout << s << endl;

    return 0;
}
