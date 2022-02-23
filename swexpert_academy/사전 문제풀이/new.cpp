#include <iostream>

struct order
{
    int mNumber;
    int mStock;
    int mQuantity;
    int mPrice;
	int type;
	struct order *left;
	struct order *right;
};

struct stock
{
    struct order *buy_tree;
    struct order *sell_tree;
	int best_profit;
	int lowest_price;
	int recent_price;
};

struct stock stock[5];
struct order *map[200000];

void free_tree(struct order *node)
{
	 if(node == NULL)
        return;

    free_tree(node->right);
    free_tree(node->left);

    delete(node);
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

/*void printPreorder(struct order **root) {
  // 노드가 없다면 종료한다.
  if (*root == NULL)
    return;

  // root data를 출력(방문)한다.
  	printf("mNumber: %d | ", (*root)->mNumber);
	printf("mPrice: %d | ", (*root)->mPrice);
	printf("mQuantity: %d\n", (*root)->mQuantity);
  
  // 왼쪽 서브트리로 재귀한다.
  printPreorder(&((*root)->left));
  
  // 오른쪽 서브트리로 재귀한다.
  printPreorder(&((*root)->right));
}

void	print_order(void)
{
	int		i;
	order *cur;

	i = 0;
	while (i < 5)
	{
		if (stock[i].buy_tree == NULL && stock[i].sell_tree== NULL)
		{
			++i;
			continue ;
		}
		printf("\n========== stock[%d] ==========\n", i+1);
		printf("===== buy =====\n");
		printPreorder(&stock[i].buy_tree);
		
		printf("===== sell =====\n");
		printPreorder(&stock[i].sell_tree);
		++i;
	}
}

void print_map()
{
	for(int i = 30; i < 40; i++)
	{
		if (map[i])
			printf("map[%d] : %d\n", i, map[i]->mNumber);
		else
			printf("map[%d] : 0\n", i );
	}
	return;
}
*/
void init()
{
	int i;

	for (i = 0; i < 5; i++)
	{
		free_tree(stock[i].buy_tree);
		free_tree(stock[i].sell_tree);
	}
	memset(stock, 0, sizeof(struct stock) * 5);	
	memset(map, 0, sizeof(struct order*) * 200000);	

}

void insert_order(struct order** tree, struct order* newnode)
{
	if (*tree == NULL)
	{
		*tree = newnode;
		return;
	}

    if (newnode->mPrice <= (*tree)->mPrice) 
        insert_order(&((*tree)->left), newnode); 
  
    else  
		insert_order(&((*tree)->right), newnode); 
    
}

void	delete_order(struct order **tree, struct order *cur, struct order *parent)
{
	if (cur->left && cur->right) // 자식 두명 있는 노드 삭제
	{
		struct order *mor;  //min of right
		struct order *mor_parent;

		mor_parent = cur->right;
		mor = cur->right;
		while (mor->left)
		{
			mor_parent = mor;
			mor = mor->left;
		}
		cur->mNumber = mor->mNumber;
		cur->mPrice = mor->mPrice;
		cur->mQuantity = mor->mQuantity;
		cur->mStock = mor->mStock;

		if (mor == cur->right) // mor이 바로 오른쪽 노드일때
			cur->right = mor->right;
		else
		{
			if (mor->right)
				mor_parent->left = mor->right;
			else
				mor_parent->left = NULL;
		}
		
		map[cur->mNumber] = NULL;
		map[mor->mNumber] = cur;
		free(mor);
		mor = NULL;
	}
	else if (cur->left || cur->right) // 자식 1개인 노드 삭제
	{
		if (cur == parent) // root
		{
			if (cur->left)
				*tree = cur->left;
			else
				*tree = cur->right;
		}
		else if (parent->left == cur)
		{
			if (cur->left)
				parent->left = cur->left;
			else
				parent->left = cur->right;
		}
		else
		{
			if (cur->left)
				parent->right = cur->left;
			else
				parent->right = cur->right;
		}
		
		map[cur->mNumber] = NULL;
	//	free(cur);
		cur = NULL;
	}
	else // has no child
	{
		if (parent->left == cur)
			parent->left = NULL;
		else
			parent->right = NULL;
		if (cur == *tree)  //root
			*tree = NULL;
		
		map[cur->mNumber] = NULL;
	//	free(cur);
		cur = NULL;
	}
}

int get_remain_buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
	struct order	*cur; 
	struct order	*trail; 
	struct order	*min_cur;
	struct order	*min_trail;

	while (stock[mStock].sell_tree != NULL && mQuantity > 0)
	{
		min_trail = min_cur = trail = cur = stock[mStock].sell_tree;
		while (cur != NULL)
		{
			if (cur->mPrice < min_cur->mPrice) // 처음 찾은 최소값 위치 저장
			{
				min_trail = trail;
				min_cur = cur;
			}
			trail = cur;
			cur = cur->left;
		}
		if (min_cur->mPrice > mPrice)
			return (mQuantity);
		
		if (min_cur->mQuantity > mQuantity)
		{
			min_cur->mQuantity -= mQuantity;
			update_bp(mStock, min_cur->mPrice);
			return (0);
		}
		else
		{
			mQuantity -= min_cur->mQuantity;
			update_bp(mStock, min_cur->mPrice);
			delete_order(&stock[mStock].sell_tree, min_cur, min_trail);
		}
	}
	return (mQuantity);
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
	mStock--;
	mNumber--;
	int remain_qty = get_remain_buy(mNumber, mStock, mQuantity, mPrice);
	
	if (remain_qty)
	{
		struct order *new_order = new struct order;
		new_order->mNumber = mNumber;
		new_order->mStock = mStock;
		new_order->mQuantity = remain_qty;
		new_order->mPrice = mPrice;
		new_order->type = 0; //buy
		new_order->left = NULL;
		new_order->right = NULL;

		insert_order(&stock[mStock].buy_tree, new_order);
		map[mNumber] = new_order;
	}
	//print_order();
	return (remain_qty);
}

int get_remain_sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
	struct order	*cur; 
	struct order	*trail; 
	struct order	*max_cur;
	struct order	*max_trail;

	while (stock[mStock].buy_tree != NULL && mQuantity > 0)
	{
		max_trail = max_cur = trail = cur = stock[mStock].buy_tree;
		while (cur != NULL)
		{
			if (cur->mPrice > max_cur->mPrice)
			{
				max_trail = trail;
				max_cur = cur;
			}
			trail = cur;
			cur = cur->right;
		}
		if (max_cur->mPrice < mPrice)
			return (mQuantity);

		if (max_cur->mQuantity > mQuantity)
		{
			max_cur->mQuantity -= mQuantity;
			update_bp(mStock, max_cur->mPrice);
			return (0);
		}
		else
		{
			mQuantity -= max_cur->mQuantity;
			update_bp(mStock, max_cur->mPrice);
			delete_order(&stock[mStock].buy_tree, max_cur, max_trail);
		}
	}
	return (mQuantity);
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
	mStock--;
	mNumber--;
	int remain_qty = get_remain_sell(mNumber, mStock, mQuantity, mPrice);
	
	if (remain_qty)
	{
		struct order *new_order = new struct order;
		new_order->mNumber = mNumber;
		new_order->mStock = mStock;
		new_order->mQuantity = remain_qty;
		new_order->mPrice = mPrice;
		new_order->type = 1; //sell
		new_order->left = NULL;
		new_order->right = NULL;

		insert_order(&stock[mStock].sell_tree, new_order);
		map[mNumber] = new_order;
	}
//	print_order();
	//print_map();
	return (remain_qty);
}

void delete_order_checkNum(struct order **tree, int price, int num)
{
	struct order *cur = *tree;
	struct order *parent = *tree;

	while (cur)
	{
		if (price == cur->mPrice && num == cur->mNumber)
		{
			delete_order(tree, cur, parent);
			return;
		}
		else if (price <= cur->mPrice)
		{
			parent = cur;
			cur = cur->left;
		}
		else
		{
			parent = cur;
			cur = cur->right;
		}
	}
}

void cancel(int mNumber)
{
	mNumber--;
	if (map[mNumber] == NULL)
		return;

	if (map[mNumber]->type == 0) // buy
		delete_order_checkNum(&(stock[map[mNumber]->mStock].buy_tree), map[mNumber]->mPrice, mNumber);
	else 
		delete_order_checkNum(&(stock[map[mNumber]->mStock].sell_tree), map[mNumber]->mPrice, mNumber);

	//print_order();
//	print_map();
	return;
}

int bestProfit(int mStock)
{
	mStock--;
	return (stock[mStock].best_profit);
}


