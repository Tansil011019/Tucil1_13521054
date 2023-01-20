#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "adt/boolean.h"
// #include "adt/wordmachine.h"

#define TABLE_SIZE 100

struct HashTable {
    int key;
    int value;
};

typedef struct{
    int array[4];
    int length;
}data;

data input_data;

typedef struct{
    int all_combination_data[1000][4];
    int length;
}combination_data;

combination_data combi_data;

char operator[4] = {'+', '-', '/', '*'};

combination_data combi_op;

struct HashTable ht[TABLE_SIZE];

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    while (ht[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    ht[index].key = key;
    ht[index].value = value;
}

int search(int key) {
    int index = hash(key);
    int counter = 0;
    while (ht[index].key != key && counter++ < TABLE_SIZE) {
        index = (index + 1) % TABLE_SIZE;
    }
    return ht[index].value;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert_combination_to_matrix(int list[], int start, int end, combination_data res_list, int * n) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            res_list.all_combination_data[res_list.length][i] = list[i];
            printf("%d ", res_list.all_combination_data[res_list.length][i]);
        }
        res_list.length++;
        (*n)++;
        printf("\n");
    }
    else {
        for (int i = start; i <= end; i++) {
            swap(&list[start], &list[i]);
            insert_combination_to_matrix(list, start + 1, end, res_list, n);
            swap(&list[start], &list[i]);
        }
    }
}

void get_all_combination(){
    int count= 0;
    insert_combination_to_matrix(input_data.array, 0, 3, combi_data, &count);
    combi_data.length = count;
}

void brute_force(){
    get_all_combination();
    
}

void input_random(){
    while(input_data.length < 4){
        input_data.array[input_data.length] = (rand()%13)+1;
        input_data.length++;
    }
}

void read_input(){
    char input[5];
    int temp;
    for (int i = 0; i < 4; i++) {
        scanf("%s", input);
        if (strlen(input) == 1 && input[0] > '1' && input[0] <= '9') {
            temp = input[0] - '0';
        } else if (strlen(input) == 2 && input[0] == '1' && input[1] == '0') {
            temp = 10;
        } else if (strlen(input) == 1 && (input[0] == 'A' || input[0] == 'a')) {
            temp = 1;
        } else if (strlen(input) == 1 && (input[0] == 'K' || input[0] == 'k')) {
            temp = 13;
        } else if (strlen(input) == 1 && (input[0] == 'Q' || input[0] == 'q')) {
            temp = 12;
        } else if (strlen(input) == 1 && (input[0] == 'J' || input[0] == 'j')) {
            temp = 11;
        } else {
            printf("Invalid input, please enter a valid number\n");
            i--;
            continue;
        }
        input_data.array[input_data.length] = temp;
        input_data.length++;
    }
}

void input_user(){
    printf(
        "Rules:\n"
        "1. If your input more than 4 and valid than the rest of your input will be ignored\n"
        "2. If your input is not valid, the input after will replace it\n\n"
        "Please input 4 items below!\n"
    );
    read_input();
}

void input_choice(){
    combi_data.length = 0;
    input_data.length = 0;
    int choice;
    printf("\nPlease input your choice here: ");
    scanf("%d", &choice);
    if(choice == 1){
        input_user();
    }else if(choice == 2){
        input_random();
    }else{
        printf("Your input is wrong please try again!\n");
        input_choice();
    }
}

int main(){
    printf(
        "Welcome to 24 games!\n"
        "There is 2 option that you can choose,\n"
        "You can either choose random or input yourself\n"
        "If you want to input yourself please press 1 otherwise press 2\n"
    );
    input_choice();
    brute_force();
    printf("This is length = %d", combi_data.length);
    // for(int i= 0; i<input_data.length; i++){
    //     printf("%d\n", input_data.array[i]);
    // }
}