#include <iostream>
using namespace std;

int f2 (int a, int b= 0, int *sum=nullptr, int *diff=nullptr);

int main(){
    int i =1, j=2, k=10, l=11;

    f2(i,j,&k,&l);

    cout << "k= " << k << endl;
    cout << "l= " << l << endl;
    return 0;
}
int f2(int a, int b , int *sum, int *diff){
    *sum = a+b ;
    *diff = a-b;
    return *sum;
}