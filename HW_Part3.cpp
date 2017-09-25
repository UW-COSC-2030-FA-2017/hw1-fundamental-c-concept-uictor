#include <iostream>

#include "HW_Part3.h"


using namespace std;

template <class Temp>
Collection<Temp>::Collection(int size){
	setSize(size);
}

template <class Temp>
bool Collection<Temp> ::isEmpty(){
	if (CollSize == 0){
		return true;
	}
	else {
		return false;
	}
}

template<class Temp>
void Collection<Temp>::makeEmpty(){
	if (isEmpty()){
		cout << "The collection is already empty." << endl;
	}
	else{
		for (int i = 0; i < CollSize; i++){
			arrayObj[i] = NULL;
		}
		CollSize = 0;
	}

}

template<class Temp>
void Collection<Temp>::insert(Temp const & x){
	arrayObj[CollSize] = x;
	CollSize++;
}
template<class Temp>
void Collection<Temp>::remove(Temp x){
	int i = 0;
	int counter = 0;
	while (i < CollSize){
		if (arrayObj[i] == x || &arrayObj[i] == &x){
			counter++;
		}
		i++;
	}
	if (counter == 0){
		cout << "This element provided does not exist in the collection" << endl;
	}
	else if (counter == 1){
		int i = 0;
		int location = {};
		while (i < CollSize){
			if (arrayObj[i] == x || &arrayObj[i] == &x){
				location = i;
			}
			i++;
		}
		while (location < CollSize){
			arrayObj[location] = arrayObj[location + 1];
			location++;
		}
		arrayObj[CollSize - 1] = NULL;
		CollSize--;
	}
	else{
		int i = 0;
		int y = 0;
		int position[counter] = {};
		while (i < CollSize){
			if (arrayObj[i] == x || &arrayObj[i] == &x){
				position[y] = i;
				y++;
			}
			i++;
		}
		for (int z = 0; z < counter; z++){
			int post = position[z];
			while (post < CollSize){
				arrayObj[post] = arrayObj[post + 1];
				post++;
			}
			arrayObj[CollSize - 1] = NULL;
			CollSize--;
			for (int a = 0; a< counter; a++){
				position[a]--;
			}
		}
	}
}



template<class Temp>
void Collection<Temp>::removeRandom(){
	if (isEmpty()){
		cout << "The list already empty" << endl;
	}
	else{
		int position = rand() % CollSize;
		cout << "Element from position " << position << " has been removed." << endl;
		while (position < CollSize){
			arrayObj[position] = arrayObj[position + 1];
			position++;
		}
		CollSize--;
	}

}

template<class Temp>
bool Collection<Temp>::notContained(Temp x){
	bool notContained = true;
	int i = 0;
	while (i < CollSize){
		if (arrayObj[i] == x || &arrayObj[i] == &x){
			notContained = false;
		}
		i++;
	}
	return notContained;
}

template<class Temp>
void Collection<Temp>::setSize(int x){
	arrayObj = new Temp[x];
	cout << "The size of the collection has been set to " << x << endl;
}

template<class Temp>
void Collection<Temp>::printArray(){
	cout << "[";
	for (int i = 0; i < CollSize; i++){
		cout << arrayObj[i] << " ";
	}
	cout << "]" << endl;
}

int main(){

	int max_size;
	cout << "please enter the maximum size of the array:  ";
	cin >> max_size;
	Collection<int> intCollection(max_size);


	intCollection.insert(2);
	intCollection.insert(4);
	intCollection.insert(7);

	intCollection.printArray();

	intCollection.remove(2);
	intCollection.printArray();

	intCollection.insert(12);
	intCollection.insert(20);
	intCollection.insert(5);
	intCollection.printArray();
	intCollection.remove(5);
	intCollection.printArray();
	intCollection.removeRandom();
	intCollection.printArray();

	intCollection.insert(0);
	intCollection.insert(13);
	intCollection.insert(12);
	intCollection.insert(0);
	intCollection.insert(13);
	intCollection.insert(4);
	intCollection.insert(1);
	intCollection.printArray();
	intCollection.remove(12);
	intCollection.printArray();
	intCollection.removeRandom();
	intCollection.printArray();
	intCollection.remove(0);
	intCollection.printArray();



}
