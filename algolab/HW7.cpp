#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int t,k;

    cin >> t;
    for (int i=0;i<t;i++){
        cin >> k;
        int k2 =k;
        int sum=0;
        int d = to_string(k).size();
        while(k2>9){
            int r = k2%10;
            sum += pow(r,d);
            k2=k2/10;
        }
        sum += pow(k2,d);

        if (k==sum)
            cout << '1' << endl;
        else
            cout << '0' << endl;

    }
    return 0;

}
