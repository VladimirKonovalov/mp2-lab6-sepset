#pragma once
 #include <iostream>

using namespace std;

class sepset {
	private:
		int *parent;
		int *status;
		int *rank;
		int size;
		void check_parents(int** table, int n);
		int  check_status();
		void link(int x, int y);
		public:
			sepset(int s);
			~sepset();
			void separate_set(int** table, int n);
			
};
