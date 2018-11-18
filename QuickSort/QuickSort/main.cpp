#include<iostream>
void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}


int partition(int* arr, int front, int rear) {
	int left, right;
	left = front + 1;
	right = rear;

	while(left <= right) {
		while (arr[front] >= arr[left] && left <= rear) {
			left++;
		}
		while (arr[front] <= arr[right] && right >= front+1) {
			right--;
		}
		if (left <= right) {
			swap(arr, left, right);
		}
	}
	swap(arr, front, right);
	return right;
	
}

void quickSort(int* arr, int front, int rear) {
	if (front <= rear) {
		int middle = partition(arr, front, rear);
		quickSort(arr, front, middle - 1);
		quickSort(arr, middle + 1, rear);
	}
}



int main() {

	int arr[] = { 5, 4, 3, 2, 1, 6, 7, 8, 9 , 10, 156};

	for (int i : arr) {
		std::cout << i << ", ";
	}

	std::cout << std::endl;

	quickSort(arr, 0, (sizeof(arr) / sizeof(int))-1);

	for (int i : arr) {
		std::cout << i << ", ";
	}

	return 0;
}