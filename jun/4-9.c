// 도현이는 바구니를 총 N개 가지고 있고, 바구니에는 1번부터 N번까지 번호가 매겨져 있다.
// 앞으로 M번 바구니의 순서를 역순으로 만들려고 한다. 한 번 순서를 역순으로 바꿀 때, 순서를 역순으로 만들 범위를 정하고, 그 범위에 들어있는 바구니의 순서를 역순으로 만든다.
// 첫째 줄에 N과 M이 주어진다.
// 둘째 줄부터 M개의 줄에는 바구니의 순서를 역순으로 만드는 방법이 주어진다. 방법은 i j로 나타내고, 왼쪽으로부터 i번째 바구니부터 j번째 바구니의 순서를 역순으로 만든다는 뜻이다.
// M번 바구니의 순서를 역순으로 만든 다음 가장 왼쪽에 있는 바구니부터 바구니에 적혀있는 순서를 공백으로 구분해 출력한다.

#include <stdio.h>
#include <stdlib.h>

int main(void)	{
	int a, b, n, m, i, j, count;

	scanf("%d%d", &n, &m);

	int *basket = (int *)malloc(sizeof(int) * (n + 1));
	int *buffer = (int *)malloc(sizeof(int) * (n + 1));
		
	for(int a = 1; a <= n; a++)
		basket[a] = a;
	
	for(int b = 0; b < m; b++)	{
		scanf("%d%d", &i, &j);

		count = i;

		for(a = 1; a <= n; a++)
			buffer[a] = basket[a];
		
		for(int x = j - i; x >= i - j; x -= 2)	{
			buffer[count + x] = basket[count];	
			count++;
		}

		for(a = 1; a <= n; a++)
                        basket[a] = buffer[a];
	}

	for(a = 1; a <= n; a++)
		printf("%d ", basket[a]);

	printf("\n");

	return 0;
}
