#include<bits/stdc++.h>
using namespace std;
string s;
stack<int>val;
stack<char>symbol;//两个栈一个存储数字，一个存储符号 
//操作符之间的优先级的比较
char cmp(char a,char b){
//右括号不会进栈，不必写右括号的优先级 
//遇到右括号就弹出左括号 
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
//返回计算结果
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
//表达式计算的过程
int process(){
	int i=0,num=0;
	while(symbol.top()!='#'||i<s.size()){
		if(s[i]>='0'&&s[i]<='9'){
			//为操作数
			num=0;
			while(s[i]>='0'&&s[i]<='9'){
				num*=10;//比如又10，11这些数， 
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
	symbol.push('#');//栈底用'#'标识 
	while(cin>>s){  //输入字符串表达式 
		cout<<process()<<endl;
	}
	return 0;
}
