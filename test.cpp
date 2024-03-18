#include <vector>
#include <iostream>
#include <assert.h>
#include "MySort.hpp"
#include <windows.h>
#include <random>
#include<algorithm>
#include<chrono>
#include <ratio>
#include <windows.h>
#include<thread>
#pragma comment( lib,"winmm.lib" )
int main() {
	srand(time(nullptr));
	std::vector<int> test;
	for (int i = 0; i < 100; ++i) {
		test.emplace_back(rand() % 10);
	}
	auto start = std::chrono::high_resolution_clock::now();
	//BubblingSort(test);
	//InsertSort(test);
	//SelectSort(test);
	//QuickSort(test, 0, test.size());
	//HeapSort(test, 0, test.size());
	ShellSort(test);
	//MergeSort(test);
	//sort(test.begin(), test.end());

	//Sleep(20);
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	//std::this_thread::sleep_for(std::chrono::milliseconds(10));

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::ratio<1, 1000>> usetime(end - start);
	for (auto i : test) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "运行时间" << usetime.count() << " ms" << std::endl;
	system("pause");
} 