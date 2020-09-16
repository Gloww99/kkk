#include <bits/stdc++.h>
using namespace std;
//对数函数 
double logNumber(double a, double b){//a为底数 
	return log(b)/log(a);
}
//反比例函数
double fanNumber(double k,double x){
	return k/x;
} 
int main(){
	double a,b;
	cin>>a>>b;
	cout<<logNumber(a,b)<<endl;
	cout<<fanNumber(a,b)<<endl;
}
