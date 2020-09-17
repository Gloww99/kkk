#include <bits/stdc++.h>
using namespace std;
int main(){
	char a[8];
	while(cin>>a){
		int l=strlen(a);
		int start,j;
		double sum=0,sum1=0;
		bool b=true;
		if(a[0]=='-'){
			j=1; //负数 
		} 
		else j=0;//正数 
		
		if(a[j]=='0'&&(a[j+1]=='B'||a[j+1]=='b')){
			cout<<"输入的数为二进制数，对应十进制数："; 
			int l1=l;
			for(int i=0;i<l;i++){
				if(a[i]=='.'){
					l1=i;
				}
			}
			start=2+j;
			for(int i=start;i<l1;i++){
				sum1=(a[i]-48)+sum1*2;
			}
			for(int i=l-1;i>l1;i--){
				sum=(a[i]-48)*double(1.0/2.0)+sum*double(1.0/2.0);
			}
			if(j){
				cout<<0-(sum+sum1)<<endl;
			}
			else cout<<sum+sum1<<endl;
		}	
		else if(a[j]=='0'&&(a[j+1]=='X'||a[j+1]=='x')){
			cout<<"输入的数为十六进制数，对应十进制数：";
			start=2+j; 
			int l1=l;
			for(int i=0;i<l;i++){
				if(a[i]=='.'){
					l1=i;
				}
			}
			for(int i=start;i<l1;i++){
				sum1=(a[i]-48)+sum1*16;
			}
			for(int i=l-1;i>l1;i--){
				sum=(a[i]-48)*double(1.0/16.0)+sum*double(1.0/16.0);
			}
			if(j){
				cout<<0-(sum+sum1)<<endl;
			}
			else cout<<sum+sum1<<endl;
		}
		else {
			cout<<"输入的数为十进制数，对应十进制数：";
			start=j; 
			int l1=l;
			for(int i=0;i<l;i++){
				if(a[i]=='.'){
					l1=i;
				}
			}
			for(int i=start;i<l1;i++){
				sum1=(a[i]-48)+sum1*10;
			}
			for(int i=l-1;i>l1;i--){
				sum=(a[i]-48)*double(1.0/10.0)+sum*double(1.0/10.0);
			}
			if(j){
				cout<<0-(sum+sum1)<<endl;
			}
			else cout<<sum+sum1<<endl;
		}
	}
} 
