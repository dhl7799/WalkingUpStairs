#include<iostream>
#include <cstring>
using namespace std;


//https://www.acmicpc.net/problem/2579


int main() {
	int n = 0; //��� ��
	int straight = 0; //�����ؼ� ��������� ����� ����
	int stcount = 0; //SArray ���� 
	int spcount = 0; //SPoint ����
	printf("��ܼ��� �Է��ϼ���:");
	scanf("%d", &n);
	printf("\n");
	
	if (n < 0 || n>300) {
		printf("N�� ������ ������ϴ�\n");
		return 0;
	}

	int* SPoint = new int[n]; //��ܺ� ���� �迭
	int* SArray = new int[n]; //�ѹ��� �ö󰥶� ���� �ִ�����

	memset(SPoint, 0, n); //spoint�迭 0���� �ʱ�ȭ
	memset(SArray, 0, n); //sarray�迭 0���� �ʱ�ȭ

	printf("��ܺ� ������ �Է��ϼ���:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &SPoint[i]);
		if (SPoint[i] > 10000 || SPoint[i] < 0)
		{
			printf("������ ������ ������ϴ�\n");
			return 0;
		}
	}

	SArray[0] = SPoint[0];

	while (spcount < n - 1)
	{
		stcount++;
		SArray[stcount] = SArray[stcount - 1];
		
		if (SPoint[spcount + 1] > SPoint[spcount + 2] && straight == 0 && spcount + 2 < n-1)
		{
			SArray[stcount] += SPoint[spcount + 1];
			spcount += 1;
			straight += 1;
		}
		else if (spcount == n - 2)
		{
			SArray[stcount] += SPoint[spcount + 1];
			spcount += 1;
			straight = 1;
		}
		else
		{
			SArray[stcount] += SPoint[spcount + 2];
			spcount += 2;
			straight =0;
		}
	}

	printf("\n\n");
	for (int i = 0; i < stcount+1; i++)
	{
		printf("%d\n", SArray[i]);
	}
	printf("\n\n");

	printf("�� ���� = %d\n", SArray[stcount]);

	return 0;
}