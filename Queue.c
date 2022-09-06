#include<stdio.h>

void add(char Line[][10], int* size, int max_line);
void pull_out(char Line[][10], int* size);
void show(char Line[][10], int* size);


int main() {

	char Line[10][10];
	int max_line = sizeof(Line) / sizeof(Line[0]);
	int size = 0;
	char user_choice;
	//char *Pline = &Line;

	do {
		
		printf("\npress (a) to Add to the Queue \n");
		printf("press (p) to pull out of the Queue \n");
		printf("press (e) to exit the program \n");
		scanf_s("%c", &user_choice, 1);

		switch (user_choice) {
			case ('a'): add( Line, &size, max_line);
				break;
			case ('p'): pull_out( Line, &size);
				break;
			default:
				break;
		}
		
		show(Line, &size);

		while ((getchar()) != '\n');

	} while (user_choice != 'e');
	

	return 0;
}

void add(char Line[][10], int* size, int max_line) {

	if (*size < max_line) {
		
		printf("Enter name to add to the Queue: ");
		scanf_s("%s", &Line[*size], 10);

		*size = *size + 1;
		
	}
	else {
		printf("The queue is full! \n");
	}
	
};

void pull_out(char Line[][10], int* size) {

	if (*size > 0){
		*size = *size - 1;
		for (int i = 0; i < *size; i++) {
			strcpy(Line[i] , Line[i + 1]);

			//printf("%s", Line[i]);
		}
	}
	else {
		printf("The queue is empty! \n");
	}
	
};

void show(char Line[][10], int* size) {

	for (int i = 0; i < *size; i++) {
		printf("%s ", Line[i]);
	}
	printf("\n");

};