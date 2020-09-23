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
	cout << " --2.十进制混合四则运算--------" << endl;
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
	cout << " --14.十进制转为十六进制--------" << endl;
	cout << endl;
	cout << "********************************" << endl;
}
//自动识别函数进制类型并转为十进制 
double identify(char a[8]){
	    int l=strlen(a);
		int start,j;
		double sum=0,sum1=0,sum2;
		bool b=true;
		if(a[0]=='-'){
			j=1; //负数，从a[1]开始识别，即跳过负号  
		} 
		else j=0;//正数，从a[0]开始识别 
		
		if(a[j]=='0'&&(a[j+1]=='B'||a[j+1]=='b')){
				cout<<"输入的数为二进制数，对应十进制数：";
			int l1=l;
			for(int i=0;i<l;i++){
				if(a[i]=='.'){
					l1=i;//以小数点所在的位置为分割点 
				}
			}
			start=2+j;//跳过前面的符号及进制的标识  
			for(int i=start;i<l1;i++){
				sum1=(a[i]-48)+sum1*2;//整数部分*2; 
			}
			for(int i=l-1;i>l1;i--){
				sum=(a[i]-48)*double(1.0/2.0)+sum*double(1.0/2.0);
				//小数部分乘 0.5; 
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
			start=2+j;//标记数字的起始位置  
			int l1=l;
			for(int i=0;i<l;i++){
				if(a[i]=='.'){//标记'.'的位置  
					l1=i;
				}
			}
			for(int i=start;i<l1;i++){//整数部分*16
				if(a[i]>='0'&&a[i]<='9'){
					sum1=(a[i]-48)+sum1*16; 
				} 
				else {
					sum1=(a[i]-'A'+10)+sum1*16;
				}
			}
			for(int i=l-1;i>l1;i--){//小数部分*1/16
				if(a[i]>='0'&&a[i]<='9'){
					sum=(a[i]-48)*double(1.0/16.0)+sum*double(1.0/16.0);
				}
				else {
					sum=(a[i]); 
				}
				
			}
			if(j){//负数 
				sum2=0-(sum+sum1);
				cout<<sum2<<endl;
			}
			else{//正数  
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
			else{//正数  
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
double cal(double a,double b,char op){
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
bool IsOper(char ch){
   char ptr[7] = {'+','-','*','/','(',')','='};
   int i;
    for(i=0;i<7;i++){
       if(ch == ptr[i]){
   	        return true;
        }
    }
    return false;
}
//表达式计算的过程
double process_10(string s){
	int i=0,j,point=0;
	double num=0;
	while(symbol.top()!='#'||s[i]!= '='){
		if((s[i]>='0'&&s[i]<='9')||s[i]=='.'){
            num=0;   //初始化数字0
			point=0;//point用来标记是否出现小数点以及当前处于小数点后第x位，point==10^x
			if(s[i]=='.'){
            	point=10;
			}
            else{
            	num=s[i]-'0';
			}
            j=i+1;
            while(!IsOper(s[j])){ 
                if(s[j]=='.'){
                    point=10;
                    j++;
                    continue;
                }
                if(!point){//整数部分
				    num=num*10+(s[j]-'0');
                }
                else{  //小数部分
                    num=num+1.0*(s[j]-'0')/point;  //小数部分
                    point*= 10;  //小数位数后移一位
                }
                j++;
            }
            i=j;
			val.push(num);
			//cout<<"num="<<num<<endl; 
		}
		else if(IsOper(s[i])){
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
					double a=val.top();
					val.pop();
					double b=val.top();
					val.pop();
					val.push(cal(b,a,symbol.top()));
					//cout<<"a="<<a<<" "<<"b="<<b<<endl;
					//cout<<"num="<<val.top()<<endl;
					symbol.pop();
					break;
			}
		}
	}
	double res=val.top();
	//cout<<"res:"<<res<<endl;
	val.pop();
	return res;
} 

//四则运算 
double add(char k[8],char f[8]){
	double r=identify(k);
	double s=identify(f);
	//double sum=r+s;
	return r+s;
}
double subb(char k[8],char f[8]){
	double r=identify(k);
	double s=identify(f);
	//cout<<r-s<<endl;
	return r-s;
}
double multt(char k[8],char f[8]){
	double r=identify(k);
	double s=identify(f);
	//cout<<r*s<<endl;
	return r*s;
}

double modd(char k[8],char f[8]){
	double r=identify(k);
	double s=identify(f);
	//cout<<r/s<<endl;
	return r/s;
} 
//十进制对数计算 
double logNumber(double a, double b){//a为底数 
	return log(b)/log(a);
} 
//幂运算 
double power(double a,double b)
{
    double ans=1;
    for(int i=1;i<=b;i++)
    {
        ans*=a;
    }
    return ans;
}
double expx (double x){//求e的x次幂的值
   return exp(x);
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
void changeTo_2(double m){
	/*int n=(int)m;
    double k=m-n;
    if(m<0)cout<<'-';
    cout<<"0x";
    f_10_2_z(n);
    if(k>0){
    	cout<<'.';
    	f_10_2_x(k);
	}*/
	    long c=(int)m;  //c是整数 
		double b=m-c;  //b是小数 
		cout<<"0B";
		f_10_2_z(c); 
		if(b>0){
			f_10_2_x(b);
		} 
		cout<<endl;
}
//十进制转为十六进制整数部分 
void f_10_16_zheng(int n){
	int i=0,x,num[100];
	char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	if(n==0){
		cout<<n;
	}
	if(n<0){
		n=fabs(n);
	}
	while(n>0){
		num[i++]=n%16;
		n=n/16;
	}
	for(i=i-1;i>=0;i--){
		x=num[i];
		cout<<hex[x];
	}
}
//十进制转为十六进制小数部分 
void f_10_16_xiao(double m){
    double temp = 0.0;
    int res;
    int count=0;
    while (!(m == 0) ){
            temp = (m * 16);
            res = static_cast<int>(temp);
            count++;
            if(!(res)||count==10){
            	break;
			}
            m = temp-res;
            cout<<res;  
    }
    cout<<endl;
}
void changeTo_16(double m){
	int n=(int)m;
    double k=m-n;
    if(m<0)cout<<'-';
    cout<<"0x";
    f_10_16_zheng(n);
    if(k>0){
    	cout<<'.';
    	f_10_16_xiao(k);
	}
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
				cout<<"请输入带等号的十进制表达式："; 
				symbol.push('#');//栈底用'#'标识 
	            cin>>s; //输入字符串表达式 
	           	cout<<process_10(s)<<endl; 
				break;
			}
			case(3):{
	            char k[8],f[8];
	            char w;
	            cout<<"--1 二进制加法"<<endl ;
	            cout<<"--2 二进制减法"<<endl ;
	            cout<<"--3 二进制乘法"<<endl ;
	            cout<<"--4 二进制除法"<<endl; 
	            int  p;
	            cout<<"请选择四则运算类型：" ;
	            cin>>p;
	            switch(p){
		            case(1):{
			           cout<<"请输入两个数：";
		        	   cin>>k>>f;
			           double l=add(k,f); 
			           cout<<"和为：";
			           changeTo_2(l);
			           cout<<endl;
	        		   break;
		            }
		            case(2):{
		        	   cout<<"请输入两个数：";
			           cin>>k>>f;
		        	   double l=subb(k,f);
		        	   cout<<"差为：";
					   changeTo_2(l);
					   cout<<endl;
		        	   break;
		            }
		           case(3):{
			           cout<<"请输入两个数：";
			           cin>>k>>f;
			           double l=multt(k,f);
			           cout<<"乘积为：";
			           changeTo_2(l);
			           cout<<endl;
			           break;
		            }
		            case(4):{
			           cout<<"请输入两个数：";
			           cin>>k>>f;
			           double l=modd(k,f);
			           cout<<"商为："<<l;
			           changeTo_2(l);
			           cout<<endl;
			           break;
		            }
		            default:{
						break;
					}
	            } 
				break;
			}
			case(4):{
				char k[8],f[8];
	            char w;
	            cout<<"--1 十六进制加法"<<endl ;
	            cout<<"--2 十六进制减法"<<endl ;
	            cout<<"--3 十六进制乘法"<<endl ;
	            cout<<"--4 十六进制除法"<<endl; 
	            int p;
	            cout<<"请选择四则运算类型：" ;
	            cin>>p;
	            switch(p){
		            case(1):{
			           cout<<"请输入两个数：";
		        	   cin>>k>>f;
		        	   double l=add(k,f);
		        	   cout<<"两数之和为：";
		        	   changeTo_16(l);
			           //cout<<add(k,f)<<endl;
					   cout<<endl; 
	        		   break;
		            }
		            case(2):{
		        	   cout<<"请输入两个数：";
			           cin>>k>>f;
		        	   double l=subb(k,f);
		        	   cout<<"两数之差为：";
		        	   changeTo_16(l);
		        	   cout<<endl;
		        	   break;
		            }
		           case(3):{
			           cout<<"请输入两个数：";
			           cin>>k>>f;
			           //cout<<multt(k,f)<<endl;
			           double l=multt(k,f);
			           cout<<"两数之积为：";
		        	   changeTo_16(l);
		        	   cout<<endl;
			           break;
		            }
		            case(4):{
			           cout<<"请输入两个数：";
			           cin>>k>>f;
			          // cout<<modd(k,f)<<endl;
			           double l=modd(k,f);
					   cout<<"两数相除为：";
		        	   changeTo_16(l);
		        	   cout<<endl;
			           break;
		            }
		            default:{
						break;
					}
	            } 
				break;
			}
			case(5):{
			    double a,b;
				//char a[8],b[8];
				cout<<"请输入底数和指数：";
				cin>>a>>b;
				cout<<logNumber(a,b)<<endl;
				break;
			} 
			case(6):{//幂运算 
				double a,b;
				cout<<"--1 底数、指数任意输入"<<endl; 
				cout<<"--2 以e为底，需输入指数"<<endl;
				int k;
				cin>>k;
				switch(k){
					case(1):{
					cout<<"请输入底数，指数：" ;
	                cin>>a>>b;
	                cout<<power(a,b)<<endl;
					break;
				}
				case(2):{
					cout<<"请输入指数：";
					cin>>a;
					cout<<expx(a)<<endl;
					break;
				}
				default:{
						break;
					}
				}
	        break;
			}
			case(7):{//三角函数计算
			    cout<<"--1 正弦函数"<<endl ;
			    cout<<"--2 余弦函数"<<endl ;
			    cout<<"--3 正切函数"<<endl ;
			    cout<<"--4 反正弦函数"<<endl;
			    cout<<"--5 反余切函数"<<endl;
			    cout<<"--6 反正切函数"<<endl;
			    int p;
				cout<<"请选择三角函数类型：" ;
				cin>>p;
				switch(p){
					case(1):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<sinx(x)<<endl; 
						break;
					}
					case(2):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<cosx(x)<<endl;
						break;
					}
					case(3):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case(4):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case(5):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case(6):{
						double x;
						cout<<"请输入一个数：";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					default:{
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
			    //int a,b;
			    char a[8],b[8];
			    cout<<"请输入任意两个进制数：";
	            cin>>a>>b;
	            double c=identify(a);
	            double d=identify(b);
	            cout<<"a,b的公约数为十进制："<<gcd(c,d)<<endl;
	            cout<<"a,b的最小公倍数为十进制："<<lcm(c,d)<<endl;
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
	            /*double m;
                cin>>m;
                changeTo_2(m);*/
                double a;
                cin>>a;
	            long c=(int)a;  //c是整数 
	        	double b=a-c;  //b是小数 
		        cout<<"0B";
		        f_10_2_z(c);
				if(b>0.0){
					f_10_2_x(b);
				}  
		        
		        cout<<endl;
				break;
			}
			case(14):{
				cout<<"请输入十进制数：";
				double m;
                cin>>m;
                changeTo_16(m);
				break;
			}
			default:{
				cin>>x;
				break;
			}
		}
	}
} 
