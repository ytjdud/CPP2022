#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t-->0)
    {
        int a, b, c, d;
        cin >> a >> b>> c >> d;

        int i1 = b-a ; // interval
        int i2 = d-c ;
        int sum = i1+i2;

        int o1 = b-c ; // overlapped
        int o2 = d-a ;

        if( (a==c) && (d==b) )
            cout << o1 << " " << i1 << endl;

        else if ( ((a<=c) && (d<=b)) || ((c<=a) && (b<=d)) ){
            int s = (i1>i2)? i2 : i1 ; // smaller one => overlapped
            int l = (i1>i2)? i1 : i2 ; // larger one
            cout << s << " " <<  l << endl;
        }
        else if ( (a<c)&&(c<b)&&(b<d) ){
            cout << o1 << " " << sum-o1 << endl;
        }
        else if ( (c<a)&&(a<d)&&(d<b) ){
            cout << o2 << " " << sum-o2 << endl;
        }
        else if ( (b<=c) || (d<=a) )
            cout << 0 << " " << sum << endl;

    }
    return 0;
}