#include<stdio.h>
#include<conio.h>
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int array[], int low, int high) {
	int pivot = array[high];
	int i = (low - 1);
	for (int j = low;j < high;j++) {
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return(i + 1);
}

void quickSort(int array[], int low, int high) {
	if (low < high) {
		int pi = partition(array, low, high);
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

void printArray(int array[], int size) {
	for (int i = 0;i < size;i++)
		printf("%d", array[i]);
	printf("\n");
}

int main() {
	int size;
	system("cls");
	printf("Enter size of data: ");
	scanf("%d", &size);
	int data[size];
	printf("Enter %d number of data:\n", size);
	for (int i = 0;i < size;i++)
		scanf("%d", &data[i]);
	printf("Unsorted Array\n");
	printArray(data, size);
	quickSort(data, 0, size - 1);
	printf("Sorted Array in ascending array: \n");
	printArray(data, size);
	// system("python -u exe.py");
	return 0;
}