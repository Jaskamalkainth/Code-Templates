const int MAXN = 105000;

struct node {
    int next[26];
    int len;
    int sufflink;
    int num, l, r;
};

int len; // length of the string
char s[MAXN]; // orignal string
node tree[MAXN]; 
int num;            // node 1 - root with len -1, node 2 - root with len 0
int suff;           // max suffix palindrome
vector<int> adj[ MAXN ];
vector<pair<pair<int,int> , int > > A;
bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while (true) {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])     
            break;  
        cur = tree[cur].sufflink;
    }       
    if (tree[cur].next[let]) {  
        suff = tree[cur].next[let];
        tree[suff].num ++;
        return false;
    }

    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[num].r = pos;
    tree[num].l = pos - tree[num].len + 1; 
    tree[cur].next[let] = num;
    if (tree[num].len == 1) {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }

    tree[num].num ++;
    while (true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }       
    }
    return true;
}

void initTree() {
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
    tree[1].num = tree[2].num = 0; 
}

void dfs( int u ) {
    for( auto it: adj[u] ) {
        dfs(it);
        tree[u].num += tree[it].num;
     }
}
 /*
  * cin >> s;
	int len = strlen(s);

    initTree();
    for (int i = 0; i < len; i++) 
        addLetter(i);
    for(int i=2; i<=num; i++) 
        adj[tree[i].sufflink].push_back(i);
    dfs(1);
    for(int i=3; i<=num; i++)
        A.push_back(make_pair(make_pair(tree[i].l, tree[i].r), tree[i].num));
	//
	for(auto &i: A)
	{
		cout << i.first.first << " " << i.first.second << " " << i.second << "\n";  
	}
	// A : count of the palindrome [i.ff.ff,i.ff.ss] = i.ss.
	// start from 3 -> num
	// for each node you have the following info:
	// 1. palindrome [l,r] and its length = len.
	// 2. count of this palindrome = num
*/
