// 지민이는 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다.
// 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다.
// 지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.
// 보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다.
// 첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
// 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.
// 첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int main(void)  {
	int n, m, sn = 8, sm = 8, arr[50][50] = {0,};
	char board;
	int a = 0, b = 0, check = 119, cnt = 0, min = 2500;
	
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++)  {
		for(int j = 0; j < m; j++)  {
			scanf("%c ", &board);
			arr[i][j] = board;
		}
	}

	while(sn <= n)  {
		b = 0;
		sm = 8;
		while(sm <= m)  {
			for(a; a < sn; a++)  {
				for(b; b < sm; b++)  {
					if(arr[a][b] != check)
						cnt++;
	
					if(check % 2 == 1)
						check = 98;
					else
						check = 119;
				}
			}
		if(cnt < min)
			min = cnt;
		cnt = 0;

		b++;
		sm++;
		}
	a++;
	sn++;
	}

	a = 0;
	sn = 0;
	check = 98;

	while(sn <= n)  {
                b = 0;
                sm = 8;
                while(sm <= m)  {
                        for(a; a < sn; a++)  {
                                for(b; b < sm; b++)  {
                                        if(arr[a][b] != check)
                                                cnt++;

                                        if(check % 2 != 1)
                                                check = 98;
                                        else
                                                check = 119;
                                }
                        }
                if(cnt < min)
                        min = cnt;
                cnt = 0;

                b++;
                sm++;
                }
        a++;
        sn++;
        }
	
	printf("%d\n", min);

	return 0;
}	// W = 119, B = 98
