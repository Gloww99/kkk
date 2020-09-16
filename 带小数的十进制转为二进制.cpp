#include <bits/stdc++.h>
using namespace std;
void f_10_2_z(long x){//将十进制整数转换成二进制整数  
	char a[10];
	int i=0;
	if(x==0)cout<<x;
	while(x){
		a[i++]=x%2+48;//+48是将整数转换成相应的ASCII码数值  
		x/=2;
	}
	int l=strlen(a);
	for(int j=l-1;j>=0;j--){
		cout<<a[j];
	}
}
void f_10_2_x(double b){//将十进制小数转换成二进制小数  
	char c[10];
	int j=0,count=0;
	while(b){
		c[j++]=(int)(2*b)+48; 
		count++;
		if(count==10){
			break; 
		}
		b=b*2-(int)(2*b);
	}
	cout<<'.';
	for(int k=0;k<count;k++){
		cout<<c[k];
	}
}
int main(){
	    double a;
	    cin>>a;
		long c=(int)a;  //c是整数 
		double b=a-c;  //b是小数 
		cout<<"0B";
		f_10_2_z(c);  
		if(b){          //有小数的话才需要将小数转换 
			f_10_2_x(b);
		}
		cout<<endl;
}

