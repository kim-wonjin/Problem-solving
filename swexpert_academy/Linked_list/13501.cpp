/*  수열 편집  */

#include <iostream>

using namespace std;

#define MAX_NODE 2010

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

	while (num-- && p->next != tail)
		p = p->next;

	// 들어갈곳 = p->next
	new_data->next = p->next;
	p->next->prev = new_data;

	new_data->prev = p;
	p->next = new_data;
}

void removeNode2Num(int num) 
{
	Node *p = head;
	Node *to_free;

	while (num-- && p->next != tail)
		p = p->next;

	if (p->next == tail)
		return;

	to_free = p->next;
	p->next = p->next->next;
	p->next->prev = p;
}

void findIndex(int index)
{
	Node *p = head;

	while (index-- && p->next != tail)
		p = p->next;

	cout << p->next->data << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, test_case, i, num, x, y;
	int N, M, L;
	char type;

	cin >> T; //test case 
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> M>> L;  

		while (N--)
		{
			cin >> num;
			addNode2Tail(num);
		}
		while (M--)
		{
			cin >> type;
			if (type == 'I')
			{
				cin >> x >> y;
				addNode2Num(y, x);
			}
			else if (type == 'D')
			{	
				cin >> x;
				removeNode2Num(x);
			}
			else if (type == 'C')
			{
				cin >> x >> y;
				removeNode2Num(x);
				addNode2Num(y, x);
			}
		}
		cout << "#" << test_case << ' ';
		findIndex(L);
	}
}