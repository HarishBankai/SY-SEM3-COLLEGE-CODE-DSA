#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct employee {
    int id;
    char name[50];
    float salary;
};

struct employee database[MAX];
int count = 0;

void create() {
    int i;

    printf("Enter number of employees: ");
    scanf("%d", &count);
    getchar();  
    for (i = 0; i < count; i++) {
        printf("\nEmployee %d\n", i + 1);

        printf("Enter id of employee: ");
        scanf("%d", &database[i].id);
        getchar();  

        printf("Enter name of employee: ");
        fgets(database[i].name, sizeof(database[i].name), stdin);
        
        database[i].name[strcspn(database[i].name, "\n")] = '\0';

        printf("Enter salary of employee: ");
        scanf("%f", &database[i].salary);
        getchar();  
    }
}

int main() {
    create();

    printf("\nEntered employee details:\n");
    for (int i = 0; i < count; i++) {
        printf("Employee %d: ID=%d, Name=%s, Salary=%.2f\n",
               i + 1, database[i].id, database[i].name, database[i].salary);
    }

    return 0;
}

