#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >>m;

    // 입력
    int arr[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%1d",&arr[i][j]); // 띄어쓰기 없어서 cin으로 못받음
    
    //출력
    int cnt = (n>m)?m:n; // 최대정사각형 크기(당연히 가로세로 중 더 작은것이 최대)  
    for(int l=cnt;l>0; l--){ // '' 부터 크기(각 변) 1씩 줄여나감 
        int s = l-1; // ㅁ의 간격 (예- 크기 3짜리 정사각형이면 2차원 배열 상으론 2차이)
        
        for (int i=0; i<n-s;i++) // ㅁ의 오른쪽변 기준, 오른쪽변이 <n 까지임을 생각하면
            for(int j=0;j<m-s;j++) // '' (j+s<n)
                if(arr[i][j]==arr[i][j+s]&&arr[i][j+s]==arr[i+s][j]){
                    cout << l*l << endl;
                    goto EXIT; // 중첩루프 전부 빠져나오기
                }
                
    }
EXIT :
    return 0;
}