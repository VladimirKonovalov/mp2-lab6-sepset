#include "sepset.h"

void main() {
	int rel = 0;
	int size = 0;
	
		cout << "Enter number of elements: "; cin >> size;
	
		cout << "Enter the number of relations: "; cin >> rel;
	
		int** relations;
	
		relations = new int *[rel];
	for (int i = 0; i < rel; i++) {
		relations[i] = new int[2];
		
	}
	
		cout << "Enter the relations: " << endl;
	for (int i = 0; i < rel; i++) {
		cout << "Relation " << i << " 1: "; cin >> relations[i][0];
		cout << "Relation " << i << " 2: "; cin >> relations[i][1];
		cout << endl;
		
	}
	
		sepset ds(size);
	ds.separate_set(relations, rel);
	
}