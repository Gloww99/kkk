#include <bits/stdc++.h>
using namespace std;
//一元一次方程 
double yici(double e,double f){
	double z;
	if(e!=0){
	    z=-f/e;
	    return z;
	}
	else{
		if(f==0){
		  return -0.00;
		  
		}
	}
}
//一元二次方程 
void erci(double x,double y,double z){
	double a,b,c,d;
	double x1,x2;
	a=x;
	b=y;
	c=z;
	if(a==0){
		cout<<"此方程为一元一次方程,它的解为：";
		cout<<yici(b,c)<<endl;
	}
	else{
	    d=b*b-4*a*c;
	    if(d>0){
		  x1=(-b+sqrt(d))/(2*a);
		  x2=(-b-sqrt(d))/(2*a);
		  cout<<"有两个不同的实根"<<x1<<" "<<x2<<endl;
	    }
	    else if(d==0){
		  x1=x2=(-b)/(2*a);
		  cout<<"有两个相同的实根"<<x1<<x2<<endl;
	    }
	    else{
		   /*x1=x2=-0.000;
		   cout<<x1<<x2<<endl;*/ 
		   cout<<"无实根"<<endl; 
	    }
	}
	
}
int main(){
	double x,y,z;  //a*x^2+b*x+c=0;
	cin>>x>>y>>z;
//	cout<<yici(b,c);
	erci(x,y,z);
	
}
