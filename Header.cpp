#include "Header.h";
void Записать(int Matrix[100][100], int n, string path) {
	ofstream out;
	out.open(path);
	out << n << "\n";
	for (int q = 0; q < n; q++) {
		for (int w = 0; w < n; w++)
			out << Matrix[q][w] << "\t";
		out << endl;
	}
	out.close();
}
void Читать(int Matrix[100][100], int& n, string path) {
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
}