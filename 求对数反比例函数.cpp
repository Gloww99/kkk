#include <bits/stdc++.h>
using namespace std;
//�������� 
double logNumber(double a, double b){//aΪ���� 
	return log(b)/log(a);
}
//����������
double fanNumber(double k,double x){
	return k/x;
} 
int main(){
	double a,b;
	cin>>a>>b;
	cout<<logNumber(a,b)<<endl;
	cout<<fanNumber(a,b)<<endl;
}
