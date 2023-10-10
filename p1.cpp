// 3 numere. min, max, diferenta max-min
#include <iostream>

using namespace std;

int maxim(int a,int b,int c)
{
    if((a>b)&&(a>c))
    {
        return a;
    }
    if((b>a)&&(b>c))
    {
        return b;
    }
    if((c>a)&&(c>b))
    {
        return c;
    }
}

int minim(int a,int b,int c)
{
    if((a<b)&&(a<c))
    {
        return a;
    }
    if((b<a)&&(b<c))
    {
        return b;
    }
    if((c<a)&&(c<b))
    {
        return c;
    }
}
void dif(int a,int b)
{
    if(a>b)
    {
        cout<<a;
    }
    if(a==b)
    {
        cout<<"maxim=minim";
    }
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<maxim(a,b,c)<<endl;
    cout<<minim(a,b,c)<<endl;
    int n1 =maxim(a,b,c);
    int n2 =minim(a,b,c);
    dif(n1,n2);
    return 0;
}
