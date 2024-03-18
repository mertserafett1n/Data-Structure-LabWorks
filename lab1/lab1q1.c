#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int len);
void swap(int *arr1, int *arr2);

int main(){
    int lenFirst, lenSecond, i;
    printf("Enter lenght of first array: ");
    scanf("%d", &lenFirst);
    int *firstarray = (int*)malloc(lenFirst * sizeof(int));
    int *lastarray = (int*)malloc(lenFirst * sizeof(int));
    printf("Enter numbers: ");
    int lenLast = 0;
    for(i = 0; i < lenFirst; ++i){
        scanf("%d", &firstarray[i]);
        lastarray[lenLast++] = firstarray[i];
    }
    printf("Enter lenght of second array: ");
    scanf("%d", &lenSecond);
    int *secondarray = (int*)malloc(lenSecond * sizeof(int));
    lastarray = (int*)realloc(lastarray, (lenFirst + lenSecond)* sizeof(int));
    printf("Enter numbers: ");
    for(i = 0; i < lenSecond; ++i){
        scanf("%d", &secondarray[i]);
        lastarray[lenLast++] = secondarray[i];
    }
    bubble_sort(lastarray, lenLast);
    printf("Merged array: ");
    for(i = 0; i < lenLast; ++i){
        printf("%d ", lastarray[i]);
    }
    free(firstarray);
    free(secondarray);
    free(lastarray);
    return 0;
}


void bubble_sort(int arr[], int len){
	int i,j;
	for(i = 0; i < len - 1; i++){
		for(j = 0; j < len - i- 1; j++){
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}
void swap(int *arr1, int *arr2){
	int temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}