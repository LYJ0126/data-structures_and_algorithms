
//ע�⣺ѡ�������ȶ�
//	�ȶ��㷨��ָ�����������������д���ֵ��ȵ�Ԫ�أ���������֮�����Ԫ��֮��ԭ�е��Ⱥ�˳�򲻱䡣
//	����˵��5��8��5��2��9 ����һ�����ݣ�ʹ��ѡ�������㷨������Ļ�����һ���ҵ���СԪ�� 2�����һ�� 5 ����λ�ã�
//�ǵ�һ�� 5 ���м�� 5 ˳��ͱ��ˣ����ԾͲ��ȶ��ˡ�������ˣ������ð������Ͳ�������ѡ���������΢ѷɫ�ˡ�
#include<iostream>
#include<algorithm>
using namespace std;

void selectsort(int a[], int len)//lenΪ����
{
	//������a�ĵ�һλ(i==0)��ʼ��һֱ�������ڶ�λ���������ȷ����λ���ϵ���
	int minidex;
	for (int i = 0; i < len - 1; i++)
	{
		minidex = i;//���Կ�ʼ��i���λ��Ϊ��С��λ�ã�minidexָ��ӵ�iλ��ʼ��������������С����λ��
		for (int j = i + 1; j < len; j++)
		{
			//�����ĳ����jλ�ϵ�����a[minidex]С������minidex
			if (a[j] < a[minidex])
				minidex = j;
		}
		swap(a[i], a[minidex]);
	}
}
int n,a[200];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	selectsort(a, n);
	for (int i = 0; i < n; i++) cout << a[i]<<" ";
	return 0;
}