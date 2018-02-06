#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;
class String
{
	private:
	char *_str;
	public:
	String(char* str=NULL):_str(str)//初始化构造函数
	{
		if(str!=NULL)
		{
			_str=new char[strlen(str)+1];
			strcpy(_str,str);
		}
	}
	String(const String&other):_str(other._str)//必须用拷贝构造函数
	{
		if(other._str!=NULL)
		{
			_str=new char[strlen(other._str)+1];
			strcpy(_str,other._str);
		}
	}
	String operator+(String other)//+重载
{
	int len=strlen(_str)+strlen(other._str);
	if(len==0)
		return String();
	else
	{
		char* buffer=new char [len+1];
		strcpy(buffer,_str);
		strcat(buffer,other._str);
		String result(buffer);
		delete[]buffer;
		return result;
	}
}
bool operator!()//重载!
{
	if(_str==NULL||strlen(_str)==0)
		return true;
	else
        return false;

}
 operator int()//强转
{
    int num;
    num=atoi(_str);
    return num;
}
String operator+=(String other)//重载+=
{
	int len=strlen(_str)+strlen(other._str);
	if(len==0)
		return *this;
	else
	{
		char* buffer=new char[len+1];
		strcpy(buffer,_str);
		strcat(buffer,other._str);
		delete[]_str;
		_str=buffer;
		return *this;
	}
}
char &operator[](int index)//重载中括号
{
    return _str[index];
}
bool operator>(String other)
{
    return !strcmp(other._str,_str);
}
friend ostream& operator<<(ostream&out,String &d);//重载输出流
String toupper()
{
    int l=strlen(_str);
    for(int i=0;i<l;i++)
    {
        if(_str[i]>='a'&&_str[i]<='z')
            _str[i]-=32;
    }
    return _str;
}
String tolower()
{
   int l=strlen(_str);
      for(int i=0;i<l;i++)
    {
        if(_str[i]>='A'&&_str[i]<='Z')
            _str[i]+=32;
    }
    return _str;
}
String tmn()
{   char q[100];
    int l=strlen(_str);//指向最后一位
    int j=0;
    int i=0;
    int u=0;
     while(_str[i]==' ')
     {
         i++;//指针移动
     }
     while(_str[l-1]==' ')
        l--;
     for(int k=i;k<=l;k++)
     {
         q[u++]=_str[k];
     }
    q[u]='\0';
    return q;

}
String& operator=(const String &other)//重载=
{
if(other._str)
{
    delete _str;
    char*t=new char[strlen(other._str)+1];
    strcpy(t,other._str);

    _str=t;

}
else
{
    _str=0;

}
 return *this;
}
};

ostream& operator<<(ostream&out,String &d)
{
    out<<d._str;
    return out;
}
int main()
{
String m("123");
String a="Hello";
String b=a,c;
c=b;
String d="world";
b=a+d;
cout<<"a+d="<<b<<endl;
d+=a;
bool f=a>b;
cout<<"f="<<f<<endl;
String str=" ee  abc   d";
cout<<"去空格前:"<<str<<endl;
String str1=str.tmn();
String e=a.toupper();
cout<<"e="<<e<<endl;
String t=a.tolower();
cout<<"t="<<t<<endl;
char xx=str[1];
cout<<"x=str[1]="<<xx<<endl;
int x=int (m);
cout<<"实数化m："<<x<<endl;
cout<<"去空格后"<<str1<<endl;
str[0]='b';
return 0;

}
