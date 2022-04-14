#include <iostream>
using namespace std;

int main(){
    /*
    int arr[2][3] ={
        10, -1, 3, // 줄바꿈이라고 땀아니고 쉼표
        2, 5, 6 // 6 뒤에도 쉼표 필요한가?? 
    };
    */
    int arr[2][3]={
        {10,-1,3},
        {2,5,6} //   이거임 씨바아아아아아
    };
    for(int i=0; i<2;i++)
        for(int j=0; j<3; j++){
            cout << "arr[" << i << "][" << j << "] value: " << arr[i][j] ;
            cout << " address: " << &arr[i][j] << endl;
        }
        return 0;
}