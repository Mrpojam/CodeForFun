/*
##################################################################################
# Author : Pouya Jafari (MrPoj) - Mathematics and applications - 03-01-2021      #
# Basics of C++ Programming Project Matrix Calculator                            #
# https://github.com/Mrpojam/CodeForFun                                          #
##################################################################################
*/
#include<iostream>

using namespace std;

#define F first
#define S second

const int MAX_SIZE = 100;

struct Matrix {
	int size_n = 0, size_m = 0;
	float mat[MAX_SIZE][MAX_SIZE];
	float inv_mat[MAX_SIZE][MAX_SIZE];
	void _init_ (int SIZE_n, int SIZE_m) {
		size_n = SIZE_n;
		size_m = SIZE_m;
	}
	void cofactor (float dmat[MAX_SIZE][MAX_SIZE], float tmp[MAX_SIZE][MAX_SIZE], int p, int q, int n);
	float determinant (float dmat[MAX_SIZE][MAX_SIZE], int n);
	void adjoint (float dmat[MAX_SIZE][MAX_SIZE], float adj[MAX_SIZE][MAX_SIZE], int n);
	bool inverse ();
	void multiply_by_num (float number);
	void show ();
};

inline void pre_execute();
char menu ();
Matrix read_matrix(int, int);
pair<bool, Matrix> Sumination (Matrix, Matrix);
pair<bool, Matrix> Multiply (Matrix, Matrix);
pair<bool, Matrix> Division (Matrix, Matrix);

Matrix A, B;

int main () {
	system("clear");
	pre_execute();
	char command = 0;
	while (command != -1) {
		command = menu();
		if (command == '1')
			B = A;
		else if (command == '2')
			A = B;
		else if (command == '3') {
			pair<bool, Matrix> ret = Multiply(A, B);
			if (ret.F) {
				A = ret.S;
				A.show();
			}
			else
				cout << "Impossible!" << endl;
		}
		else if (command == '4') {
				pair<bool, Matrix> ret = Sumination(A, B);
				if (ret.F) {
					A = ret.S;
					A.show();
				}
				else
					cout << "Impossible" << endl;
				}
		else if (command == '5') {
				pair<bool, Matrix> ret = Division(A, B);
				if (ret.F) {
					A = ret.S;
					A.show();
				}
				else
					cout << "Impossible" << endl;
			}
			else if (command == '6') {
				B.multiply_by_num(-1);
				pair<bool, Matrix> ret = Sumination(A, B);
				B.multiply_by_num(-1);
				if (ret.F) {
					A = ret.S;
					A.show();
				}
				else
					cout << "Impossible" << endl;
			}
			else if (command == '7') {
				system("cls");
				cout << "Enter value : ";
				int value;
				cin >> value;
				A.multiply_by_num(value);
				A.show();
			}
			else if (command == '8') {
				A.show();
				if (A.size_n == A.size_m)
					cout << A.determinant (A.mat, A.size_n) << endl;
				else
					cout << "Impossible" << endl;

			}
			else if (command == '9') {
				B.show();
				if (B.size_n == B.size_m)
					cout << B.determinant (B.mat, B.size_n) << endl;
				else
					cout << "Impossible" << endl;
			}
			else if (command == 'S') {
				cout << "A : \n";
				A.show();
				cout << "B : \n";
				B.show();
			}
			else if (command == 'R'){
				system("clear");
				cout << ">Enter Matrix A size ( 1 <= n, m <= 100):" << endl;
				int n, m;
				cin >> n >> m;
				A = read_matrix(n, m);
			}
			else if (command == 'T'){
				system("clear");
				cout << ">Enter Matrix A size ( 1 <= n, m <= 100):" << endl;
				int n, m;
				cin >> n >> m;
				B = read_matrix(n, m);
			}
		cout << endl;
		cout << "Enter C to continiue : ";
		char c;
		while (cin >> c)
			if (c == 'C' || c == 'c')
				break;
	}
	return 0;
}

inline void pre_execute() {
	cout << "$$ MATRIX CALCULATOR $$" << endl;
	cout << ">Enter Matrix A size ( 1 <= n, m <= 100):" << endl;
	int n, m;
	cin >> n >> m;
	A = read_matrix(n, m);
	cout << ">Enter Matrix B size ( 1 <= n, m <= 100):" << endl;
	cin >> n >> m;
	 B = read_matrix(n, m);
}
char menu() {
	system ("clear");
	cout << "$$ MATRIX CALCULATOR $$" << endl;
	cout << "1-Move A to B\n";
	cout << "2-Move B to A\n";
	cout << "3-Calculate A = A * B\n";
	cout << "4-Calculate A = A + B\n";
	cout << "5-Calculate A = A / B\n";
	cout << "6-Calculate A = A - B\n";
	cout << "7-Calculate A = a * A\n";
	cout << "8-Determinate of A\n";
	cout << "9-Determiante of B\n";
	cout << "S-Show Matrix A & B\n";
	cout << "R-Read A\n";
	cout << "T-Read B\n";
	cout <<" -1-Exit Programm\n";

	cout << "Enter Command's number : ";
	char command;
	cin >> command;
	return command;
}
Matrix read_matrix(int n, int m) {
	Matrix ret;
	ret._init_(n, m);
	system("clear");
       cout << "Enter Matrix with size " << n << "*" << m << " : " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
	       	int value;
	              cin >> value;
	              ret.mat[i][j] = value;
	       }
	system("clear");
	return ret;
}
pair<bool, Matrix> Sumination (Matrix A, Matrix B) {
	Matrix res;
	int n = A.size_n, m = A.size_m;
	if (n != B.size_n || m != B.size_m)
		return {false, res};
	res._init_(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.mat[i][j] = A.mat[i][j] + B.mat[i][j];
	return {true, res};
}
pair<bool, Matrix> Multiply (Matrix A, Matrix B) {
	Matrix res;
	int size_n_a = A.size_n, size_m_a = A.size_m;
	int size_n_b = B.size_n, size_m_b = A.size_m;
	if (size_m_a != size_n_b)
		return {false, res};
	res._init_(size_n_a, size_m_b);
	for (int i = 0; i < size_n_a; i++)
		for (int j = 0; j < size_m_b; j++)
			for (int k = 0; k < size_m_a; k++)
				res.mat[i][j] += A.mat[i][k] * B.mat[k][j];
	return {true, res};
}
pair<bool, Matrix> Division (Matrix A, Matrix B) {
	Matrix tmp{};
	tmp._init_(A.size_n, A.size_m);
	if (A.size_m != B.size_n || !B.inverse())
		return {false, tmp};
	for (int i = 0; i < B.size_n; i++) {
		for (int j = 0; j < B.size_m; j++)
			tmp.mat[i][j] = B.inv_mat[i][j];
	}
	return {true, Multiply(A, tmp).S};
}
void Matrix::cofactor (float dmat[MAX_SIZE][MAX_SIZE], float tmp[MAX_SIZE][MAX_SIZE], int p, int q, int n) {
	int i = 0, j = 0;
	for (int row = 0; row < n; row++)
		for (int col = 0; col < n; col++)
			if (row != p && col != q) {
				tmp[i][j++] = dmat[row][col];
				if (j == n-1)
					j = 0, i++;
			}
}

float Matrix::determinant (float dmat[MAX_SIZE][MAX_SIZE], int n) {
	float ret = 0, sign = 1;
	float tmp[MAX_SIZE][MAX_SIZE];
	if (n == 1)
		return dmat[0][0];
	for (int index = 0; index < n; index++) {
		cofactor(dmat, tmp, 0, index, n);
		ret += sign * dmat[0][index] * determinant(tmp, n-1);
		sign = -sign;
	}
	return ret;
}
void Matrix::adjoint (float dmat[MAX_SIZE][MAX_SIZE], float adj[MAX_SIZE][MAX_SIZE], int n) {
	int sign = 1;
	float tmp[MAX_SIZE][MAX_SIZE];
	if (n == 1) {
		adj[0][0] = 1;
		return;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
		cofactor (dmat, tmp, i, j, n);
		sign = ((i+j)%2==0) ? 1:-1;
		adj[j][i] = sign * determinant(tmp, n-1);
		}
	}
bool Matrix::inverse () {
	float det = determinant (mat, size_n);
	float adj[MAX_SIZE][MAX_SIZE];
	if (size_n != size_m || det == 0)
		return false;
	adjoint (mat, adj, size_n);
	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_n; j++)
			inv_mat[i][j] = adj[i][j]/float(det);
	return true;
}
void Matrix::multiply_by_num (float number) {
	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_m; j++)
			mat[i][j] *= number;
}
void Matrix::show () {
	for (int i = 0; i < size_n; i++) {
		for (int j = 0; j < size_m; j++)
			cout << mat[i][j] << ' ';
		cout << endl;
	}
}
