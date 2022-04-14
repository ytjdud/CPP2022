#include <iostream>
#include <cstdlib>
using namespace std;

int ***makeArray3D(int *sz);
void destroyArray3D(int ***arr, int *sz);

int main(int argc, char *argv[]){
    if(argc < 2){
        cout << "usage : ./str 1d 2d 3d ... nd \n";
        return -1 ;
    }

    int i, dim = argc-1;
    int *size = new int[dim];

    for (i=1; i<argc; i++) size[i-1] = atoi(argv[i]);
    
    int ***arr3d = NULL ;

    arr3d = makeArray3D(size) ;
    for (int i=0; i<size[0];i++)
        for(int j=0;j<size[1];j++)
            for(int k=0;k<size[2];k++)
                arr3d[i][j][k] = (i*size[1]+j)*size[2]+k; //
    for (int i =0; i<size[0]; i++){
        cout << "i: " << i << endl;
        for(int j=0; j<size[1]; j++){
            for(int k=0;k<size[2];k++)
                cout << arr3d[i][j][k] << ' '; // 
            cout << endl;
        }
        cout << endl;
    }
    destroyArray3D(arr3d, size);
    return 0;
}
  
int ***makeArray3D(int *sz){
    int d = sz[0], r = sz[1], c=sz[2];
    int ***arr = new int **[d];
    for(int i=0;i<d;i++){
        arr[i] = new int *[r];
        for(int j=0; j<r; j++){
            arr[i][j] = new int[c];
        }
    }
    return arr;
}

void destroyArray3D(int ***arr, int *sz){
    int d =sz[0], r =sz[1];
    for (int i=0;i<d;i++){
        for(int j=0;j<r;j++)
            delete[] arr[i][j];
    }
    for (int i=0;i<d;i++)
        delete[] arr[i];
    delete[] arr;
}
/* 이렇게 길게 나눠 쓰기 말고 

for (int i=0;i<d;i++){
        for(int j=0; j<r; j++)
            delete[] arr[i][j];
        delete[] arr[i];
    }
    delete[] arr;

일케 하면 한번에 쓸 수 있음
*/