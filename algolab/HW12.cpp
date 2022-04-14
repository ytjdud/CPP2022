#include <iostream>
using namespace std;

int main(){
    int t,n;
    cin >> t ;
    while(t-- >0){
        cin >> n;
        const int MID = (n-1)/2;

        for(int r=0;r<2;r++){
            cout << '+';
            for(int j=(n-3)/2; j>0;j--)
                cout << '-' ;
        }
        cout << '+' << endl;

        for(int i=1; i<MID; i++){ 
            for(int j=0;j<n;j++){
                if((j==0)||(j==MID)||(j==n-1)) //
                    cout << '|';
                else if(j==i)
                    cout << '\\' ;
                else if(j==(n-1)-i)
                    cout << '/' ;
                else
                    cout << '.';
            }
            cout << endl;
        }

        cout << '+';
        for(int jj=0; jj<(n-3)/2; jj++)
            cout << '-';
        cout << '*' ;
        for(int jj=0; jj<(n-3)/2; jj++)
            cout << '-';
        cout << '+' << endl;

        for(int i=MID+1;i<n-1;i++){
            for(int j=0;j<n;j++){
                if((j==0)||(j==MID)||(j==n-1))
                    cout << '|';
                else if(j==(n-1)-i)
                    cout << '/' ;
                else if(j==i)
                    cout << '\\' ;
                else
                    cout << '.';
            }
            cout << endl;
        }

        for(int r=0;r<2;r++){
            cout << '+';
            for(int j=(n-3)/2; j>0;j--)
                cout << '-' ;
        }
        cout << '+' << endl;
    }
    return 0;
}