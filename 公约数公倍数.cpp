#include <bits/stdc++.h>
using namespace std;
int gcd(int m,int n){ //���Լ�� 
    while(n != 0){
        int rem = m%n;
        m = n;
        n = rem;
    }//��������ֱ��������0Ϊֹ�����ķ�0�����������������
    return m;
} 
int lcm (int c,int d) //��С������ 
{
	return c*d/gcd(c,d);
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<"a,b�Ĺ�Լ��Ϊ��"<<gcd(a,b)<<endl;
	cout<<"a,b����С������Ϊ��"<<lcm(a,b)<<endl;
} 
