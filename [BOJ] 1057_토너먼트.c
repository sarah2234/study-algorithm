#include <stdio.h>
#include <stdlib.h>

int* queue = NULL;
int N;
int front = -1, rear = -1;
void enqueue(int card);
int dequeue();	

int main()
{
	int deleteCard = -1;
	int insertCard = 1;
	scanf("%d", &N);
	queue = (int*)malloc(sizeof(int) * N);
	for (int i = 1; i <= N; i++)
	{
		enqueue(i);
	}
	while (1)
	{
		if (dequeue() == 0)
			break;
		insertCard = dequeue();
		enqueue(insertCard);
	}
	printf("%d", insertCard);
	return 0;
}

void enqueue(int card)
{
	if ((rear + 1) % N == front)
		return;
	queue[++rear] = card;
}

int dequeue()
{
	if (front == rear)
		return 0;
	card = queue[++front];
	queue[front] = NULL;
	return card;
}