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
	cout << " --2.十进制整数混合四则运算--------" << endl;
	cout << endl;
	cout << " --3.二进制四则运算--------" << endl;
	cout << endl;
	cout << " --4.十六进制四则运算--------" << endl;
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
	cout << " --13.十进制转为二进制--------" << endl;
	cout << endl;
	cout << "********************************" << endl;
}
//自动识别函数进制类型并转为十进制 
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
					l1=i;//以小数点所在的位置为分割点 
				}
			}
			start=2+j;// 
			for(int i=start;i<l1;i++){
				sum1=(a[i]-48)+sum1*2;//整数部分*2; 
			}
			for(int i=l-1;i>l1;i--){
				sum=(a[i]-48)*double(1.0/2.0)+sum*double(1.0/2.0);
				//小数部分成1/2; 
			}
			if(j){//负数则用0来减 
				sum2=0-(sum+sum1);
				cout<<sum2<<endl;
			}
			else{
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
				sum1=(a[i]-48)+sum1*16;//整数部分*16 
			}
			for(int i=l-1;i>l1;i--){
				sum=(a[i]-48)*double(1.0/16.0)+sum*double(1.0/16.0);
				//小数部分*1/16
			}
			if(j){//负数 
				sum2=0-(sum+sum1);
				cout<<sum2<<endl;
			}
			else{
				sum2=sum+sum1;
				cout<<sum2<<endl;
			} 
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
			if(j){//负数
				sum2=0-(sum+sum1);
				cout<<sum2<<endl;
			}
			else{
				sum2=sum+sum1;
				cout<<sum2<<endl;
			}
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
int process_10(string s){
	int i=0,num=0;
	while(symbol.top()!='#'||i<s.size()){
		if(s[i]>='0'&&s[i]<='9'){
			//为操作数
			num=0;
			while(s[i]>='0'&&s[i]<='9'){
				num*=10;//比如又10，11这些数， 
				num+=s[i]-'0'; //转为整数 
				++i;
			}
			val.push(num);//把数字入栈 
			//cout<<"num="<<num<<endl; 
		}
		else{
			switch(cmp(symbol.top(),s[i])){//将字符栈顶和当前字符比较 
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
					val.pop();  //取出val连续两个栈顶数字 
					val.push(cal(b,a,symbol.top()));//计算 
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
void process_2(char k[100]){
	//目前仅支持无符号数 
	char w;
	int total=2;
	int n=strlen(k);
	char a[100];//存二进制数 
	double c[100];//转换后的数 
	int count=0,count1=0,count2=0;
		for(int i=0;i<n;i++){
		  if(k[i]=='0'||k[i]=='1'||k[i]=='b'||k[i]=='B'){
			if(k[i+1]=='0'||k[i+1]=='1'||k[i+1]=='b'||k[i+1]=='B'){
			  a[count++]=k[i];//存一串二进制数 
			}
			else{
				a[count++]=k[i];
				double z=identify(a);
			    //cout<<z<<endl;
			    c[count2++]=z; //转换成的十进制
			    count=0;
			}
		}
		else{
			//b[count1++]=k[i];//存运算符 
			if(i<n-1){
				w=k[i];
			}
		}
	}
	for(int i=0;i<1;i++){
		if(w=='+'){
		cout<<c[i]+c[i+1]<<endl;
	    }
	    if(w=='-'){
		  cout<<c[i]-c[i+1]<<endl;
	    }
	    if(w=='/'){
		  cout<<c[i]/c[i+1]<<endl;
	    }
	    if(w=='*'){
		  cout<<c[i]*c[i+1]<<endl;
	    }
	}
	
}
//十六进制四则运算
void add_16(char k[8],char f[8]){
	double r=identify(k);
	double s=identify(f);
	cout<<r+s<<endl;
}
void subb_16(char k[8],char f[8]){
	double r=identify(k);
	double s=identify(f);
	cout<<r-s<<endl;
}
void multt_16(char k[8],char f[8]){
	double r=identify(k);
	double s=identify(f);
	cout<<r*s<<endl;
}
void modd_16(char k[8],char f[8]){
	double r=identify(k);
	double s=identify(f);
	cout<<r/s<<endl;
} 
//十进制对数计算 
double logNumber(double a, double b){//a为底数 
	return log(b)/log(a);
} 
//幂运算 
int power(int a,int b)
{
    int ans=1;
    for(int i=1;i<=b;i++)
    {
        ans*=a;
    }
    return ans;
}
//正弦函数计算 
double sinx(double a){
	return sin((a*PI)/180);
}
//余弦函数计算 
double cosx(double a){
	return cos((a*PI)/180);
}
//正切函数计算 
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
//任意两进制数比较
void compared(char f[8],char g[8] ){
	double a1=identify(f);
	double a2=identify(g);
	if(a1>a2)cout<<"两数相比：f>g"<<endl;
	if(a1<a2)cout<<"两数相比：f<g"<<endl;
	if(a1==a2)cout<<"两数相比：f=g"<<endl;
} 
//最大公约数
int gcd(int m,int n){  
    while(n != 0){
        int rem = m%n;
        m = n;
        n = rem;
    }//计算余数直到余数是0为止，最后的非0余数就是最大公因数。
    return m;
} 
//最小公倍数 
int lcm (int c,int d) 
{
	return c*d/gcd(c,d);
}
//一元一次方程 
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
void f_10_2_z(long x){//将十进制整数转换成二进制整数  
	char a[10];
	int i=0;
	if(x==0)cout<<x;
	if(x<0){
		x=fabs(x);
	}
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
	//int lc=strlen(c);
	for(int k=0;k<count;k++){
		cout<<c[k];
	}
}
void change(double a){
	    long c=(int)a;  //c是整数 
		double b=a-c;  //b是小数 
		if(a<0)cout<<"-";
		cout<<"0B";
		f_10_2_z(c);  
		if(b){
			f_10_2_x(b);
		} 
		cout<<endl;
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
				cout<<"请输入待求值的十进制表达式(可包含括号)："; 
				symbol.push('#');//栈底用'#'标识 
	            cin>>s; //输入字符串表达式 
	           	cout<<process_10(s)<<endl; 
				break;
			}
			case(3):{
				char k[100];
	            cout<<"请输入待求值的二进制表达式(不支持括号)：";
	            cin>>k;
	            process_2(k);
				break;
			}
			case(4):{
				char k[8],f[8];
	            char w;
	            cout<<"--a 十六进制加法"<<endl ;
	            cout<<"--b 十六进制减法"<<endl ;
	            cout<<"--c 十六进制乘法"<<endl ;
	            cout<<"--d 十六进制除法"<<endl; 
	            char p;
	            cout<<"请选择四则运算类型：" ;
	            cin>>p;
	            switch(p){
		            case('a'):{
			           cout<<"请输入两个数：";
		        	   cin>>k>>f;
			           add_16(k,f); 
	        		   break;
		            }
		            case('b'):{
		        	   cout<<"请输入两个数：";
			           cin>>k>>f;
		        	   subb_16(k,f);
		        	   break;
		            }
		           case('c'):{
			           cout<<"请输入两个数：";
			           cin>>k>>f;
			           multt_16(k,f);
			           break;
		            }
		            case('d'):{
			           cout<<"请输入两个数：";
			           cin>>k>>f;
			           modd_16(k,f);
			           break;
		            }
	            } 
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
			    cout<<"--d 反正弦函数"<<endl;
			    cout<<"--e 反余切函数"<<endl;
			    cout<<"--f 反正切函数"<<endl;
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
					case('d'):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case('e'):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case('f'):{
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
				compared(f,g);
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
			case(13):{ //将十进制转换为二进制 
			    cout<<"请输入十进制数："; 
				double a;
	            cin>>a;
		        change(a);
				break;
			}
			default:{
				cin>>x;
				break;
			}
		}
	}
} 
