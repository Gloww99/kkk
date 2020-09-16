#include <bits/stdc++.h>
using namespace std;
int power(int a,int b) //快速幂 
{
    int r=1,base=a;
    while(b!=0)
    {
        if(b%2){
          r*=base;
          base*=base;
          b/=2;	
		} 
    }
    return r;
}
int main(){
	int a,b;
	cout<<"请输入底数，指数：" ;
	cin>>a>>b;
	cout<<power(a,b)<<endl;
}
/*#include <iostream>
using namespace std;
 
int power(int a,int b)
{
    int ans=1;
    for(int i=1;i<=b;i++)
    {
        ans*=a;
    }
    return ans;
}
int main()
{
    int a,b;
    int num;
    while(cin>>a>>b)
    {
        num=power(a,b);
        cout<<num<<'\n';
    }
    return 0;
}*/
