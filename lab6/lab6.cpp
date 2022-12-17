#define _CRT_SECURE_NO_WARNINGS
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

int main(void)
{
	int m;
	printf("Enter amount of peaks: \n");
	scanf("%d", &m);

	int** a, ** b;
	a = (int**)malloc((m) * sizeof(int*));
	b = (int**)malloc((m) * sizeof(int*));
	srand(time(NULL));
	// (1)
	printf("   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("%5d", (j + 1));
	}
	printf("\n   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("-----");
	}
	for (int i = 0; i < m; i++) {
		a[i] = (int*)malloc(m * sizeof(int));// Выделение памяти под хранение строк
		b[i] = (int*)malloc(m * sizeof(int));

		printf("\n %d |", (i + 1)); // цикл по столбцам
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
			b[i][j] = 0;
			if (j <= i) {
				a[i][j] = a[j][i];
				b[i][j] = a[j][i];
				printf("%4d ", a[i][j]);
			}
			else {
				a[i][j] = rand() % 2;
				b[i][j] = rand() % 2;
				printf("%4d ", a[i][j]);
			}
		}
	}
	//M2
	printf("\n\n   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("%5d", (j + 1));
	}
	printf("\n   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("-----");
	}
	for (int i = 0; i < m; i++) {
		b[i] = (int*)malloc(m * sizeof(int));

		printf("\n %d |", (i + 1)); // цикл по столбцам
		for (int j = 0; j < m; j++) {
			b[i][j] = 0;
			if (j <= i) {
				b[i][j] = b[j][i];
				printf("%4d ", b[i][j]);
			}
			else {
				b[i][j] = rand() % 2;
				printf("%4d ", b[i][j]);
			}
		}
	}
	//-------------
	// (2)
	int operation;
	printf("\nSelect an operation:\nOtozhdestvlenie vershin- 1\nStyagivanie rebra- 2\nRasheplenie vershini - 3\n");
	scanf("%d", &operation);

	if (operation == 1) {
		int peak1, peak2, repeatCheck = 0, k = m - 1, countI = 0, countJ = 0;

		int** task;
		task = (int**)malloc((k) * sizeof(int*));
		for (int i = 0; i < (k); i++) {
			task[i] = (int*)malloc((k) * sizeof(int));
			for (int j = 0; j < (k); j++) {
				task[i][j] = 0;
			}
		}
		printf("\nSelect two peaks:\n");
		scanf("%d%d", &peak1, &peak2);
		//---------- printing matrix
		printf("\n\n   ");

		for (int j = 0; j < m; j++) {  // цикл по столбцам
			if (j != peak1 - 1 && j != peak2 - 1)
				printf("%5d", (j + 1));
		}
		printf("%3d-%d", peak1, peak2);
		printf("\n   ");
		for (int j = 0; j < m - 1; j++) {  // цикл по столбцам
			printf("-----");
		}

		for (int i = 0; i < m; i++) {
			if (i != peak1 - 1 && i != peak2 - 1) {
				countJ = 0;
				for (int j = 0; j < m; j++) {
					if (j != peak1 - 1 && j != peak2 - 1) {
						task[i - countI][j - countJ] = a[i][j];
					}
					else
						countJ++;
				}
				task[i - countI][m - 2] = (a[peak1 - 1][i] + a[peak2 - 1][i]);

			}
			else countI++;
		}
		countI = 0;
		for (int i = 0; i < (m); i++) {
			if (i != peak1 - 1 && i != peak2 - 1) {
				printf("\n %d |", (i + 1)); // цикл по столбцам
				for (int j = 0; j < (k); j++) {
					printf("%4d ", task[i - countI][j]);
				}
			}
			else countI++;
		}
		countI = 0;

		printf("\n%d-%d|", peak1, peak2);
		for (int i = 0; i < m; i++) {
			if (i != peak2 - 1 && i != peak1 - 1)
				task[m - 2][i - countI] = (a[peak1 - 1][i] + a[peak2 - 1][i]);
			else
				countI++;
		}
		task[m - 2][m - 2] = (a[peak1 - 1][peak1 - 1] + a[peak1 - 1][peak2 - 1]);
		for (int j = 0; j < (k); j++) {
			printf("%4d ", task[m - 2][j]);
		}
	}

	else if (operation == 2) {
		int peak1 = 1, peak2 = 1, repeatCheck = 0, k = m - 1, countI = 0, countJ = 0;

		while (a[peak1 - 1][peak2 - 1] == 0) {
			printf("Select side (that exist):\n");
			scanf("%d%d", &peak1, &peak2);
		}


		int** task;
		task = (int**)malloc((k) * sizeof(int*));
		for (int i = 0; i < (k); i++) {
			task[i] = (int*)malloc((k) * sizeof(int));
			for (int j = 0; j < (k); j++) {
				task[i][j] = 0;
			}
		}
		//---------- printing matrix
		printf("\n\n   ");

		for (int j = 0; j < m; j++) {  // цикл по столбцам
			if (j != peak1 - 1 && j != peak2 - 1)
				printf("%5d", (j + 1));
		}
		printf("%3d-%d", peak1, peak2);
		printf("\n   ");
		for (int j = 0; j < m - 1; j++) {  // цикл по столбцам
			printf("-----");
		}

		for (int i = 0; i < m; i++) {
			if (i != peak1 - 1 && i != peak2 - 1) {
				countJ = 0;
				for (int j = 0; j < m; j++) {
					if (j != peak1 - 1 && j != peak2 - 1) {
						task[i - countI][j - countJ] = a[i][j];
					}
					else
						countJ++;
				}
				task[i - countI][m - 2] = (a[peak1 - 1][i] + a[peak2 - 1][i]);

			}
			else countI++;
		}
		countI = 0;
		for (int i = 0; i < (m); i++) {
			if (i != peak1 - 1 && i != peak2 - 1) {
				printf("\n %d |", (i + 1)); // цикл по столбцам
				for (int j = 0; j < (k); j++) {
					printf("%4d ", task[i - countI][j]);
				}
			}
			else countI++;
		}
		countI = 0;

		printf("\n%d-%d|", peak1, peak2);
		for (int i = 0; i < m; i++) {
			if (i != peak2 - 1 && i != peak1 - 1)
				task[m - 2][i - countI] = (a[peak1 - 1][i] + a[peak2 - 1][i]);
			else
				countI++;
		}
		task[m - 2][m - 2] = 0;
		for (int j = 0; j < (k); j++) {
			printf("%4d ", task[m - 2][j]);
		}
	}
	else if (operation == 3)
	{
		int peak, k = m + 1, count = 2, countJ = 0, countI = 0;
		printf("Select peak to divide:\n");
		scanf("%d", &peak);

		int** task;
		task = (int**)malloc((m + 1) * sizeof(int*));
		for (int i = 0; i < (m + 1); i++) {
			task[i] = (int*)malloc((m + 1) * sizeof(int));
			for (int j = 0; j < (m + 1); j++) {
				task[i][j] = 0;
			}
		}

		printf("\n\n   ");
		for (int j = 0; j < m; j++) {  // цикл по столбцам
			if (j != peak - 1)
				printf("%5d", (j + 1));
		}
		printf("%3d.1%3d.2", peak, peak);

		printf("\n   ");
		for (int j = 0; j < k; j++) {  // цикл по столбцам
			printf("-----");
		}
		for (int i = 0; i < m; i++) {
			if (i != peak - 1) {
				countJ = 0;
				for (int j = 0; j < m; j++) {
					if (j != peak - 1) {
						task[i - countI][j - countJ] = a[i][j];
					}
					else
						countJ++;
				}
				if (a[i][peak - 1] == 0) {
					task[i - countI][m - 1] = 0;
					task[i - countI][m] = 0;
				}
				else if (count % 2 == 0) {
					task[i - countI][m - 1] = 1;
					task[i - countI][m] = 0;
					count++;
				}
				else if (count % 2 == 1) {
					task[i - countI][m - 1] = 0;
					task[i - countI][m] = 1;
					count++;
				}
			}
			else countI = 1;
		}

		for (int i = 0; i < (m - 1); i++) {
			if (i >= peak - 1) {
				printf("\n %d |", (i + 2)); // цикл по столбцам
				for (int j = 0; j < (m + 1); j++) {
					printf("%5d", task[i][j]);
				}
			}
			else {
				printf("\n %d |", (i + 1)); // цикл по столбцам
				for (int j = 0; j < (m + 1); j++) {
					printf("%5d", task[i][j]);
				}
			}

		}

		printf("\n%d.1|", peak);
		for (int j = 0; j < m - 1; j++) {
			task[m - 1][j] = task[j][m - 1];
			task[m][j] = task[j][m];
		}
		task[m - 1][m - 1] = 0;
		task[m - 1][m] = 1;
		task[m][m - 1] = 1;
		task[m][m] = 0;

		for (int j = 0; j < (m + 1); j++) {
			printf("%5d", task[m - 1][j]);
		}

		printf("\n%d.2|", peak);

		for (int j = 0; j < (m + 1); j++) {
			printf("%5d", task[m][j]);
		}

	}

	//------------------
	// (3)
	int** Sum, ** Mul, ** RSum;
	Sum = (int**)malloc((m) * sizeof(int*));
	Mul = (int**)malloc((m) * sizeof(int*));
	RSum = (int**)malloc((m) * sizeof(int*));
	for (int i = 0; i < m; i++) {
		Sum[i] = (int*)malloc(m * sizeof(int));
		Mul[i] = (int*)malloc(m * sizeof(int));
		RSum[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++) {
			Sum[i][j] = 0;
			Mul[i][j] = 0;
			RSum[i][j] = 0;
		}
	}
	printf("\n\n\n SUM:\n");

	printf("   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("%5d", (j + 1));
	}
	printf("\n   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("-----");
	}
	for (int i = 0; i < m; i++) {
		printf("\n %d |", (i + 1)); // цикл по столбцам
		for (int j = 0; j < m; j++) {
			Sum[i][j] = (a[i][j] + b[i][j]);
			if (Sum[i][j] == 2) Sum[i][j] = 1;
			printf("%4d ", Sum[i][j]);
		}
	}

	printf("\n\n\n Multiplying:\n");

	printf("   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("%5d", (j + 1));
	}
	printf("\n   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("-----");
	}
	for (int i = 0; i < m; i++) {
		printf("\n %d |", (i + 1)); // цикл по столбцам
		for (int j = 0; j < m; j++) {
			Mul[i][j] = (a[i][j] * b[i][j]);
			printf("%4d ", Mul[i][j]);
		}
	}

	printf("\n\n\n Ring sum:\n");

	printf("   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("%5d", (j + 1));
	}
	printf("\n   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("-----");
	}
	for (int i = 0; i < m; i++) {
		printf("\n %d |", (i + 1)); // цикл по столбцам
		for (int j = 0; j < m; j++) {
			if (a[i][j] + b[i][j] == 1)
				RSum[i][j] = 1;
			else
				RSum[i][j] = 0;
			printf("%4d ", RSum[i][j]);
		}
	}

	//------------------
	// (4)
	int** D;
	const int l = m * m;
	int count = -1;
	D = (int**)malloc(l * sizeof(int*));

	for (int i = 0; i < l; i++) {
		D[i] = (int*)malloc(l * sizeof(int));
		for (int j = 0; j < l; j++) {
			D[i][j] = 0;
		}
	}


	for (int x1 = 0; x1 != m; x1++) {

		for (int y1 = 0; y1 != m; y1++) {
			D[x1 * m + y1] = new int[m * m];

			for (int x2 = 0; x2 != m; x2++) {

				for (int y2 = 0; y2 != m; y2++) {
					if (x1 == x2) {
						D[x1 * m + y1][x2 * m + y2] = b[y1][y2];
					}
					else if (y1 == y2) {
						D[x1 * m + y1][x2 * m + y2] = a[x1][x2];
					}
					else D[x1 * m + y1][x2 * m + y2] = 0;
				}
			}
		}
	}


	printf("\n\n\n Dekart:\n");
	printf("     ");
	for (int i = 0; i < m; i++) {  // цикл по столбцам
		for (int j = 0; j < m; j++) // цикл по столбцам
			printf("%2d.%d", (i + 1), (j + 1));
	}
	printf("\n     ");
	for (int j = 0; j < l; j++) {  // цикл по столбцам
		printf("----");
	}
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < m; k++) {
			printf("\n %2d.%d|", (i + 1), (k + 1)); // цикл по столбцам
			for (int j = 0; j < l; j++) {
				printf("%3d ", D[i * m + k][j]);
			}
		}
	}

	free(a);
	free(b);
	free(D);
	getchar();
	getchar();
	return(0);
}