#include <iostream>
using namespace std;

void f2(int a, int b, int sum, int diff);

int main(){
    int i=1, j=2, k, l;
    f2(i,j,k,l);

    cout << "k= " << k << endl;
    cout << "l= " << l << endl;
    return 0;
}
void f2(int a, int b, int sum, int diff){
    sum = a+b ;
    diff = a-b;
}