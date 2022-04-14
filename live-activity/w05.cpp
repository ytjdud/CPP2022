#include <iostream>
using namespace std;

void init_array(int *a,int n); // int *a 임.. 참
int sum_array1(int *a,int n);

int main(int argc, char *argv[]){
    if (argc < 2){
        cout << "one command line argument needed\n";
        return -1;
    }

    int n = atoi(argv[1]);
    srand(n);
    n = (n<1)? 1 : n ;
    n = (n>10)? 10 : n ;

    int *a = new int [n];
    if(!a){
        cout << "allocation failed.\n";
        return -1;
    }
    int s;

    init_array(a, n);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";

    s = sum_array1(a,n);
    cout << endl << s << endl;

    return 0;
}

void init_array(int *a,int n){
    for(int i=0;i<n;i++){
        a[i] = rand()%1000;
    }
}
int sum_array1(int *a,int n){
    int sum =0;
    for (int i =0; i<n;i++){
        sum += a[i];
    }
    return sum;

}