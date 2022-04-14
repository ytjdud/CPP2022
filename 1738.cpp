#include <iostream>
#include <cstring>
using namespace std;

class Student{
    int id;
    char *name;
public :
    Student(int n,const char *s){
        id =n;
        name = new char[strlen(s)+1];
        strcpy(name,s);
}
    ~Student(){delete[] name;}
    Student(const Student& st){
        id = st.id;
        //name = st.name;
        name = new char[strlen(st.name)+1];
        strcpy(name,st.name);
    }
    void setName(const char *s){
        delete[] name;
        name = new char[strlen(s)+1];
        strcpy(name,s);
    }
    void print(){
        cout << this << " ] " << "name: " << name;
        cout << " id : " << id << endl;
    }
};

int main(){
    Student s1(20100001,"Kim"), s2(s1);
    s1.print(); s2.print();
    s2.setName("Park");
    s1.print(); s2.print();
    return 0;
}