#include <iostream>
#include <vector>
using namespace std;

static int arr[1000*1000];

int main(){
    int t ;
    cin >> t;
    while(t-->0){
        int n, a, b;
        cin >> n >> a >> b;
        arr[0]=1;
        int i;
        for(i=1;i<n;i++)
            arr[i] = arr[i-1]+1; // 1증가
        int l =0;
        //for (int j=n-1;j>0;j--)
        int j=n;
        while(j-- >0)
        {
            if (l%2==0){
                int x=j, y=j;
                while (x-- >0){
                    arr[i] =arr[i-1]+ n ;
                    i++;
                }
                while(y-->0){
                    arr[i] =arr[i-1]- 1 ;
                    i++;
                }
            }
            if(l%2==1){
                int w=j, z=j;
                while (w-- >0){
                    arr[i] =arr[i-1]- n ;
                    i++;
                }
                while(z-- >0){
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