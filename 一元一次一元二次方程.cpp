#include <bits/stdc++.h>
using namespace std;
//һԪһ�η��� 
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
//һԪ���η��� 
void erci(double x,double y,double z){
	double a,b,c,d;
	double x1,x2;
	a=x;
	b=y;
	c=z;
	if(a==0){
		cout<<"�˷���ΪһԪһ�η���,���Ľ�Ϊ��";
		cout<<yici(b,c)<<endl;
	}
	else{
	    d=b*b-4*a*c;
	    if(d>0){
		  x1=(-b+sqrt(d))/(2*a);
		  x2=(-b-sqrt(d))/(2*a);
		  cout<<"��������ͬ��ʵ��"<<x1<<" "<<x2<<endl;
	    }
	    else if(d==0){
		  x1=x2=(-b)/(2*a);
		  cout<<"��������ͬ��ʵ��"<<x1<<x2<<endl;
	    }
	    else{
		   /*x1=x2=-0.000;
		   cout<<x1<<x2<<endl;*/ 
		   cout<<"��ʵ��"<<endl; 
	    }
	}
	
}
int main(){
	double x,y,z;  //a*x^2+b*x+c=0;
	cin>>x>>y>>z;
//	cout<<yici(b,c);
	erci(x,y,z);
	
}
