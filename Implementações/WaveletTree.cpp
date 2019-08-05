#include <vector>
#include <algorithm>
using namespace std;

int Lcmp;
bool less(int i) { return i <= Lcmp; }

class WaveletTree {
private:
	vector<vector<int> > ml;
	vector<int> arr; 
	int sig, size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
	
	void build(int u, int l, int r, int lo, int hi, int* A) {
		if (lo == hi) return;
		int mid = (lo + hi) / 2;
		Lcmp = mid;
		ml[u].reserve(r-l+2);
		ml[u].push_back(0);
		for (int i=l; i<=r; i++) {
			ml[u].push_back(ml[u].back() + (A[i]<=Lcmp));
		}
		int p = (int)(stable_partition(A+l, A+r+1, less) - A);
		build(left(u), l, p-1, lo, mid, A);
		build(right(u), p, r, mid+1, hi, A);
	}
	
	int rank(int u, int lo, int hi, int q, int i) {
		if (lo == hi) return i;
		int mid = (lo + hi) / 2, ri = ml[u][i];
		if (q <= mid) return rank(left(u), lo, mid, q, ri);
		else return rank(right(u), mid+1, hi, q, i - ri);
	}
	
	int quantile(int u, int lo, int hi, int i, int j, int k) {
		if (lo == hi) return lo;
		int mid = (lo + hi) / 2;
		int ri = ml[u][i-1], rj = ml[u][j], c = rj - ri;
		if (k <= c) return quantile(left(u), lo, mid, ri+1, rj, k);
		else return quantile(right(u), mid+1, hi, i-ri, j-rj, k-c);
	}
	
	int range(int u, int lo, int hi, int i, int j, int a, int b) {
		if (lo > b || hi < a) return 0;
		if (b >= hi && lo >= a) return j-i;
		int mid = (lo + hi) / 2;
		int ri = ml[u][i], rj = ml[u][j];
		int c1 = range(left(u), lo, mid, ri, rj, a, b);
		int c2 = range(right(u), mid+1, hi, i-ri, j-rj, a, b);
		return c1 + c2;
	}
	
	void swap(int u, int lo, int hi, int v1, int v2, int i) {
		if (lo == hi) return;
		int mid = (lo + hi) / 2;
		if (v1 <= mid) {
			if (v2 > mid) ml[u][i]--;
			else swap(left(u), lo, mid, v1, v2, ml[u][i]);
		}
		else {
			if (v2 <= mid) ml[u][i]++;
			else swap(right(u), mid+1, hi, v1, v2, i-ml[u][i]);			
		}
	}
	
public:
	WaveletTree() {}
	WaveletTree(int* begin, int* end, int _sig) {
		sig = _sig;
		size = (int)(end-begin);
		ml.resize(4*size);
		arr = vector<int>(begin, end);
		build(1, 0, size-1, 0, sig, &arr[0]);
		arr = vector<int>(begin, end);
	}
	
	int rank(int i, int q) { return rank(1, 0, sig, q, i+1); }
    // Acha quantas vezes um elemento q aparece em [i, j]
	int rank(int i, int j, int q) { return rank(j, q) - rank(i-1, q); }
    // Acha o k-ésimo elemento em [i, j]
	int quantile(int i, int j, int k) { return quantile(1, 0, sig, i+1, j+1, k); }
    // Acha quantos elementos em [i, j] estão contidos em [a, b]
	int range(int i, int j, int a, int b) { return range(1, 0, sig, i, j+1, a, b); }
    // Troca os elementos na posição i e i+1
	void swap(int i) {
		if (i >= size-1) return;
		swap(1, 0, sig, arr[i], arr[i+1], i+1);
		std::swap(arr[i], arr[i+1]);
	}
};