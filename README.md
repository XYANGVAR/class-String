# class-String
write a String class by c++
自己定义一个字符串类String,使该类实现如下要求：</br>
```
String a=”Hello”;//重载=
String b=a,c;//拷贝构造函数
 c=b;//重载=
String d=”world”;
 d+=a;重载+=
b=a+d;//重载+
bool f=a>d;//重载+
String e=a.toupper();//把字符串都变成大写
String f=a.tolower();//把字符串都变成小写
String m=”123”;
int x=int(m);//把数字字符串强转成整型
String str=”   abc “;
String str1=str.tmn();//去掉字符串中前缀后缀空格
char x=str[1];
str[0]=b;
```
