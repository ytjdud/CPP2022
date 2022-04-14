#include <iostream>
using namespace std;

int main(){
  int t, n;

  cin >> t;
  for (int c=0;c<t;c++)
  { 
    cin >> n ;
    for (int i=0; i<(n+1)/2; i++) { // case1 처음~중간 (i=행)
        for(int j=0; j<n; j++){ // 한 줄 출력 (j=열)
            if ((j>=i)&&(j<=n-i-1)){
                if(i%2==0) // 최외각? 숫자랑 짝꿍 되는 행들
                    cout << ((n%4==3)? '1':'0') ;
                else  // 최외각-1 숫자랑 짝궁 되는 행들
                    cout << (n%4==1)? '1':'0' ;
            }

            else if ((j<i)||(j>n-i-1)){
                if (j%2==0)
                    cout << ((n%4==3)? '1':'0') ;
                else
                    cout << (n%4==1)? '1':'0' ;
            }
        }
        cout << endl;
    }

    for (int i=(n+1)/2 ; i<n; i++) { // case2 중간~끝
        for(int j=0;j<n;j++){ // 한 줄 출력
            if ((j>=n-i-1)&&(j<=i)){
                if(i%2==0)
                    cout << ((n%4==3)? '1':'0') ;
                else 
                    cout << (n%4==1)? '1':'0' ;
            }

            else if ((j<i)||(j>n-i-1)){
                if (j%2==0)
                    cout << ((n%4==3)? '1':'0') ;
                else
                    cout << (n%4==1)? '1':'0' ;
            }
        }
        cout << endl;
    }
    
  }
}