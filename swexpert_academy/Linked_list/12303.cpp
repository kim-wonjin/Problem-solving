/* 단일 연결리스트 연습문제 */

//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

void init();
void addNode2Head(int data);
void addNode2Tail(int data);
void addNode2Num(int data, int num);
void removeNode(int data);
int getList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	//freopen("sll_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}

/* user code */

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) 
{
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = new struct Node;
	head->data = -1;
	head->next = nullptr;
}

void addNode2Head(int data) 
{
	Node *new_data = getNode(data);
	new_data->next = head->next;
	head->next = new_data;
}

void addNode2Tail(int data) 
{
	Node *new_data = getNode(data);
	Node * p = head;
	int i = 0;

	while (p->next != nullptr)
		p = p->next; 
	p->next = new_data;
}

void addNode2Num(int data, int num) 
{
	Node *new_data = getNode(data);
	Node * p = head;

	num--;
	while (num-- && p->next)
		p = p->next;
	new_data->next = p->next;
	p->next = new_data;
}

void removeNode(int data) 
{
	Node * p = head;

	while (p->next && p->next->data != data)
		p = p->next;
	if (p->next == nullptr)
		return;
	p->next = p->next->next;
}

int getList(int output[MAX_NODE]) 
{
	Node * p = head;
	int i = 0;

	while (p->next != nullptr)
	{
		p = p->next; 
		output[i++] = p->data;
	}
	return (i);
}