#include <iostream>
#include <string>
using namespace std;

int main(){
    int t ;
    unsigned long int n;
    int sum;

    cin >> t;
    for (int i =0; i<t ; i++){
        cin >> n;
        while(n>=10){
            int sum =1;
            while(n>=10){
                int r = n%10;
                n = n/10;
                if (r==0)
                    continue;
                sum *= r;
            }
            sum *= n;
            n = sum;
        }

        cout << n << endl;
    }
    return 0;
}
