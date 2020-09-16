#include <bits/stdc++.h>
using namespace std;
int gcd(int m,int n){ //最大公约数 
    while(n != 0){
        int rem = m%n;
        m = n;
        n = rem;
    }//计算余数直到余数是0为止，最后的非0余数就是最大公因数。
    return m;
} 
int lcm (int c,int d) //最小公倍数 
{
	return c*d/gcd(c,d);
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<"a,b的公约数为："<<gcd(a,b)<<endl;
	cout<<"a,b的最小公倍数为："<<lcm(a,b)<<endl;
} 
