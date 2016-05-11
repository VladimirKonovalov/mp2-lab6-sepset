#include "sepset.h"

sepset::sepset(int s) {
	size = s;
	parent = new int[size];
	rank = new int[size];
	status = new int[size];
	for (int i = 0; i < size; i++) {
		parent[i] = i;
		rank[i] = 0;
		
	}
	
}

sepset::~sepset() {
	delete[] parent;
	delete[] rank;
	delete[] status;
	
}

void sepset::check_parents(int** table, int n) {
	for (int i = 0; i < n; i++) {
		int x = table[i][0];
		int y = table[i][1];
		link(x, y);
		
	}
	
}

int sepset::check_status() {
	int count = 0;
	for (int i = 0; i < size; i++) {
		status[i] = parent[i];
		if (status[i] == i) {
			count++;
			
		}
		
	}
	return count;
	
}

void sepset::link(int x, int y) {
	int s1 = parent[x];
	int s2 = parent[y];
	int r1 = rank[s1];
	int r2 = rank[s2];
	if (r1<r2) {
		parent[s1] = s2;
		
	}
	else {
		parent[s2] = s1;
		if (r1 == r2)
			 rank[s1] = rank[s2] + 1;
		
	}
	
}

void sepset::separate_set(int** table, int n) {
	check_parents(table, n);
	int count_parents = check_status();
	for (int j = 0; j < count_parents; j++) {
		cout << "set [" << j << "] = {";
		int cur_status = 1;
		int i = 0;
		for (int k = 0; k < size; k++) {
			if (status[k] != 1) {
				cur_status = status[k];
				i = k;
				break;
				
			}
			
		}
		for (; i < size; i++) {
			if (status[i] == cur_status) {
				status[i] = 1;
				cout << " " << i;
				
			}
			
		}
		cout << " } " << endl;
		
	}
	
}