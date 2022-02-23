/* 이중 연결리스트 연습문제 */

//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

void init();
void addNode2Head(int data);
void addNode2Tail(int data);
void addNode2Num(int data, int num);
int findNode(int data);
void removeNode(int data);
int getList(int output[MAX_NODE]);
int getReversedList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
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
	//freopen("dll_input.txt", "r", stdin);

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
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
Node* tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(-1);
	tail = getNode(-1);
	head->next = tail;
	tail->prev = head;
}

void addNode2Head(int data) 
{
	Node *new_data = getNode(data);

	new_data->next = head->next;
	head->next->prev = new_data;

	new_data->prev = head;
	head->next = new_data;
}

void addNode2Tail(int data) 
{
	Node *new_data = getNode(data);
 
	new_data->prev = tail->prev;
	tail->prev->next = new_data;

	new_data->next = tail;
	tail->prev = new_data;
}

void addNode2Num(int data, int num) 
{
	Node *new_data = getNode(data);
	Node * p = head;

	num--;
	while (num-- && p->next != tail)
		p = p->next;

	// 들어갈곳 = p->next
	new_data->next = p->next;
	p->next->prev = new_data;

	new_data->prev = p;
	p->next = new_data;
}

int findNode(int data) 
{
	Node * p = head;
	int num = 1;
	
	while (p->next != tail && p->next->data != data)
	{
		p = p->next;
		num++;
	}	
	if (p->next == tail)
		return 0;
	return (num);
}

void removeNode(int data) 
{
	Node * p = head;

	while (p->next != tail && p->next->data != data)
		p = p->next;

	p->next = p->next->next;
	p->next->prev = p;
}

int getList(int output[MAX_NODE]) 
{
	Node * p = head;
	int i = 0;

	while (p->next != tail)
	{
		p = p->next; 
		output[i++] = p->data;
	}
	return (i);
}

int getReversedList(int output[MAX_NODE]) 
{
	Node * p = tail;
	int i = 0;

	while (p->prev != head)
	{
		p = p->prev; 
		output[i++] = p->data;
	}
	return (i);
}