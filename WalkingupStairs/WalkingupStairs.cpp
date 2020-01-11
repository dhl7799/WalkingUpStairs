#include<iostream>
#include <cstring>
using namespace std;


//https://www.acmicpc.net/problem/2579


int main() {
	int n = 0; //계단 수
	int straight = 0; //연속해서 같은계단을 밟는지 점검
	int stcount = 0; //SArray 세기 
	int spcount = 0; //SPoint 세기
	printf("계단수를 입력하세요:");
	scanf("%d", &n);
	printf("\n");
	
	if (n < 0 || n>300) {
		printf("N값 범위를 벗어났습니다\n");
		return 0;
	}

	int* SPoint = new int[n]; //계단별 점수 배열
	int* SArray = new int[n]; //한번씩 올라갈때 마다 최대점수

	memset(SPoint, 0, n); //spoint배열 0으로 초기화
	memset(SArray, 0, n); //sarray배열 0으로 초기화

	printf("계단별 점수를 입력하세요:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &SPoint[i]);
		if (SPoint[i] > 10000 || SPoint[i] < 0)
		{
			printf("점수값 범위를 벗어났습니다\n");
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

	printf("총 점수 = %d\n", SArray[stcount]);

	return 0;
}