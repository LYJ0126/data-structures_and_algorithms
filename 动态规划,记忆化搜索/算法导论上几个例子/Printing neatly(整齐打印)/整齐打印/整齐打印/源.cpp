#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<climits>
using namespace std;

int main(void)
{
	void zq_print(void);


	zq_print();
	return 0;
}

void zq_print(void)
{
	//输入数据
	int num, M, count;
	int p, q, i, j, flag;


	cin >> num;
	cin >> M;
	string* data = new string[num];
	for (i = 0; i < num; i++)
	{
		cin >> data[i];
	}

	int* line = new int[num]();
	int* c = new int[num];

	memset(c, 0, num);

	p = 0; flag = 0; q = 0; count = 0;
	while (p < num)
	{
		line[q] = INT_MAX;
		for (i = p; i < num;)
		{
			/*计算的累加值*/
			int sum = 0;
			for (j = p; j <= i; j++)
				sum += data[j].size();
			//计算3次方
			int temp = (M - i + p - sum) * (M - i + p - sum) * (M - i + p - sum);
			if (q >= 1)
				temp += line[q - 1];
			if (temp >= 0 && (temp < line[q]))
			{
				flag = i;
				c[q] = flag;
				line[q] = temp;
				i++;
			}
			else
				break;
			//现在判断flag的值，是不是到达最后一行
		}

		++q;
		++count;
		if (flag == num - 1)
			break;
		else
			p = flag + 1;
	}

	cout << "count=" << count << endl;
	for (i = 0; i < count; i++)
	{
		cout << c[i] << "--->" << line[i] << endl;
	}
	//共count行
	for (i = 0; i < count; i++)
	{
		int begin = 0;
		if (i > 0)
			begin = c[i - 1] + 1;

		for (j = begin; j <= c[i]; ++j)
			cout << data[j] << " ";
		cout << endl;
	}

	delete[] c;
	delete[] line;
	delete[] data;
}