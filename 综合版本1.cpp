# include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926
string s;
stack<int>val;
stack<char>symbol;//两个栈一个存储数字，一个存储符号 
//菜单函数 
void menu()
{
	cout << " ****计算器****" << endl;
	cout << endl;
	cout << " --1.自动识别进制，并转换为十进制-------" << endl;
	cout << endl;
	cout << " --2.带括号的十进制四则运算--------" << endl;
	cout << endl;
	cout << " --3.带括号的二进制四则运算--------" << endl;
	cout << endl;
	cout << " --4.带括号的十六进制四则运算--------" << endl;
	cout << endl;
	cout << " --5.十进制对数计算--------" << endl;
	cout << endl;
	cout << " --6.十进制幂运算--------" << endl;
	cout << endl;
	cout << " --7.三角函数计算--------" << endl;
	cout << endl;
	cout << " --8.任意两进制数的比较运算--------" << endl;
	cout << endl;
	cout << " --9.最小公倍数、最大公约数--------" << endl;
	cout << endl;
	cout << " --10.一元二次函数--------" << endl;
	cout << endl;
	cout << " --11.一元一次函数--------" << endl;
	cout << endl;
	cout << " --12.反比例函数计算--------" << endl;
	cout << endl;
	cout << "********************************" << endl;
}
//进制识别函数
int identify(char a[8]){
	int l=strlen(a);
		int start,j;
		double sum=0,sum1=0,sum2;
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
				sum2=0-(sum+sum1);
				//cout<<0-(sum+sum1)<<endl;
				cout<<sum2<<endl;
			}
			else{
				//cout<<sum+sum1<<endl;
				sum2=sum+sum1;
				cout<<sum2<<endl;
			} 
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
				sum2=0-(sum+sum1);
				//cout<<0-(sum+sum1)<<endl;
				cout<<sum2<<endl;
				//cout<<0-(sum+sum1)<<endl;
			}
			else{
				sum2=sum+sum1;
				cout<<sum2<<endl;
			} //cout<<sum+sum1<<endl;
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
				sum2=0-(sum+sum1);
				//cout<<0-(sum+sum1)<<endl;
				cout<<sum2<<endl;
				//cout<<0-(sum+sum1)<<endl;
			}
			else{
				sum2=sum+sum1;
				cout<<sum2<<endl;
			} //cout<<sum+sum1<<endl;
	    }
	    return sum2;
}
//十进制四则运算
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
 int process(string s){
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
			//cout<<"num="<<num<<endl; 
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
					//cout<<"a="<<a<<" "<<"b="<<b<<endl;
					//cout<<"num="<<val.top()<<endl;
					symbol.pop();
					break;
			}
		}
	}
	int res=val.top();
	val.pop();
	return res;
} 
//十进制对数计算 
double logNumber(double a, double b){//a为底数 
	return log(b)/log(a);
} 
//快速幂 
int power(int a,int b)
{
    int r=1,base=a;
    while(b!=0)
    {
        if(b%2){
          r*=base;
          base*=base;
          b/=2;	
		} 
    }
    return r;
}
double sinx(double a){
	return sin((a*PI)/180);
}
double cosx(double a){
	return cos((a*PI)/180);
}
double tanx(double a){
	return tan((a*PI)/180);
}
int gcd(int m,int n){ //最大公约数 
    while(n != 0){
        int rem = m%n;
        m = n;
        n = rem;
    }//计算余数直到余数是0为止，最后的非0余数就是最大公因数。
    return m;
} 
int lcm (int c,int d) //最小公倍数 
{
	return c*d/gcd(c,d);
}
void yici(double e,double f){
	double z;
	if(e!=0&&f!=0){
	    z=-f/e;
	    cout<<z<<endl;
	}
	else{
		if(f==0){
		  cout<<"解为任意值"<<endl;
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
		yici(b,c);
	}
	else{
	    d=b*b-4*a*c;
	    if(d>0){
		  x1=(-b+sqrt(d))/(2*a);
		  x2=(-b-sqrt(d))/(2*a);
		  if(x1==-0){
		  	x1=0;
		  }
		  if(x2==-0){
		  	x2=0;
		  }
		  cout<<"有两个不同的实根"<<x1<<" "<<x2<<endl;
	    }
	    else if(d==0){
		  x1=x2=(-b)/(2*a);
		  cout<<"有两个相同的实根"<<x1<<x2<<endl;
	    }
	    else{ 
		   cout<<"无实根"<<endl; 
	    }
	}
	
}
//反比例函数
double fanNumber(double k,double x){
	return k/x;
} 
int main(){
	menu();
	while(1){
		int x;
		cout<<"请选择功能：";
		cin>>x; 
		switch(x){
			case(1):{
				char a[8];
				cout<<"请输入二或十或十六进制数：";
				cin>>a; 
				identify(a);
				break;
			}
			case(2):{
				cout<<"请输入需要求值的表达式："; 
				symbol.push('#');//栈底用'#'标识 
	            cin>>s; //输入字符串表达式 
	           	cout<<process(s)<<endl;
				break;
			}
			case(3):{
				//二进制四则运算 
				break;
			}
			case(4):{
				//十六进制四则运算 
				break;
			}
			case(5):{
				double a,b;
				cout<<"请输入底数和指数：";
				cin>>a>>b;
				cout<<logNumber(a,b)<<endl;
				break;
			} 
			case(6):{//幂运算 
				int a,b;
	            cout<<"请输入底数，指数：" ;
	            cin>>a>>b;
	            cout<<power(a,b)<<endl;
				break;
			}
			case(7):{//三角函数计算
			    cout<<"--a 正弦函数"<<endl ;
			    cout<<"--b 余弦函数"<<endl ;
			    cout<<"--c 正切函数"<<endl ;
			    char p;
				cout<<"请选择三角函数类型：" ;
				cin>>p;
				switch(p){
					case('a'):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<sinx(x)<<endl; 
						break;
					}
					case('b'):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<cosx(x)<<endl;
						break;
					}
					case('c'):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
				} 
				
				break;
			}
			case(8):{//任意两个进制数比较 
			    char f[8],g[8];
			    cout<<"请输入任意两个进制数f, g：";
				cin>>f>>g;
				double a1=identify(f);
				double a2=identify(g);
				if(a1>a2)cout<<"两数相比：f>g"<<endl;
				if(a1<a2)cout<<"两数相比：f<g"<<endl;
				if(a1==a2)cout<<"两数相比：f=g"<<endl;
				break;
			}
			case(9):{
			    int a,b;
			    cout<<"请输入任意两个十进制整数：";
	            cin>>a>>b;
	            cout<<"a,b的公约数为："<<gcd(a,b)<<endl;
	            cout<<"a,b的最小公倍数为："<<lcm(a,b)<<endl;
				break;
			}
			case(10):{
				double x,y,z;  //a*x^2+b*x+c=0;
				cout<<"请输入二次系数、一次系数、常数：";
	            cin>>x>>y>>z;
	            erci(x,y,z);
				break;
			}
			case(11):{
				double y,z;  //a*x^2+b*x+c=0;
				cout<<"请输入一次系数、常数：";
	            cin>>y>>z;
	            yici(y,z);
				break;
			}
			case(12):{
				double k,x;
	            cout<<"请输入k,x:";
	            cin>>k>>x;
	            cout<<fanNumber(k,x)<<endl;
				break;
			}
		}
	}
} 
