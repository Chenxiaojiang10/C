#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//在这里完成代码
	int* p = &arr[0];
	for (int i = 0; i < 10; i++) {
		printf("%d ", *p);
		*p += 1;
	}

	return 0;
}