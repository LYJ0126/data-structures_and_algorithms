/*int cnt = 0;     // ����Ʒ���·�����˳��
    for (int i = 1; i <= n; i ++)
    {
        int a, b, s;    // a ���, b ��ֵ, s ÿ����Ʒ�ĸ���
        scanf("%d %d %d", &a, &b, &s);

        int k = 1;   // �����Ʋ�� ���ʱÿ������ k ��ͬ����Ʒ
        while (k <= s)  // ��y��˵��: ���һ�����Ʒ���� < 2^(n+1)   1 2 4 8 16 ... 2^n 2^(n+1)
        {
            cnt ++;
            v[cnt] = a * k;  // ÿ������
            w[cnt] = b * k;  // ÿ��ļ�ֵ
            s -= k;
            k *= 2;  // ע���� k * 2��ÿ������һ��������k * k
        }

        if (s > 0)   // �����Ʋ����֮�� ʣ�µ���Ʒ������Ϊ�µ�һ��
        {
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
*/

#include <iostream>
#include<cmath>

using namespace std;

const int N = 11 * 1000 + 10, M = 2010;

int v[N], w[N];
int f[M];

int main()
{
    int  n, m;
    scanf("%d %d", &n, &m);

    int cnt = 0;     // ����Ʒ���·�����˳��
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;    // a ���, b ��ֵ, s ÿ����Ʒ�ĸ���
        scanf("%d %d %d", &a, &b, &s);

        int k = 1;   // �����Ʋ�� ���ʱÿ������ k ��ͬ����Ʒ
        while (k <= s)  // ��y��˵��: ���һ�����Ʒ���� < 2^(n+1)   1 2 4 8 16 ... 2^n 2^(n+1)
        {
            cnt++;
            v[cnt] = a * k;  // ÿ������
            w[cnt] = b * k;  // ÿ��ļ�ֵ
            s -= k;
            k *= 2;  // ע���� k * 2��ÿ������һ��������k * k
        }

        if (s > 0)   // �����Ʋ����֮�� ʣ�µ���Ʒ������Ϊ�µ�һ��
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    n = cnt;  // ���е�������Ϊ 01�����е���Ʒ����

    // д01����ģ��
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    printf("%d", f[m]);

    return 0;
}

