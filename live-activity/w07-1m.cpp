#include <iostream>
#include <cstring>
using namespace std;

class Kvector{    
    int *m;
    int len;
public :
    Kvector(int sz =0, int value =0);
    Kvector(const Kvector& v);
    ~Kvector(){
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    void print() const{
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
    Kvector& operator=(const Kvector& k);
friend bool operator==(const Kvector& k, const Kvector& v); 
friend bool operator!=(const Kvector& k, const Kvector& v);
int& operator[](int idx);
friend ostream& operator<<(ostream& os, const Kvector& k);
};
Kvector::Kvector(int sz, int value):len(sz){
    cout << this << " : Kvector( " << sz << ", "<< value << ")\n";
    if(sz>0){
        m = new int[sz];
        for(int i=0;i<sz;i++)
            m[i] = value;
    }else{
        m = nullptr;
        }
    }
Kvector::Kvector(const Kvector& v){
    cout << this << " : Kvector(*" << &v << ")\n";
    len = v.len;
    if(len>0){
        m = new int[len];
        copy(v.m,v.m+v.len,m);
    }else{
        m = nullptr;
    }
}
Kvector& Kvector::operator=(const Kvector& k){ 
    if(this != &k){
        if(len != k.len){
            delete[] m;
            len =0;
            m = nullptr;
            m = new int[k.len];
            len = k.len;
        }
        copy(k.m,k.m+k.len,m);
    }
    return *this;
}
bool operator==(const Kvector& k, const Kvector& v){
    if(k.len == v.len){
        for(int i=0; i<k.len; i++){
            if(k.m[i]!=v.m[i])  
                return false;
            return true;
        }
    }else{
        return false;
    }
    return 0; // warning: non-void function does not return a value in all control paths [-Wreturn-type]
}
bool operator!=(const Kvector& k, const Kvector& v){
    return !(operator==(k,v));
}
ostream& operator<<(ostream& os, const Kvector& k){
    for(int i=0;i<k.len;i++){
        os << k.m[i] << " ";
    }
    return os;
}
int& Kvector::operator[](int idx){
    assert(0<=idx && idx < size());
    return m[idx];
}
int main(){
    Kvector v1(3); v1.print();
    Kvector v2(2,9); v2.print(); 
    Kvector v3(v2); v3.print(); 
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1: "<< v1 <<"v2: "<< v2 <<"v3: "<< v3 << endl;
    return 0;
}
/* result
0x7ffee060c7f8 : Kvector( 3, 0)
0 0 0 
0x7ffee060c7d8 : Kvector( 2, 9)
9 9 
0x7ffee060c7c8 : Kvector(*0x7ffee060c7d8)
9 9 
0
1
0 0 0 
0 0 0 
0 0 0 
0
v1: 0 0 2 v2: 2 0 0 v3: 0 0 0 
0x7ffee060c7c8 : ~Kvector() 
0x7ffee060c7d8 : ~Kvector() 
0x7ffee060c7f8 : ~Kvector() 
*/
