#include <iostream>

struct order
{
    int mNumber;
    int mStock;
    int mQuantity;
    int mPrice;
	struct order *next;
	struct order *prev;
};

struct stock
{
    struct order *buy_h;
    struct order *sell_h;
	struct order *buy_t;
    struct order *sell_t;
	int best_profit;
	int lowest_price;
	int recent_price;
};

struct stock stock[5];

void	print_order(void)
{
	int		i;
	order *cur;

	i = 0;
	while (i < 5)
	{
		if (stock[i].buy_h == NULL && stock[i].sell_h == NULL)
		{
			++i;
			continue ;
		}
		printf("\n========== stock[%d] ==========\n", i+1);
		printf("===== buy =====\n");
		cur = stock[i].buy_h;
		while (cur)
		{
			printf("mNumber: %d | ", cur->mNumber);
			printf("mPrice: %d | ", cur->mPrice);
			printf("mQuantity: %d\n", cur->mQuantity);
			cur = cur->next;
		}
		printf("===== sell =====\n");
		cur = stock[i].sell_h;
		while (cur)
		{
			printf("mNumber: %d | ", cur->mNumber);
			printf("mPrice: %d | ", cur->mPrice);
			printf("mQuantity: %d\n", cur->mQuantity);
			cur = cur->next;
		}
		++i;
	}
}

void update_bp(int mStock, int dPrice)
{
	if (stock[mStock].lowest_price == 0 || dPrice < stock[mStock].lowest_price) //init || 최저값 갱신
		stock[mStock].lowest_price = dPrice;
	else if (stock[mStock].recent_price != 0 && stock[mStock].recent_price < dPrice) // 극대일때
	{
		if (dPrice - stock[mStock].lowest_price > stock[mStock].best_profit) // best-profit 갱신
			stock[mStock].best_profit = dPrice - stock[mStock].lowest_price;
	}

	stock[mStock].recent_price = dPrice;
	return;
}

void init()
{
	int i;
	order *p;
	order *dlt;

	for (i = 0; i < 5; i++)
	{
		p = stock[i].buy_h;
		while (p)
		{
			dlt = p;
			p = p->next;
			delete(dlt);
		}
		p = stock[i].sell_h;
		while (p)
		{
			dlt = p;
			p = p->next;
			delete(dlt);
		}
	}
	memset(stock, 0, sizeof(struct stock) * 5);	
}

void dequeue(struct order **head, struct order **tail, struct order *remove)
{
	if (*head == *tail)  //only one
	{
		*head = NULL;
		*tail= NULL;
	}
	else if (*head == remove) //head
	{
		*head = remove->next;
		remove->next->prev = NULL;
	}
	else if (*tail == remove) //tail
	{						
		*tail = remove->prev;
		remove->prev->next = NULL;
	}
	else
	{
		remove->prev->next = remove->next;
		remove->next->prev = remove->prev;
	}
	delete(remove);
}

int get_remain_buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
	struct order *p = stock[mStock].sell_h;
	struct order *dlt;
	int minPrice = -1;
	while (minPrice < mPrice) 
	{
		p = stock[mStock].sell_h;
		minPrice = mPrice;
		while (p != NULL) // 체결가 찾기(최소)
		{
			if (p->mPrice < minPrice)
				minPrice = p->mPrice;
			p = p->next;
		}

		p = stock[mStock].sell_h;
		while (p != NULL)
		{
			if (p->mPrice == minPrice)
			{
				if (mQuantity < p->mQuantity)  // 매수주문량이 매도주문 하나 안에서 해결
				{
					p->mQuantity -= mQuantity;
					update_bp(mStock, minPrice);
					return (0);
				}
				//else
				mQuantity -= p->mQuantity;
				update_bp(mStock, minPrice);
				dlt = p;
				p = p->next;
				dequeue(&stock[mStock].sell_h, &stock[mStock].sell_t, dlt);
				if (!mQuantity)
					return (0);	
			}
			else
				p = p->next;
		}
	}
	return (mQuantity);
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
	mStock--;
	int remain_qty = get_remain_buy(mNumber, mStock, mQuantity, mPrice);

	if (remain_qty)
	{
		struct order *new_order = new struct order;
		new_order->mNumber = mNumber;
		new_order->mStock = mStock;
		new_order->mQuantity = remain_qty;
		new_order->mPrice = mPrice;
		new_order->next = NULL;
		new_order->prev = NULL;
		
		//add
		if (stock[mStock].buy_h == 0) //첫주문
		{
			stock[mStock].buy_h = new_order;
			stock[mStock].buy_t = new_order;
		}
		else
		{
			new_order->prev = stock[mStock].buy_t;
			stock[mStock].buy_t->next = new_order;
			stock[mStock].buy_t = stock[mStock].buy_t->next;
		}
	}
	print_order();
    return (remain_qty);
}

int get_remain_sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
	struct order *p = stock[mStock].buy_h;
	struct order *dlt;
	int maxPrice = mPrice + 1;
	while (maxPrice > mPrice) 
	{
		p = stock[mStock].buy_h;
		maxPrice = mPrice;
		while (p != NULL) // 체결가 찾기(최대)
		{
			if (p->mPrice > maxPrice)
				maxPrice = p->mPrice;
			p = p->next;	
		}

		p = stock[mStock].buy_h;
		while (p != NULL)
		{
			if (p->mPrice == maxPrice)
			{
				if (mQuantity < p->mQuantity)  // 매도주문량이 매수주문 하나 안에서 해결
				{
					p->mQuantity -= mQuantity;
					update_bp(mStock, maxPrice);
					return (0);
				}
				//else
				mQuantity -= p->mQuantity;
				update_bp(mStock, maxPrice);
				dlt = p;
				p = p->next;
				dequeue(&stock[mStock].buy_h, &stock[mStock].buy_t, dlt);
				if (!mQuantity)
					return (0);	
			}
			else
				p = p->next;
		}
	}
	return (mQuantity);
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
	mStock--;
    int remain_qty = get_remain_sell(mNumber, mStock, mQuantity, mPrice);

	if (remain_qty)
	{
		struct order *new_order = new struct order;
		new_order->mNumber = mNumber;
		new_order->mStock = mStock;
		new_order->mQuantity = remain_qty;
		new_order->mPrice = mPrice;
		new_order->next = NULL;
		new_order->prev = NULL;
		
		//add
		if (stock[mStock].sell_h == 0) //첫주문
		{
			stock[mStock].sell_h = new_order;
			stock[mStock].sell_t = new_order;
		}
		else
		{
			new_order->prev = stock[mStock].sell_t;
			stock[mStock].sell_t->next = new_order;
			stock[mStock].sell_t = stock[mStock].sell_t->next;
		}
	}
	print_order();
    return (remain_qty);
}

void cancel(int mNumber)
{
	int i;
	struct order *p;

	for (i = 0; i < 5; i++)
	{
		p = stock[i].buy_h;
		while(p != NULL)
		{
			if (p->mNumber == mNumber)
			{
				dequeue(&stock[i].buy_h, &stock[i].buy_t, p);
				return;
			}
			p = p->next;
		}
		p = stock[i].sell_h;
		while(p != NULL)
		{
			if (p->mNumber == mNumber)
			{
				dequeue(&stock[i].sell_h, &stock[i].sell_t, p);
				return;
			}
			p = p->next;
		}
	}
	print_order();
}

int bestProfit(int mStock)
{
	mStock--;
    return (stock[mStock].best_profit);
}