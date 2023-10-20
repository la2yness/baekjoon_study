// 첫째 줄에 a, b, c (1 ≤ a, b, c ≤ 100)가 주어진다.
// 각 막대의 길이는 양의 정수이고, 삼각형의 둘레를 최대로 해야 한다.
// a, b, c가 주어졌을 때, 만들 수 있는 가장 큰 둘레를 구하는 프로그램을 작성하시오. 

#include <stdio.h>

int main(void)	{
	int a, b, c, max, sum2;
	scanf("%d%d%d", &a, &b, &c);

	max = a;
	sum2 = b + c;

	if(b >= max)	{
		max = b;
		sum2 = a + c;
	}

	if(c >= max)	{
		max = c;
		sum2 = a + b;
	}

	if(sum2 <= max)
		max = sum2 - 1;

	printf("%d\n", sum2 + max);

	return 0;
}
