#include <iostream>
using namespace std;

int main(){
    int t ;
    cin >> t;
    while(t-->0){
        int n, a, b;
        cin >> n >> a >> b;
        
        int arr[n*n];
        arr[0]=1;
        int i;
        for(i=1;i<n;i++)
            arr[i] = arr[i-1]+1;
        
        int l =0;
        int j=n;
        while(j-- >0)
        {
            if (l%2==0){
                int j1=j, j2=j;
                while (j1-- >0){
                    arr[i] =arr[i-1]+ n ;
                    i++;
                }
                while(j2-- >0){
                    arr[i] =arr[i-1]- 1 ;
                    i++;
                }
            }
            if(l%2==1){
                int j1=j, j2=j;
                while (j1-- >0){
                    arr[i] =arr[i-1]- n ;
                    i++;
                }
                while(j2-- >0){
                    arr[i] =arr[i-1]+ 1 ;
                    i++;
                }
            }
            l++;
        }
        for (i=a-1; i<b; i++)
            cout << arr[i] << ' ' ;
        cout << endl;
    }
    return 0 ;
}