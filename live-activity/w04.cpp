#include <iostream>
#include <cstdlib>
#include <ctime>    
using namespace std;
/*
void print_arg(char *p){
    for(int i=0; p[i] !='\0'; i++)
        cout << p[i];
    cout << endl;
}
*/

int main(int argc, char *argv[]){
    if(argc !=2){ // command line에 int 2개 input 안되면
        cout << "usage: ./args n\n";
        return -1;
    }
    srand(time(NULL));

    int n = atoi(argv[1]);
    srand(n); // 시드를 지정한다는게 이런말이군아..
    for(int i=0;i<10;i++){
        int dice = rand()%6+1;
        cout << dice << " ";
    }
    cout << endl;

    return 0;
}