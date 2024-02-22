#include<iostream>
#include<algorithm>
using namespace std;

int a[200],n;
//升序
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n+1);//注意，因为输入的时候是从1开始的，sort的位置右边为最后一个元素的下一位，所以要n+1
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}

//升序：sort(begin,end,less<data-type>())一般默认为升序，所以less<data-type>()可以不加
//降序：sort(begin, end, greater<data - type>())
//降序法一
/*int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n+1, greater<int >());
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}*/
//降序法二
//自定义比较大小的函数，将大的数排前面
/*bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n+1, cmp);
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}*/