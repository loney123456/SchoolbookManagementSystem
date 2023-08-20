#include "base.h"
const int maxNum = 1005;

int shift[maxNum];

int Sunday(const string& T, const string& P) {
	int n = T.length();
	int m = P.length();
	// Ĭ��ֵ���ƶ�m+1λ
	for (int i = 0; i < maxNum; i++) {
		shift[i] = m + 1;
	}
	// ģʽ��P��ÿ����ĸ���ֵ������±�
	// ����Ӧ����������ƥ�����ĩλ�ַ�����һλ�ַ��ƶ�����λ������Ҫ���ƶ�λ��
	for (int i = 0; i < m; i++) {
		shift[P[i]] = m - i;
	}
	// ģʽ����ʼλ��������������
	int s = 0;
	// ģʽ���Ѿ�ƥ�䵽��λ��
	int j;
	while (s <= n - m) {
		j = 0;
		while (T[s + j] == P[j]) {
			j++;
			// ƥ��ɹ�
			if (j >= m) {
				return s;
			}
		}
		// �ҵ������е�ǰ��ģʽ��ƥ�����ĩ�ַ�����һ���ַ�
		// ��ģʽ���г�������λ��
		// ����Ҫ��(ģʽ��ĩβ+1)�ƶ�����λ�õĲ���
		s += shift[T[s + m]];
	}
	return -1;
}

int String_Matching(char* str1, char* str2)
{
	// ������ģʽ��
	string T;
	string P;
	T = str1;
	P = str2;
	int res = Sunday(T, P);
	if (res == -1) 
	{
		//cout << "������ģʽ����ƥ�䡣" << endl;
		return 0;//��ʾû���ҵ�
	}
	else 
	{
		//cout << "ģʽ����������λ��Ϊ��" << res + 1 << endl;
		return 1;//��ʾ�ҵ���
	}
}