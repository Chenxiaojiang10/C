#include<stdio.h>
#include<assert.h>
void* my_Memcpy(void* dest, const void* src, size_t size) {
	assert(dest != NULL && src != NULL);
	void* ret = dest;
	for (unsigned int i = 0; i < size; i++) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

void* my_Memmove(void* dest, const void* src, size_t size) {
	assert(dest != NULL && src != NULL);
	char* newdest = (char*)dest;
	char* newsrc = (char*)src;
	if (newsrc < newdest && newsrc < newdest + size) {
		char* lastdest = newdest + size - 1;
		char* lastsrc = newsrc + size - 1;
		for (unsigned int i = 0; i < size; i++) {
			*lastdest = *lastsrc;
			lastdest--;
			lastsrc--;
		}
	}
	else {
		my_Memcpy(dest, src, 16);
	}
}

int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[4] = { 0 };
	my_Memcpy(arr2, arr1, 16);
	for (int i = 0; i < 4; i++) {
		printf("%d ", arr2[i]);
	}

	return 0;
}