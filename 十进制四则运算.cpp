#include<bits/stdc++.h>
using namespace std;
string s;
stack<int>val;
stack<char>symbol;//����ջһ���洢���֣�һ���洢���� 
//������֮������ȼ��ıȽ�
char cmp(char a,char b){
//�����Ų����ջ������д�����ŵ����ȼ� 
//���������ž͵��������� 
    if(a=='#'){
		if(b=='#'){
			return '=';
		}else{
			return '<';
		}
	}
	if(a=='+'||a=='-'){
		if(b=='*'||b=='/'||b=='('){
			return '<';
		}
		else{
			return '>';
		}
	}
	if(a=='*'||a=='/'){
		if(b=='('){
			return '<';
		}
		else{
			return '>';
		}
	}
	if(a=='('){
		if(b==')'){
			return '=';
		}
		else{
			return '<';
		}
	}
} 
//���ؼ�����
int cal(int a,int b,char op){
	switch(op){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}  
//���ʽ����Ĺ���
int process(){
	int i=0,num=0;
	while(symbol.top()!='#'||i<s.size()){
		if(s[i]>='0'&&s[i]<='9'){
			//Ϊ������
			num=0;
			while(s[i]>='0'&&s[i]<='9'){
				num*=10;//������10��11��Щ���� 
				num+=s[i]-'0';
				++i;
			}
			val.push(num);
			cout<<"num="<<num<<endl; 
		}
		else{
			switch(cmp(symbol.top(),s[i])){
				case '<':
					symbol.push(s[i]);
					++i;
					break;
				case '=':
					symbol.pop();
					++i;
					break;
				case '>':
					int a=val.top();
					val.pop();
					int b=val.top();
					val.pop();
					val.push(cal(b,a,symbol.top()));
					cout<<"a="<<a<<" "<<"b="<<b<<endl;
					cout<<"num="<<val.top()<<endl;
					symbol.pop();
					break;
			}
		}
	}
	int res=val.top();
	val.pop();
	return res;
} 
int main(){
	symbol.push('#');//ջ����'#'��ʶ 
	while(cin>>s){  //�����ַ������ʽ 
		cout<<process()<<endl;
	}
	return 0;
}
