#include <iostream>
using namespace std;

int main(){
    int t, n ;
    cin >> t; // 테스트 케이스 횟수
    while(t-- > 0 ){
        int a,b,c,k;
        int cnt =0; // 중간고점 발생 횟수 count
        cin >> n >> a >> b; // 
        for(int i=n-2;i>0;i--){
            cin >> k;
            c = k;
            if(b==c)
                continue;
            if ((a<b)&&(b>c))
                cnt++;
            a = b;
            b = c;
        }
        cout << cnt << endl;
    }
    return 0;
}