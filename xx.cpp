#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
//endld �����û���+��ջ�����
using namespace std;
//ʹ��cin�ӱ�׼�����ȡ����ʱ��ͨ���õ��ķ�����    cin>>��  cin.get��  cin.getline�� ����2����������ǰ��Ľ����� //cin.clear();  cin.ignore���������
/*
��1��cin >> �ȼ���cin.operator>>()�������ó�Ա����operator >> ()���ж�ȡ���ݡ�
��2����cin >> �ӻ������ж�ȡ����ʱ�����������е�һ���ַ��ǿո�tab������Щ�ָ���ʱ��cin >> �Ὣ����Բ������
������ȡ��һ���ַ�����������Ϊ�գ�������ȴ������������ȡ�ɹ����ַ�����ķָ����ǲ����ڻ������ģ�cin >> ��������

��3�������Թ��հ��ַ����Ǿ�ʹ�� noskipws �����ơ�����cin >> noskipws >> input;
*/
int main()
{
#if 0
	//cin
	int a, b;
	cin >> a >> b;   //cin >> �Ի������ж�ǰ����ַ��Ӷ���������ȡ�Ĵ�ʩ�Ǻ�����������������ȴ���������Ч���ݵĵ���
	cout << " " << a << " " << b << endl;
	string test;
	getline(cin, test);//������getline()��ȡ����ʱ��������cin >> ����ǰ���ַ���
	                   //ֻҪ����ǰ��Ļ������ж��������,(�����붼ʡ����)�����������ַ�������Ϊ���ַ���\0��
	cout << "test:" << test << endl;
	//��2����������������	char a;
	char b='A';
	a = cin.get();
	//���ȡ�������Ĳ������ݣ�cin.get()�����뻺������ȡ�����ַ�ʱ�����Էָ�����
	cin.get(a);
	cin.get(b);
	cout << a << b << endl;
#endif
#if 0
	//cin.get ��getline//cin.getline��cin.get�������ǣ�cin.getline���Ὣ���������߻��з����������뻺������(�Լ�����Ľ�����)��
	char a;
	char array[20] = { NULL };//��ȡһ��ʱ���������з�ʱ������ȡ�����ǲ��Ի��з����д������з���Ȼ���������뻺������
	//�ڶ�����cin.get()�����з��������b����ӡ���뻻�з���ASCII��ֵΪ10��
	//��Ϊû�Ի�����\n���������´λ�ȡʱ��ֱ�ӽ�\n������
	cin.get(array, 20);
	cin.get(a);
	cout << array << " " << (int)a << endl;

	//getline��ȡһ���ַ�ʱ��Ĭ��������\n��ʱ��ֹ��
	//���ҽ���\n��ֱ�Ӵ����뻺������ɾ����������Ӱ����������봦��
	char array[20] = { NULL };
	char a = 'a';
	//cin.getline(array, 20); 
	//cin.get(a);
	cin.getline(array,20,'A');//��ָ������������������AΪ������
	cout << array <<" "<<a<< endl;
	
#endif

#if 0
	//�����������
	char str1[20] = { NULL }, str2[20] = { NULL };
	cin.getline(str1, 5);
	cin.clear();  // ��������־   
	cin.ignore(numeric_limits<std::streamsize>::max(),'\n'); // ���cin����������//�����뻺����û������ʱ��Ҳ�������ȴ����ݵĵ�����
	//������ʹ��cin.ignore��������뻺�����ĵ�ǰ�У�
	//ʹ�ϴε���������µ�����û��Ӱ�쵽��һ�ε����룬�����ignore()��������Ҫ����
	//numeric_limits::max()������ͷ�ļ��������ʹ�õ����ֵ����Ҳ������һ���㹻��������������� 
	cin.getline(str2, 20); 
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;
#endif
	while (1);
	return 0;
}
