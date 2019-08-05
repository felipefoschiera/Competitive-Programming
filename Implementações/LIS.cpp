// Implementação retirada do macacário do ITA
int lis(int arr[], int n) {
	multiset<int> s;
	multiset<int>::iterator it;
	for(int i = 0; i < n; i++) {
		s.insert(arr[i]);
		it = s.upper_bound(arr[i]); //non-decreasing
		//it = ++s.lower_bound(arr[i]); //strictly increasing
		if (it != s.end()) s.erase(it);
	}
	return s.size();
}