#include <bits/stdc++.h>
using namespace std;
void f_10_2_z(long x){//��ʮ��������ת���ɶ���������  
	char a[10];
	int i=0;
	if(x==0)cout<<x;
	while(x){
		a[i++]=x%2+48;//+48�ǽ�����ת������Ӧ��ASCII����ֵ  
		x/=2;
	}
	int l=strlen(a);
	for(int j=l-1;j>=0;j--){
		cout<<a[j];
	}
}
void f_10_2_x(double b){//��ʮ����С��ת���ɶ�����С��  
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
		long c=(int)a;  //c������ 
		double b=a-c;  //b��С�� 
		cout<<"0B";
		f_10_2_z(c);  
		if(b){          //��С���Ļ�����Ҫ��С��ת�� 
			f_10_2_x(b);
		}
		cout<<endl;
}

