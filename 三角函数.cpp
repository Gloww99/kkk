#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926
double sinx(double a){
	return sin((a*PI)/180);
}
double cosx(double a){
	return cos((a*PI)/180);
}
double tanx(double a){
	return tan((a*PI)/180);
}
double asinx(double a){
	return asin((a*PI)/180);
}
double acosx(double a){
	return acos((a*PI)/180);
}
double atanx(double a){
	return atan((a*PI)/180);
}
int main(){
	double x;
	cin>>x;
	cout<<sinx(x)<<endl;
	cout<<cosx(x)<<endl;
	cout<<tanx(x)<<endl;
	cout<<asinx(x)<<endl;
	cout<<acosx(x)<<endl;
	cout<<atanx(x)<<endl;
}
