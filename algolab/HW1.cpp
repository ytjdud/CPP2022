#include <iostream>
using namespace std;

int main(){
  int t, k;

  cin >> t;

  int n,i,j;

  for (n=0; n<t; n++){
    cin >> k ;
    for (i=0; i<(k+1)/2; i++){
      for (j=0; j<k;j++){
        if( (j<i) || (k-1-i<j) )
          cout << '-';
        else if((j-i)%2==0)
          cout << '*';
        else
          cout << '+';
      }
      cout << endl;
    }

      for(i=(k+1)/2; i<k; i++){
        for(j=0; j<k; j++){
          if ( (j<k-1-i) || (i<j) )
            cout << '-';
          else if ((j-i)%2==0)
            cout << '*';
          else
            cout << '+';
        }
        cout << endl;
      }

  }
  return 0;
}
