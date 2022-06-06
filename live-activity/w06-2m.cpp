#include <iostream>
#include <cstring>
using namespace std;

class Kvector{
    int *m;
    int len;
public :
    Kvector(int sz =0, int value =0);
    Kvector(Kvector& v);
    ~Kvector(){
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    void print(){
        for(int i=0; i<len; i++) 
            cout << m[i] << " ";
        cout << endl;
    }
    void clear(){
        delete[] m;
        m = nullptr;
        len =0;
    }
    int size(){
        return len;
    }
};
Kvector::Kvector(int sz, int value):len(sz){
    cout << this << " : Kvector( " << sz << ", "<< value << ")\n";
    if(sz>0){
        m = new int[sz];
        for(int i=0;i<sz;i++) 
        // can write 'sz' as 'len' BUT using parameters is better to understand the func
            m[i] = value;
    }else{
        m = nullptr;
    }
}
Kvector::Kvector(Kvector& v){
    cout << this << " : Kvector(*" << &v << ")\n";
    len = v.len;
    if(len>0){
        m = new int[len];
        // for(int i=0;i<len;i++){
        //     m[i] = v.m[i];
        // }
        copy(v.m,v.m+v.len,m); // copy(src, src+(length), dst);
    }else{
        m = nullptr;
    }
  
}
int main(){
    Kvector v1(3); v1.print();
    Kvector v2(2, 9); v2.print();
    Kvector v3(v2); v3.print();
    v2.clear();
    v2.print();
    v3.print();
    
    return 0;
}
/* result
0x7ffee4a537f8 : Kvector( 3, 0)
0 0 0 
0x7ffee4a537d8 : Kvector( 2, 9)
9 9 
0x7ffee4a537c8 : Kvector(*0x7ffee4a537d8)
9 9 

9 9 
0x7ffee4a537c8 : ~Kvector() 
0x7ffee4a537d8 : ~Kvector() 
0x7ffee4a537f8 : ~Kvector() 
*/