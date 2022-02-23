/* 암호문3 */

#include <iostream>

using namespace std;

struct Node {
	int num;
	Node* next;
	Node* prev;
};

Node* head;
Node* tail;

Node* getNode(int num) {
	Node *new_num = new struct Node;
	new_num->num = num;
	new_num->prev = nullptr;
	new_num->next = nullptr;
	return (new_num);
}

void init()
{
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

void removeNode(int num) 
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
	delete(to_free);
}

void getList() 
{
	Node * p = head;
	int i = 10;

	while (p->next != tail && i--)
	{
		p = p->next; 
		cout << p->num <<' ';
	}
	cout << endl;
	return;
}

int main()
{
	int T;
	int length, num, cmd;
	char type;
	int	x, y, s;
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (T = 1; T <= 10; T++)
	{
		init();
		cin >> length; //2000-4000
		while (length--)
		{
			cin >> num;
			addNode2Tail(num);
		}
		cin >> cmd; // 250-500
		while (cmd--)
		{
			cin >> type;
			if (type == 'I')
			{
				cin >> x >> y;
				while (y--)
				{
					cin >> s;
					addNode2Num(s, x);
					x++;
				}
			}
			else if (type == 'D')
			{	
				cin >> x >> y;
				while (y--)
					removeNode(x);
			}
			else if (type == 'A')
			{
				cin >> y;
				while (y--)
				{
					cin >> s;
					addNode2Tail(s);
				}
			}
		}
		cout << "#" << T << ' ';
		getList();
	}
}

