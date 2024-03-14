#ifndef My_Sort
#define My_Sort
#include <assert.h>
#include <vector>
#include <iostream>
template<class T, class A>
void BubblingSort(std::vector<T, A>& nums, int begin = 0, int end = -1) {
	if (end == -1) end = nums.size();
	assert(begin >= 0 && begin < end);
	if (begin == end - 1) return;
	for (int i = begin; i < end; ++i) {
		bool ischange = false;
		for (int j = i + 1; j < end; ++j) {
			if (nums[i] > nums[j]) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				ischange = true;
			}
		}
		if (!ischange) return;
	}
	return;
}
template<class T, class A>
void InsertSort(std::vector<T, A>& nums, int begin = 0, int end = -1) {
	if(end == -1) end = nums.size();
	assert(begin >= 0 && begin < end);
	if (begin == end - 1) return;
	for (int i = 1; i < end; ++i) {
		int low = 0, high = i - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[i] < nums[mid]) high = mid - 1;
			else low = mid + 1;
		}
		int temp = nums[i];
		for (int j = i;j > high + 1; --j)
		{
			nums[j] = nums[j - 1];
		}
		nums[high + 1] = temp;
	}
}
template<class T, class A>
void SelectSort(std::vector<T, A>& nums, int begin = 0, int end = -1) {
	if (end == -1) end = nums.size();
	assert(begin >= 0 && begin < end);
	if (begin == end - 1) return;
	for (int i = 0; i < end; ++i) {
		int temp = nums[i];
		int minval = nums[i];
		int cur = i;
		for (int j = i + 1; j < end; ++j) {
			if (nums[j] < minval) { minval = nums[j]; cur = j; }
		}
		nums[i] = nums[cur];
		nums[cur] = temp;
	}
}
template<class T, class A>
void QuickSort(std::vector<T, A>& nums, int begin, int end) {
	if(end <= begin) return;
	int key = nums[begin];
	int left = begin, right = end - 1;
	while (left < right) {
		//找到右边比key小的元素放到左边
		while (left < right && nums[right] > key) --right;
		if(left < right) nums[left++] = nums[right];
		//找到左边比key大的元素放到右边
		while (left < right && nums[left] <= key) ++left;
		if (left < right) nums[right--] = nums[left];
	}
	nums[left] = key;
	QuickSort(nums, begin, left - 1);
	QuickSort(nums, left + 1, end);
}
//维护堆的性质
template<class T, class A>
void Heap_maintain(std::vector<T, A>& nums, int begin, int end, int n) {
	int lagerst = n;
	int lson = 2 * n + 1;
	int rson = 2 * n + 2;
	if (lson < end && nums[lagerst] < nums[lson]) lagerst = lson;
	if (rson < end && nums[lagerst] < nums[rson]) lagerst = rson;
	if (lagerst != n) {
		std::swap(nums[lagerst], nums[n]);
		//递归维护
		Heap_maintain(nums, begin, end, lagerst);
	}
}
//堆排序入口
template<class T, class A>
void HeapSort(std::vector<T, A>& nums, int begin, int end) {
	for (int i = begin + (end - begin) / 2 - 1; i >= begin; --i) {
		//建堆
		Heap_maintain(nums, begin, end, i);
	}
	//将最大元素放到最后
	for (int i = end - 1; i >= begin + 1; --i)
	{
		std::swap(nums[0], nums[i]);
		Heap_maintain(nums, begin, i, 0);
	}
}
template<class T, class A>
void ShellSort(std::vector<T, A>& nums, int begin = 0, int end = -1) {
	if (end == -1) end = nums.size();
	assert(begin >= 0 && begin < end);
	if (begin == end - 1) return;
	//每段间隔
	int n = end - begin;
	while (n > 1) {
		n /= 2;
		for (int i = begin; i < end - n; ++i) {
			if (nums[i + n] < nums[i]) {
				int cur = nums[i + n];
				int index = i;
				//找合适位置放cur，并且移动元素
				while (index >= 0 && cur < nums[index]) {
					nums[index + n] = nums[index];
					index -= n;
				}
				nums[index + n] = cur;
			}
		}
	}
}
template<class T, class A>
void Merge(std::vector<T, A>& nums, int begin, int mid, int end) {
	std::vector<T> temp(end - begin, 0);//辅助数组
	int i = 0, j = begin, k = mid;
	//排序
	for ( ; j < mid && k < end; ) {
		if (nums[j] > nums[k]) {
			temp[i++] = nums[k++];
		}
		else {
			temp[i++] = nums[j++];
		}
	}
	//合并剩余部分
	while (j < mid) {
		temp[i++] = nums[j++];
	}
	while (k < end) {
		temp[i++] = nums[k++];
	}
	//填回原数组
	for (T i : temp) {
		nums[begin++] = i;
	}
}
template<class T, class A>
void MergeSort(std::vector<T, A>& nums, int begin = 0, int end = -10) {
	if (end == -10) end = nums.size();
	assert(begin >= 0 && begin < end);
	if (end - begin > 1) {
		int mid = begin + (end - begin) / 2;
		MergeSort(nums, begin, mid);//划分前半段
		MergeSort(nums, mid, end);//划分后半段
		Merge(nums, begin, mid, end);//合并
	}
}
#endif