#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
//endld 的作用换行+清空缓冲区
using namespace std;
//使用cin从标准输入读取数据时，通常用到的方法有    cin>>，  cin.get，  cin.getline。 后面2个都不忽略前面的结束符 //cin.clear();  cin.ignore清除缓冲区
/*
（1）cin >> 等价于cin.operator>>()，即调用成员函数operator >> ()进行读取数据。
（2）当cin >> 从缓冲区中读取数据时，若缓冲区中第一个字符是空格、tab或换行这些分隔符时，cin >> 会将其忽略并清除，
继续读取下一个字符，若缓冲区为空，则继续等待。但是如果读取成功，字符后面的分隔符是残留在缓冲区的，cin >> 不做处理。

（3）不想略过空白字符，那就使用 noskipws 流控制。比如cin >> noskipws >> input;
*/
int main()
{
#if 0
	//cin
	int a, b;
	cin >> a >> b;   //cin >> 对缓冲区中对前面的字符视而不见，采取的措施是忽略清除，继续阻塞等待缓冲区有效数据的到来
	cout << " " << a << " " << b << endl;
	string test;
	getline(cin, test);//不阻塞getline()读取数据时，并非像cin >> 忽略前的字符，
	                   //只要发现前面的缓存区有东西就输出,(连输入都省略了)，将缓冲区字符串补上为空字符’\0’
	cout << "test:" << test << endl;
	//这2个可以连起来输入	char a;
	char b='A';
	a = cin.get();
	//会读取缓冲区的残留数据（cin.get()从输入缓冲区读取单个字符时不忽略分隔符）
	cin.get(a);
	cin.get(b);
	cout << a << b << endl;
#endif
#if 0
	//cin.get 与getline//cin.getline与cin.get的区别是，cin.getline不会将结束符或者换行符残留在输入缓冲区中(自己输入的结束符)。
	char a;
	char array[20] = { NULL };//读取一行时，遇到换行符时结束读取，但是不对换行符进行处理，换行符仍然残留在输入缓冲区。
	//第二次由cin.get()将换行符读入变量b，打印输入换行符的ASCII码值为10。
	//因为没对缓冲区\n处理所以下次获取时会直接将\n读出。
	cin.get(array, 20);
	cin.get(a);
	cout << array << " " << (int)a << endl;

	//getline读取一行字符时，默认遇到’\n’时终止，
	//并且将’\n’直接从输入缓冲区中删除掉，不会影响下面的输入处理。
	char array[20] = { NULL };
	char a = 'a';
	//cin.getline(array, 20); 
	//cin.get(a);
	cin.getline(array,20,'A');//以指定结束符，结束例以A为结束符
	cout << array <<" "<<a<< endl;
	
#endif

#if 0
	//缓冲区的清空
	char str1[20] = { NULL }, str2[20] = { NULL };
	cin.getline(str1, 5);
	cin.clear();  // 清除错误标志   
	cin.ignore(numeric_limits<std::streamsize>::max(),'\n'); // 清除cin里所有内容//当输入缓冲区没有数据时，也会阻塞等待数据的到来。
	//程序中使用cin.ignore清空了输入缓冲区的当前行，
	//使上次的输入残留下的数据没有影响到下一次的输入，这就是ignore()函数的主要作用
	//numeric_limits::max()不过是头文件定义的流使用的最大值，你也可以用一个足够大的整数代替它。 
	cin.getline(str2, 20); 
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;
#endif
	while (1);
	return 0;
}
