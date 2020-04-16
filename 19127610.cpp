#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void outputMatrix(int** a, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int** inputMatrix(int n, int m) {
	srand(time(0));
	int** a = new int* [m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 99;
		}

	return a;
}
int findMin(int bot, int top, int left, int right) {
	int min = 100;
	if (left < min)
		min = left;
	else if (right < min)
		min = right;
	else if (top < min)
		min = top;
	else min = bot;
	return min;
}
int** squareMatrix(int** a, int n, int m,int p,int &temp) {
	int top = 0, bot = 0, left = 0, right = 0,b,ip,jp;
	temp = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		b = temp;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == p) {
				count++;
				right = n  - j;
				left = j ;
				top = i ;
				bot = n - i ;
				temp = findMin(bot, top, left, right);
				if (temp > b) {
					ip = i;
					jp = j;
				}
			}
		}

	}if (count != 0) {
		int** x = new int* [temp + 1];
		for (int i = 0; i < temp + 1; i++)
			x[i] = new int[temp + 1];
		for (int i = 0; i < temp + 1; i++)
			for (int j = 0; j < temp + 1; j++)
			{
				x[i][j] = a[i + ip][j + jp];
			}

		return x;
	}
	else return 0;
}
int main() {
	int m, n, p,temp;
	cout << "Nhap 3 so nguyen duong m,n,p: "; cin >> m >> n >>p;
	int** a = inputMatrix(n, m);
	outputMatrix(a, n, m);


	cout << endl;
	int**x= squareMatrix(a, n, m, p,temp);
	if (x == 0)
		cout << "Khong tim duoc p." << endl;
	else {
		cout << "Ma tran vuong moi nhat vua tim duoc: " << endl;
		outputMatrix(x, temp + 1, temp + 1);
	}
	/*for (int i = 0; i < m; i++)
		delete a[i];
	delete[]a;*/
	return 0;
}
