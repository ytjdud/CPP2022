#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    double i = 97.0;
    double j = 97.0L;
    cout << typeid(i).name() << endl;
    cout << typeid(j).name() << endl;
    
    return 0;
}