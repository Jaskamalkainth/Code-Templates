const int maxn = 4e5+7;
int arr[maxn];
struct node
{
	int lazy;
	node()
	{
		lazy = 0;

	}
	node(int val)
	{
		lazy = 0;
	}
	void merge(node &l , node &r)
	{

	}
	void split(node &lc , node &rc, int left ,int right)
	{
		if(lazy)
		{

			if(left != right)
			{

			}
			lazy = 0;
		}
	}
}tree[4*maxn];

inline void build(int id ,int left , int right)
{
	if(left == right)
	{
		
		return ;
	}
	int mid = mid(left,right);
	build(id<<1,left,mid);
	build((id<<1)|1,mid+1,right);
	tree[id].merge(tree[id<<1],tree[(id<<1)|1]);
}
inline void update(int id ,int left ,int right ,int lq ,int rq ,int val)
{
	tree[id].split(tree[id<<1],tree[(id<<1)|1],left,right);
	if(left > rq || right < lq)
		return ;
	if(left >= lq && right <= rq)
	{
		tree[id] = node(val);
		if(left != right)
		{
			tree[id<<1].lazy = val;
			tree[(id<<1)|1].lazy = val;  
		}
		return ;
	}
	int mid = mid(left,right);
	update(id<<1,left,mid,lq,rq,val);
	update((id<<1)|1,mid+1,right,lq,rq,val);
	tree[id].merge(tree[id<<1],tree[(id<<1)|1]);
}
inline node query(int id ,int left ,int right ,int lq ,int rq)
{
	tree[id].split(tree[id<<1],tree[(id<<1)|1],left,right);
	if(left > rq || right < lq)
		return node();
	if(left >= lq && right <= rq)
	{
		return tree[id];
	}
	int mid = mid(left,right);
	node nl = query(id<<1,left,mid,lq,rq);
	node nr = query((id<<1)|1,mid+1,right,lq,rq);
	node t;
	t.merge(nl,nr);
	return t;
}
