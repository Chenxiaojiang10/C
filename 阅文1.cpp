//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//void Swap(int* array, int i, int j)
//{
//	int tmp = array[i];
//	array[i] = array[j];
//	array[j] = tmp;
//}
//
//
//int partion2(int* array, int begin, int end)
//{
//
//	int key = array[begin];
//	while (begin < end)
//	{
//		//先从后向前找
//		while (begin < end && array[end] >= key)
//			--end;
//		array[begin] = array[end];
//		//再从前向后找
//		while (begin < end && array[begin] <= key)
//			++begin;
//		array[end] = array[begin];
//	}
//	array[begin] = key;
//	return begin;
//}
//
//void quickSort(int* array, int begin, int end)
//{
//	if (begin >= end)
//		return;
//	int keyPos = partion2(array, begin, end);
//	quickSort(array, begin, keyPos - 1);
//	quickSort(array, keyPos + 1, end);
//}
//
//
//int main() {
//	int n;
//	while (cin >> n) {
//		string str;
//		cin.clear();
//		cin.ignore();
//		getline(cin, str);
//		int s = str.size() / 2;
//		if (str.size() % 2 != 0) {
//			s++;
//		}
//		
//		int* arr = new int[s];
//		for (int i = 0; i < str.size(); i+=2) {
//			int k = 0;
//			k = (int)(str[i] - '0');
//			arr[i / 2] = k;
//		}
//		
//		cout << s << endl;
//		quickSort(arr, 0, s - 1);
//		cout << arr[s - n] << endl;
//	}
//
//	return 0;
//}