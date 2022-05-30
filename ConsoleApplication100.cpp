
#include <iostream> 
#include <fstream> 
#include <string> 
#include "Header.h"
using namespace std;
bool Содержит_Нужную_Цифру(int value) {
	if (value < 0)
		value = -value;
	do {
		if (value % 10 == 3 || value % 10 == 5)
			return true;
		value = value / 10;
	} while (value > 0);
	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int Matrix[100][100];
	//int** Matrix=new int* [100]; 
	int n, q, w, e;

	//
	string path = "Text.txt";
	Читать(Matrix, n, path);
	/*
		ifstream in(path);
		int i, m = 0, k = -1;
		in >> n;
		while (in >> i) {
			if (m % n == 0)
				k++;
			Matrix[k][m % n] = i;
			m++;
		}
		in.close();
	*/
	if (n > 100) {
		cout << "n>100";
		return 0;
	}
	for (q = 0; q < n; q++) {
		for (w = 0; w < n; w++) {
			cout << Matrix[q][w] << "\t";
		}
		cout << endl;
	}
	bool isComplite = false;
	for (e = 0; e < n; e++) {
		if ((Matrix[e][e] < 0) || (Matrix[e][n - e - 1] < 0))
		{
			cout << "Элемент диагонали матрицы меньше нуля" << endl;
			isComplite = false;
			break;
		}
		if ((Содержит_Нужную_Цифру(Matrix[e][e])) || (Содержит_Нужную_Цифру(Matrix[e][n - e - 1]))) {
			isComplite = true;
		}
	}
	if (isComplite) {
		for (int i = 0; i < n; i++) {
			int minj = 0;
			int min = Matrix[0][i];
			for (int j = 1; j < n; j++) {
				if (min > Matrix[j][i]) {
					minj = j;
					min = Matrix[j][i];
				}
			}
			Matrix[minj][i] = -1000;
		}
	}
	cout << endl;
	for (q = 0; q < n; q++) {
		for (w = 0; w < n; w++)
			cout << Matrix[q][w] << "\t";
		cout << endl;
	}
	path = "text2.txt";
	Записать(Matrix, n, path);
	/*
	ofstream out;
	out.open(path);
	for (int q = 0; q < n; q++) {
		for (int w = 0; w < n; w++)
			out << Matrix[q][w] << "\t";
		out << endl;
	}
	out.close();
	*/
	return 0;
}
