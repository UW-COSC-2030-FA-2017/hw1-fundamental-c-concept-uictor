//Pointer Example
#include <iostream>
using namespace std;


// I apologize but this is the simplest code
//explaining pointers that I could think of.

int main(){

	int num;
	int *pointer;

	pointer = &num;
	*pointer = 1;

	

	
	// The value of num should be 1.

	cout << "Yes num is equal to " << num << endl;
}