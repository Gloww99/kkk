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
	cout << " --2.ʮ�������������������--------" << endl;
	cout << endl;
	cout << " --3.��������������--------" << endl;
	cout << endl;
	cout << " --4.ʮ��������������--------" << endl;
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
	cout << " --13.ʮ����תΪ������--------" << endl;
	cout << endl;
	cout << "********************************" << endl;
}
//�Զ�ʶ�����������Ͳ�תΪʮ���� 
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
					l1=i;//��С�������ڵ�λ��Ϊ�ָ�� 
				}
			}
			start=2+j;// 
			for(int i=start;i<l1;i++){
				sum1=(a[i]-48)+sum1*2;//��������*2; 
			}
			for(int i=l-1;i>l1;i--){
				sum=(a[i]-48)*double(1.0/2.0)+sum*double(1.0/2.0);
				//С�����ֳ�1/2; 
			}
			if(j){//��������0���� 
				sum2=0-(sum+sum1);
				cout<<sum2<<endl;
			}
			else{
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
				sum1=(a[i]-48)+sum1*16;//��������*16 
			}
			for(int i=l-1;i>l1;i--){
				sum=(a[i]-48)*double(1.0/16.0)+sum*double(1.0/16.0);
				//С������*1/16
			}
			if(j){//���� 
				sum2=0-(sum+sum1);
				cout<<sum2<<endl;
			}
			else{
				sum2=sum+sum1;
				cout<<sum2<<endl;
			} 
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
			if(j){//����
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
int process_10(string s){
	int i=0,num=0;
	while(symbol.top()!='#'||i<s.size()){
		if(s[i]>='0'&&s[i]<='9'){
			//Ϊ������
			num=0;
			while(s[i]>='0'&&s[i]<='9'){
				num*=10;//������10��11��Щ���� 
				num+=s[i]-'0'; //תΪ���� 
				++i;
			}
			val.push(num);//��������ջ 
			//cout<<"num="<<num<<endl; 
		}
		else{
			switch(cmp(symbol.top(),s[i])){//���ַ�ջ���͵�ǰ�ַ��Ƚ� 
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
					val.pop();  //ȡ��val��������ջ������ 
					val.push(cal(b,a,symbol.top()));//���� 
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
	//Ŀǰ��֧���޷����� 
	char w;
	int total=2;
	int n=strlen(k);
	char a[100];//��������� 
	double c[100];//ת������� 
	int count=0,count1=0,count2=0;
		for(int i=0;i<n;i++){
		  if(k[i]=='0'||k[i]=='1'||k[i]=='b'||k[i]=='B'){
			if(k[i+1]=='0'||k[i+1]=='1'||k[i+1]=='b'||k[i+1]=='B'){
			  a[count++]=k[i];//��һ���������� 
			}
			else{
				a[count++]=k[i];
				double z=identify(a);
			    //cout<<z<<endl;
			    c[count2++]=z; //ת���ɵ�ʮ����
			    count=0;
			}
		}
		else{
			//b[count1++]=k[i];//������� 
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
//ʮ��������������
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
//ʮ���ƶ������� 
double logNumber(double a, double b){//aΪ���� 
	return log(b)/log(a);
} 
//������ 
int power(int a,int b)
{
    int ans=1;
    for(int i=1;i<=b;i++)
    {
        ans*=a;
    }
    return ans;
}
//���Һ������� 
double sinx(double a){
	return sin((a*PI)/180);
}
//���Һ������� 
double cosx(double a){
	return cos((a*PI)/180);
}
//���к������� 
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
//�������������Ƚ�
void compared(char f[8],char g[8] ){
	double a1=identify(f);
	double a2=identify(g);
	if(a1>a2)cout<<"������ȣ�f>g"<<endl;
	if(a1<a2)cout<<"������ȣ�f<g"<<endl;
	if(a1==a2)cout<<"������ȣ�f=g"<<endl;
} 
//���Լ��
int gcd(int m,int n){  
    while(n != 0){
        int rem = m%n;
        m = n;
        n = rem;
    }//��������ֱ��������0Ϊֹ�����ķ�0�����������������
    return m;
} 
//��С������ 
int lcm (int c,int d) 
{
	return c*d/gcd(c,d);
}
//һԪһ�η��� 
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
void f_10_2_z(long x){//��ʮ��������ת���ɶ���������  
	char a[10];
	int i=0;
	if(x==0)cout<<x;
	if(x<0){
		x=fabs(x);
	}
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
	//int lc=strlen(c);
	for(int k=0;k<count;k++){
		cout<<c[k];
	}
}
void change(double a){
	    long c=(int)a;  //c������ 
		double b=a-c;  //b��С�� 
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
				cout<<"���������ֵ��ʮ���Ʊ��ʽ(�ɰ�������)��"; 
				symbol.push('#');//ջ����'#'��ʶ 
	            cin>>s; //�����ַ������ʽ 
	           	cout<<process_10(s)<<endl; 
				break;
			}
			case(3):{
				char k[100];
	            cout<<"���������ֵ�Ķ����Ʊ��ʽ(��֧������)��";
	            cin>>k;
	            process_2(k);
				break;
			}
			case(4):{
				char k[8],f[8];
	            char w;
	            cout<<"--a ʮ�����Ƽӷ�"<<endl ;
	            cout<<"--b ʮ�����Ƽ���"<<endl ;
	            cout<<"--c ʮ�����Ƴ˷�"<<endl ;
	            cout<<"--d ʮ�����Ƴ���"<<endl; 
	            char p;
	            cout<<"��ѡ�������������ͣ�" ;
	            cin>>p;
	            switch(p){
		            case('a'):{
			           cout<<"��������������";
		        	   cin>>k>>f;
			           add_16(k,f); 
	        		   break;
		            }
		            case('b'):{
		        	   cout<<"��������������";
			           cin>>k>>f;
		        	   subb_16(k,f);
		        	   break;
		            }
		           case('c'):{
			           cout<<"��������������";
			           cin>>k>>f;
			           multt_16(k,f);
			           break;
		            }
		            case('d'):{
			           cout<<"��������������";
			           cin>>k>>f;
			           modd_16(k,f);
			           break;
		            }
	            } 
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
			    cout<<"--d �����Һ���"<<endl;
			    cout<<"--e �����к���"<<endl;
			    cout<<"--f �����к���"<<endl;
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
					case('d'):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case('e'):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case('f'):{
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
				compared(f,g);
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
			case(13):{ //��ʮ����ת��Ϊ������ 
			    cout<<"������ʮ��������"; 
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
