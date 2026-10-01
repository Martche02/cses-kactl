#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegTree
{
    vector<T> tree;
    T neutro; // Elemento vazio para retornos fora do intervalo
    
    // Função embutida que será injetada na criação
    function<T(T, T)> merge; 

    SegTree(int n, T elemento_neutro, function<T(T, T)> funcao_merge)
	{
        tree.assign(4 * n, elemento_neutro);
        neutro = elemento_neutro;
        merge = funcao_merge;
    }

    void build(int pos, int L, int R, const vector<T>& base_array)
	{
        if (L == R)
		{
            tree[pos] = base_array[L];
            return;
        }
		
        int mid = (L + R) / 2;
        build(2 * pos, L, mid, base_array);
        build(2 * pos + 1, mid + 1, R, base_array);
        tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
    }

    void update(int pos, int L, int R, int idx, T val)
	{
        if (L == R) 
		{
            tree[pos] = val;
            return;
        }
		
        int mid = (L + R) / 2;
        if (idx <= mid)
			update(2 * pos, L, mid, idx, val);
        else 
			update(2 * pos + 1, mid + 1, R, idx, val);
		
        tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
    }

    T query(int pos, int L, int R, int ql, int qr)
	{
        if (ql > R || qr < L) 
			return neutro;
        if (ql <= L && qr >= R) 
			return tree[pos];
		
        int mid = (L + R) / 2;
        return merge(
            query(2 * pos, L, mid, ql, qr),
            query(2 * pos + 1, mid + 1, R, ql, qr)
        );
    }
};

long long P = 313;
long long MOD = 1e9 + 7;

// 1. O TIPO DE DADO
struct Node 
{
    long long hash_val;
    int len;
	
	Node(char x) 
		: hash_val(x-'a'+1)
		, len(1)
	{}
	
	Node() 
		: hash_val(0)
		, len(0)
	{}
};

vector<long long> p(2e5+5);

Node merge_fwd(Node L, Node R)
{
	if (L.len == 0)
		return R;
	if (R.len == 0)
		return L;
	
	Node merge{};
	
	merge.len = R.len + L.len;
	merge.hash_val = (R.hash_val + p[R.len] * L.hash_val) % MOD;
	return merge;
}

Node merge_rev(Node L, Node R)
{
	if (L.len == 0)
		return R;
	if (R.len == 0)
		return L;
	
	Node merge{};
	
	merge.len = R.len + L.len;
	merge.hash_val = (L.hash_val + p[L.len] * R.hash_val) % MOD;
	return merge;
}

int main()
{
	int n;
	cin >> n;
	p[0] = 1;
	for (int i = 1; i < n+5; i++)
		p[i] = p[i-1]*P%MOD;
	
	
	int m;
	cin >> m;
	string s;
	cin >> s;
	vector<Node> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = s[i];
	}
	
	SegTree<Node> fwd(n, Node{}, merge_fwd);
	SegTree<Node> rev(n, Node{}, merge_rev);
	
	fwd.build(1, 0, n-1, arr);
	rev.build(1, 0, n-1, arr);
	
	while (m--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int k;
			char x;
			cin >> k >> x;
			k--;
			fwd.update(1, 0, n-1, k, x);
			rev.update(1, 0, n-1, k, x);
		}
		else
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			if (fwd.query(1, 0, n-1, a, b).hash_val == rev.query(1, 0, n-1, a, b).hash_val)
				cout << "YES\n";
			else
				cout << "NO\n";			
		}
	}

	return 0;
	
}