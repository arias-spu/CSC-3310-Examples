#include <iostream>
using std::cout;
using std::endl;

short* CreateArray(size_t);
void PrintLastElement(short*, size_t);
void FreeMemory(short**);
size_t mySize = 5;

int main(int argc, char* argv[]){
	short* array = CreateArray(mySize);
	for (short i=0; i<mySize; i++)
		array[i] = 2 * i;
	for (size_t i=0; i < 10; i++)
		PrintLastElement(array, mySize);
	FreeMemory(&array);	
	return 0;
}

short* CreateArray(size_t size){
	short* data = new short[size];
	return data;
}

void PrintLastElement(short* data, size_t size){
	static int element = 0;
	cout << data[element] << endl;
	element = (element + 1) % size;
}
void FreeMemory(short** memory){
	delete[] *memory;
	*memory = nullptr;
}
