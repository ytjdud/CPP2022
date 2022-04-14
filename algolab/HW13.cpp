#include <iostream>
using namespace std;

void swap(int &s1, int &s2){
    int tmp;

    tmp = s1;
    s1 = s2;
    s2 = tmp;
} 

void print(int sA, int l, int w, int sPer){ 
    int A = sA-l*w; // area
    int Per = sPer - 2*(l+w);
    cout << A << " " << Per << endl;
} 

int main(){
    int t;
    cin >> t;
    while (t-- > 0){
        int a, b, c, d;
        int e, f, g, h;
        cin >> a >> b>> c>> d;
        cin >> e >> f>> g >> h;
        
        if (a>e){
            swap(a,e); swap(b,f); swap(c,g); swap(d,h);
        }
        int sA = (c-a)*(d-b) + (g-e)*(h-f) ; 
        int sPer = 2*(c-a + d-b + g-e + h-f);
        const int CE = c-e; const int GE = g-e; 

        if( (e<=c && c<=g) && ( f<=b && b<=h && h<=d )){
            int w = h-b; 
            print(sA, CE, w, sPer);
        }
        else if( (e<=c && c<=g) &&( b<f && f<=d && d<h )){
            int w = d-f;
            print(sA, CE, w, sPer);
        }
        else if( (e<=c && c<=g) &&( f<=b && d<h )){
            int w = d-b;
            print(sA, CE, w, sPer);
        }
        else if( (e<=c && c<=g) &&( b<f && h<=d )){
            int w= h-f;
            print(sA, CE, w, sPer);   
        }
        else if( g<c && ( f<=b && b<=h && h<=d )){
            int w = h-b;
            print(sA, GE, w, sPer);
        }
        else if( g<c && ( b<f && f<=d && d<h )){
            int w = d-f;
            print(sA, GE, w, sPer);    
        }
        else if( g<c && ( f<=b && d<h )){
            int w = d-b;
            print(sA, GE, w, sPer);
        }
        else if( g<c && ( b<f && h<=d )){
            int w = h-f;
            print(sA, GE, w, sPer);
        }
        else if (c<=e || ((a<=e && e<=c)&& (h<=b) || (d<=f) )){
            cout << sA << " " << sPer << endl;
        }
    }
    return 0;
}