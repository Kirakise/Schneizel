#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};

unsigned char height(node* p)
{
	return (p ? p->height : 0);
}

int bfactor(node* p)
{
	return (height(p->right) - height(p->left));
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // балансировка узла p
{
	fixheight(p);
	if( bfactor(p)==2 )
	{
		if( bfactor(p->right) < 0 )
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if( bfactor(p)==-2 )
	{
		if( bfactor(p->left) > 0  )
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if( !p ) return new node(k);
	if( k<p->key )
		p->left = insert(p->left,k);
	else
		p->right = insert(p->right,k);
	return balance(p);
}

int	getheight(node *p, int i)
{
	if (i == 0)
		i = 1;
	if (!p)
		return (1);
	else
		return (getheight(p->left, i) > getheight(p->right, i) ? 
				getheight(p->left, i) + i : getheight(p->right, i) + i);
}

void	printtree(node *p, int i)
{
	int tmp = i;
	if (p->right)
		printtree(p->right, i + 1);

	while (i--)
		cout << '\t';
	cout << p->key << '\n';
	if (p->left)
		printtree(p->left, tmp + 1);
}

int main()
{
	node *p = 0;
	int n;
	int tmp;
	
	cin >> n;
	while (n--)
	{
		cin >> tmp;
		p = insert(p, tmp);
	}
	printtree(p, 0);
	cout << getheight(p, 0) - 1<< '\n';
	return (0);

}
