# include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926
string s;
stack<int>val;
stack<char>symbol;//����ջһ���洢���֣�һ���洢���� 
//�˵����� 
void menu()
{
	cout << " ****������****" << endl;
	cout << endl;
	cout << " --1.�Զ�ʶ����ƣ���ת��Ϊʮ����-------" << endl;
	cout << endl;
	cout << " --2.�����ŵ�ʮ������������--------" << endl;
	cout << endl;
	cout << " --3.�����ŵĶ�������������--------" << endl;
	cout << endl;
	cout << " --4.�����ŵ�ʮ��������������--------" << endl;
	cout << endl;
	cout << " --5.ʮ���ƶ�������--------" << endl;
	cout << endl;
	cout << " --6.ʮ����������--------" << endl;
	cout << endl;
	cout << " --7.���Ǻ�������--------" << endl;
	cout << endl;
	cout << " --8.�������������ıȽ�����--------" << endl;
	cout << endl;
	cout << " --9.��С�����������Լ��--------" << endl;
	cout << endl;
	cout << " --10.һԪ���κ���--------" << endl;
	cout << endl;
	cout << " --11.һԪһ�κ���--------" << endl;
	cout << endl;
	cout << " --12.��������������--------" << endl;
	cout << endl;
	cout << "********************************" << endl;
}
//����ʶ����
int identify(char a[8]){
	int l=strlen(a);
		int start,j;
		double sum=0,sum1=0,sum2;
		bool b=true;
		if(a[0]=='-'){
			j=1; //���� 
		} 
		else j=0;//���� 
		
		if(a[j]=='0'&&(a[j+1]=='B'||a[j+1]=='b')){
				cout<<"�������Ϊ������������Ӧʮ��������";
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
			cout<<"�������Ϊʮ������������Ӧʮ��������";
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
			cout<<"�������Ϊʮ����������Ӧʮ��������";
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
//ʮ������������
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
 int process(string s){
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
//ʮ���ƶ������� 
double logNumber(double a, double b){//aΪ���� 
	return log(b)/log(a);
} 
//������ 
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
int gcd(int m,int n){ //���Լ�� 
    while(n != 0){
        int rem = m%n;
        m = n;
        n = rem;
    }//��������ֱ��������0Ϊֹ�����ķ�0�����������������
    return m;
} 
int lcm (int c,int d) //��С������ 
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
		  cout<<"��Ϊ����ֵ"<<endl;
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
		  cout<<"��������ͬ��ʵ��"<<x1<<" "<<x2<<endl;
	    }
	    else if(d==0){
		  x1=x2=(-b)/(2*a);
		  cout<<"��������ͬ��ʵ��"<<x1<<x2<<endl;
	    }
	    else{ 
		   cout<<"��ʵ��"<<endl; 
	    }
	}
	
}
//����������
double fanNumber(double k,double x){
	return k/x;
} 
int main(){
	menu();
	while(1){
		int x;
		cout<<"��ѡ���ܣ�";
		cin>>x; 
		switch(x){
			case(1):{
				char a[8];
				cout<<"���������ʮ��ʮ����������";
				cin>>a; 
				identify(a);
				break;
			}
			case(2):{
				cout<<"��������Ҫ��ֵ�ı��ʽ��"; 
				symbol.push('#');//ջ����'#'��ʶ 
	            cin>>s; //�����ַ������ʽ 
	           	cout<<process(s)<<endl;
				break;
			}
			case(3):{
				//�������������� 
				break;
			}
			case(4):{
				//ʮ�������������� 
				break;
			}
			case(5):{
				double a,b;
				cout<<"�����������ָ����";
				cin>>a>>b;
				cout<<logNumber(a,b)<<endl;
				break;
			} 
			case(6):{//������ 
				int a,b;
	            cout<<"�����������ָ����" ;
	            cin>>a>>b;
	            cout<<power(a,b)<<endl;
				break;
			}
			case(7):{//���Ǻ�������
			    cout<<"--a ���Һ���"<<endl ;
			    cout<<"--b ���Һ���"<<endl ;
			    cout<<"--c ���к���"<<endl ;
			    char p;
				cout<<"��ѡ�����Ǻ������ͣ�" ;
				cin>>p;
				switch(p){
					case('a'):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<sinx(x)<<endl; 
						break;
					}
					case('b'):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<cosx(x)<<endl;
						break;
					}
					case('c'):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
				} 
				
				break;
			}
			case(8):{//���������������Ƚ� 
			    char f[8],g[8];
			    cout<<"��������������������f, g��";
				cin>>f>>g;
				double a1=identify(f);
				double a2=identify(g);
				if(a1>a2)cout<<"������ȣ�f>g"<<endl;
				if(a1<a2)cout<<"������ȣ�f<g"<<endl;
				if(a1==a2)cout<<"������ȣ�f=g"<<endl;
				break;
			}
			case(9):{
			    int a,b;
			    cout<<"��������������ʮ����������";
	            cin>>a>>b;
	            cout<<"a,b�Ĺ�Լ��Ϊ��"<<gcd(a,b)<<endl;
	            cout<<"a,b����С������Ϊ��"<<lcm(a,b)<<endl;
				break;
			}
			case(10):{
				double x,y,z;  //a*x^2+b*x+c=0;
				cout<<"���������ϵ����һ��ϵ����������";
	            cin>>x>>y>>z;
	            erci(x,y,z);
				break;
			}
			case(11):{
				double y,z;  //a*x^2+b*x+c=0;
				cout<<"������һ��ϵ����������";
	            cin>>y>>z;
	            yici(y,z);
				break;
			}
			case(12):{
				double k,x;
	            cout<<"������k,x:";
	            cin>>k>>x;
	            cout<<fanNumber(k,x)<<endl;
				break;
			}
		}
	}
} 
