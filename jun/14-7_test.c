// 자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다.
// 첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다.
// 둘째 줄에는 집합 A의 모든 원소가, 셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 주어진다.
// 각 집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.
// 이때, 두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오.

#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;	// hashTable이라는 이름으로 bucket 주소값 선언
int BUCKET_SIZE = 200000;		// bucket의 총 길이는 200,000

// node 구조체 선언
struct node  {
	int key;		// 해시 함수에 사용될 key
	int value;		// key가 가지고 있는 실제 값
	struct node* next;	// 다음 노드를 가르키는 포인터
};

// bucket 구조체 선언
struct bucket  {
	struct node* head;	// bucket 맨 앞 노드의 포인터
	int count;		// bucket에 들어있는 노드의 개수
};

// hashtable이 삽입될 때 새로 노드를 생성해주는 함수
struct node* createNode(int key, int value)  {
	struct node* newNode;
	// 메모리 할당
	newNode = (struct node*)malloc(sizeof(struct node));
	// 사용자가 정해준 값 대입
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

// 해시함수 만들기
int hashFunction(int key)  {
	return key % BUCKET_SIZE;
}

// 새 key를 추가하는 함수
void add(int key, int value)  {
	// 어느 bucket에 추가할지 인덱스를 계산
	int hashIndex = hashFunction(key);
	// 새 노드 생성
	struct node* newNode = createNode(key, value);
	// 계산한 인덱스의 bucket에 아무 노드도 없을 경우
	if (hashTable[hashIndex].count == 0)  {
		hashTable[hashIndex].count = 1;
		hashTable[hashIndex].head = newNode;	// head 교체
	}
	// bucket에 노드가 있을경우 한칸씩 뒤로 밀고 newNode가 헤드가 된다
	else  {
		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;
	}
}

// key를 주면 value를 알려주는 함수
int search(int key){
    int hashIndex = hashFunction(key);
    struct node* node = hashTable[hashIndex].head;
    int flag = 0;
    while (node != NULL)
    {
        if (node->key == key){
            flag = 1;
            break;
        }
        node = node->next;
    }
    if (flag == 1) // 키를 찾았다면
        return node->value;
}

int main()  {
	// 해시테이블 메모리 할당
	hashTable = (struct bucket*)malloc(BUCKET_SIZE * sizeof(struct bucket));

	int A, B, cntA, cntB, i, j, IS = 0;

	scanf("%d%d", &cntA, &cntB);
	
	for (i = 0; i < cntA; i++)  {
		scanf("%d", &A);
		add(A, A);
	}
	for (j = 0; j < cntB; j++)  {
		scanf("%d", &B);
		// 입력받은 값이 B를 키로 가지는 해시테이블의 value와 같은지 확인	
		if (B == search(B))
			IS++;
	}

	printf("%d\n", cntA + cntB - 2 * IS);
	
	free(hashTable);

	return 0;
}
