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
	cout << " --2.ʮ���ƻ����������--------" << endl;
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
	cout << " --14.ʮ����תΪʮ������--------" << endl;
	cout << endl;
	cout << "********************************" << endl;
}
//�Զ�ʶ�����������Ͳ�תΪʮ���� 
double identify(char a[8]){
	    int l=strlen(a);
		int start,j;
		double sum=0,sum1=0,sum2;
		bool b=true;
		if(a[0]=='-'){
			j=1; //��������a[1]��ʼʶ�𣬼���������  
		} 
		else j=0;//��������a[0]��ʼʶ�� 
		
		if(a[j]=='0'&&(a[j+1]=='B'||a[j+1]=='b')){
				cout<<"�������Ϊ������������Ӧʮ��������";
			int l1=l;
			for(int i=0;i<l;i++){
				if(a[i]=='.'){
					l1=i;//��С�������ڵ�λ��Ϊ�ָ�� 
				}
			}
			start=2+j;//����ǰ��ķ��ż����Ƶı�ʶ  
			for(int i=start;i<l1;i++){
				sum1=(a[i]-48)+sum1*2;//��������*2; 
			}
			for(int i=l-1;i>l1;i--){
				sum=(a[i]-48)*double(1.0/2.0)+sum*double(1.0/2.0);
				//С�����ֳ� 0.5; 
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
			start=2+j;//������ֵ���ʼλ��  
			int l1=l;
			for(int i=0;i<l;i++){
				if(a[i]=='.'){//���'.'��λ��  
					l1=i;
				}
			}
			for(int i=start;i<l1;i++){//��������*16
				if(a[i]>='0'&&a[i]<='9'){
					sum1=(a[i]-48)+sum1*16; 
				} 
				else {
					sum1=(a[i]-'A'+10)+sum1*16;
				}
			}
			for(int i=l-1;i>l1;i--){//С������*1/16
				if(a[i]>='0'&&a[i]<='9'){
					sum=(a[i]-48)*double(1.0/16.0)+sum*double(1.0/16.0);
				}
				else {
					sum=(a[i]); 
				}
				
			}
			if(j){//���� 
				sum2=0-(sum+sum1);
				cout<<sum2<<endl;
			}
			else{//����  
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
			else{//����  
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
//���ʽ����Ĺ���
double process_10(string s){
	int i=0,j,point=0;
	double num=0;
	while(symbol.top()!='#'||s[i]!= '='){
		if((s[i]>='0'&&s[i]<='9')||s[i]=='.'){
            num=0;   //��ʼ������0
			point=0;//point��������Ƿ����С�����Լ���ǰ����С������xλ��point==10^x
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
                if(!point){//��������
				    num=num*10+(s[j]-'0');
                }
                else{  //С������
                    num=num+1.0*(s[j]-'0')/point;  //С������
                    point*= 10;  //С��λ������һλ
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

//�������� 
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
//ʮ���ƶ������� 
double logNumber(double a, double b){//aΪ���� 
	return log(b)/log(a);
} 
//������ 
double power(double a,double b)
{
    double ans=1;
    for(int i=1;i<=b;i++)
    {
        ans*=a;
    }
    return ans;
}
double expx (double x){//��e��x���ݵ�ֵ
   return exp(x);
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
	    long c=(int)m;  //c������ 
		double b=m-c;  //b��С�� 
		cout<<"0B";
		f_10_2_z(c); 
		if(b>0){
			f_10_2_x(b);
		} 
		cout<<endl;
}
//ʮ����תΪʮ�������������� 
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
//ʮ����תΪʮ������С������ 
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
				cout<<"��������Ⱥŵ�ʮ���Ʊ��ʽ��"; 
				symbol.push('#');//ջ����'#'��ʶ 
	            cin>>s; //�����ַ������ʽ 
	           	cout<<process_10(s)<<endl; 
				break;
			}
			case(3):{
	            char k[8],f[8];
	            char w;
	            cout<<"--1 �����Ƽӷ�"<<endl ;
	            cout<<"--2 �����Ƽ���"<<endl ;
	            cout<<"--3 �����Ƴ˷�"<<endl ;
	            cout<<"--4 �����Ƴ���"<<endl; 
	            int  p;
	            cout<<"��ѡ�������������ͣ�" ;
	            cin>>p;
	            switch(p){
		            case(1):{
			           cout<<"��������������";
		        	   cin>>k>>f;
			           double l=add(k,f); 
			           cout<<"��Ϊ��";
			           changeTo_2(l);
			           cout<<endl;
	        		   break;
		            }
		            case(2):{
		        	   cout<<"��������������";
			           cin>>k>>f;
		        	   double l=subb(k,f);
		        	   cout<<"��Ϊ��";
					   changeTo_2(l);
					   cout<<endl;
		        	   break;
		            }
		           case(3):{
			           cout<<"��������������";
			           cin>>k>>f;
			           double l=multt(k,f);
			           cout<<"�˻�Ϊ��";
			           changeTo_2(l);
			           cout<<endl;
			           break;
		            }
		            case(4):{
			           cout<<"��������������";
			           cin>>k>>f;
			           double l=modd(k,f);
			           cout<<"��Ϊ��"<<l;
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
	            cout<<"--1 ʮ�����Ƽӷ�"<<endl ;
	            cout<<"--2 ʮ�����Ƽ���"<<endl ;
	            cout<<"--3 ʮ�����Ƴ˷�"<<endl ;
	            cout<<"--4 ʮ�����Ƴ���"<<endl; 
	            int p;
	            cout<<"��ѡ�������������ͣ�" ;
	            cin>>p;
	            switch(p){
		            case(1):{
			           cout<<"��������������";
		        	   cin>>k>>f;
		        	   double l=add(k,f);
		        	   cout<<"����֮��Ϊ��";
		        	   changeTo_16(l);
			           //cout<<add(k,f)<<endl;
					   cout<<endl; 
	        		   break;
		            }
		            case(2):{
		        	   cout<<"��������������";
			           cin>>k>>f;
		        	   double l=subb(k,f);
		        	   cout<<"����֮��Ϊ��";
		        	   changeTo_16(l);
		        	   cout<<endl;
		        	   break;
		            }
		           case(3):{
			           cout<<"��������������";
			           cin>>k>>f;
			           //cout<<multt(k,f)<<endl;
			           double l=multt(k,f);
			           cout<<"����֮��Ϊ��";
		        	   changeTo_16(l);
		        	   cout<<endl;
			           break;
		            }
		            case(4):{
			           cout<<"��������������";
			           cin>>k>>f;
			          // cout<<modd(k,f)<<endl;
			           double l=modd(k,f);
					   cout<<"�������Ϊ��";
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
				cout<<"�����������ָ����";
				cin>>a>>b;
				cout<<logNumber(a,b)<<endl;
				break;
			} 
			case(6):{//������ 
				double a,b;
				cout<<"--1 ������ָ����������"<<endl; 
				cout<<"--2 ��eΪ�ף�������ָ��"<<endl;
				int k;
				cin>>k;
				switch(k){
					case(1):{
					cout<<"�����������ָ����" ;
	                cin>>a>>b;
	                cout<<power(a,b)<<endl;
					break;
				}
				case(2):{
					cout<<"������ָ����";
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
			case(7):{//���Ǻ�������
			    cout<<"--1 ���Һ���"<<endl ;
			    cout<<"--2 ���Һ���"<<endl ;
			    cout<<"--3 ���к���"<<endl ;
			    cout<<"--4 �����Һ���"<<endl;
			    cout<<"--5 �����к���"<<endl;
			    cout<<"--6 �����к���"<<endl;
			    int p;
				cout<<"��ѡ�����Ǻ������ͣ�" ;
				cin>>p;
				switch(p){
					case(1):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<sinx(x)<<endl; 
						break;
					}
					case(2):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<cosx(x)<<endl;
						break;
					}
					case(3):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case(4):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case(5):{
						double x;
						cout<<"������һ������";
						cin>>x;
						cout<<tanx(x)<<endl;
						break;
					}
					case(6):{
						double x;
						cout<<"������һ������";
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
			case(8):{//���������������Ƚ� 
			    char f[8],g[8];
			    cout<<"��������������������f, g��";
				cin>>f>>g;
				compared(f,g);
				break;
			}
			case(9):{
			    //int a,b;
			    char a[8],b[8];
			    cout<<"����������������������";
	            cin>>a>>b;
	            double c=identify(a);
	            double d=identify(b);
	            cout<<"a,b�Ĺ�Լ��Ϊʮ���ƣ�"<<gcd(c,d)<<endl;
	            cout<<"a,b����С������Ϊʮ���ƣ�"<<lcm(c,d)<<endl;
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
	            /*double m;
                cin>>m;
                changeTo_2(m);*/
                double a;
                cin>>a;
	            long c=(int)a;  //c������ 
	        	double b=a-c;  //b��С�� 
		        cout<<"0B";
		        f_10_2_z(c);
				if(b>0.0){
					f_10_2_x(b);
				}  
		        
		        cout<<endl;
				break;
			}
			case(14):{
				cout<<"������ʮ��������";
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
