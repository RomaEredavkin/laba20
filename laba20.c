#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h> 
#define MAX_N 8
#define MAX_M 10
int nums;
int num;
int arr[MAX_N][MAX_M];
int n;
int m;
void load() {

	FILE* fin = fopen("c:\\Programs\\in10.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fin, "%d", &arr[i][j]);
		}
	}

	fclose(fin);
}



void print() {
	printf("!!!! print() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}
void fillIx10() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = i * 10 + j;
		}
	}
}
void fillZero() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}
}
void randFill0_9() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}
void del10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 10 == 0){ 
				arr[i][j] = arr[i][j] / 10; 

		    }
		}

	}

} 
void del2() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 != 0) {
				arr[i][j] = arr[i][j] * 10;

			}
		}

	}

}
void save() {
	
	FILE* fout = fopen("c:\\Programs\\out11.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d ", n);
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(fout, "%d ", arr[i][j]);
		}
		fprintf(fout, "\n");
	}

	fclose(fout);
}
void deleteRow(int delRow) {
	printf("!!!! deleteRow(%d) !!!!\n", delRow);
	for (int i = delRow; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n--;
}

void addColumn0() {
	

	if (m < MAX_M) {
		for (int i = 0; i < n; i++) {
			arr[i][m] = 0;
		}
		m++;
	}

}
void hp() {
	for (int j = 0; j < m; j++) {
		if ((arr[n][j] % 2 != 0) &(arr[n][j + 1] % 2 != 0)& (arr[n][j + 2] % 2 != 0)) {
			arr[n][j] = 0;
		}
	}

}

int item;
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	do {
		
		print();
		
		printf("Выберите нужную вам операцию\n"); 
		printf("1: Заполнить значениями i * 10 + j\n"); 
		printf("2: Заполнить нулями\n"); 
		printf("3: Заполнить случайными значениями\n"); 
		printf("4: Все нечетные увеличить в 10 раз\n"); 
		printf("5: Все кратные 10 уменьшить в 10 раз\n"); 
		printf("6: сохранить массив в файл\n");
		printf("7: удалить заданную строку из массива\n");
		printf("8: Дублировать столбец\n");
		printf("9: A10 обнулить тех столбцов в которых нет не одного четного элемента\n");
		printf("\n"); 
		printf("-1: выйти из операции\n"); 
		printf("Введенная операция>>>>"); 
		scanf_s("%d", &item);
		load();
		switch (item) {
		case 1: 
			fillIx10(); 
			break; 
		case 2:
			fillZero(); 
			break; 
		case 3: 
			randFill0_9();
			break;
		case 5: 
			del10(); 
			break; 
		case 4:
			del2(); 
			break; 
		case 6: 
			save(); 
			break; 
		case 7: 
			 
			printf("Номер строки которую нужно удалить\n"); 
			scanf_s("%d", &num);
			
			deleteRow(num); 
			break;
		case 8: 
			printf("введите номер строки которую хотите продублировать\n"); 
			scanf_s("%d", &nums); 
			addColumn0();
			break; 
		case 9: 
			hp(); 
			break;
		} 


	} while (item != 0);
}