#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// boolean declaration 
#define boolean unsigned char
#define true 1
#define false 0

// input data type and decalaration
typedef struct{
    double array[4];
    int length;
}data;

data input_data;

// input data combination data type and declaration
typedef struct{
    double all_combination_data[1000][4];
    int length;
}combination_data;

combination_data combi_data;

// operator declaration
enum operator {PLUS = 1, MINUS = 2, DIVIDE = 3, MUL = 4};

int operator_arr[4] = {PLUS, MINUS, DIVIDE, MUL};

char operator_char[4] = {'+', '-', '/', '*'};

// operator combination data type and declaration
typedef struct{
    int all_combination_data[1000][3];
    int length;
}combination_op;

combination_op combi_op;

// result combination data type and declaration
typedef struct{
    char all_combination_data[1000][1000];
    int length;
}combination_res;

combination_res result_storage;

// stopwatch declaration
clock_t start_time, end_time;

// result of an expression between two number
double result_count(double first_num, int op, double second_num){
    if(op == 1){
        return first_num + second_num;
    }else if(op == 2){
        return first_num - second_num;
    }else if(op == 3){
        if(second_num != 0){
            return first_num / second_num;  
        }else{
            return -28561; // if the divisor is 0, then it will be minus 13^4 (the greatest amount of the card possible) so that it is impossible to result 24
        }
    }else if(op == 4){
        return first_num * second_num;
    }
}

// find all operator combination (take 3 from 4)
void operator_permute(){
    for(int i= 0; i< 4; i++){
        for(int j= 0; j< 4; j++){
            for(int k= 0; k< 4; k++){
                combi_op.all_combination_data[combi_op.length][0] = operator_arr[i];
                combi_op.all_combination_data[combi_op.length][1] = operator_arr[j];
                combi_op.all_combination_data[combi_op.length][2] = operator_arr[k];
                combi_op.length++;
            }
        }
    }
}

// store the result in result data type that had been declared before
void convert_operation_and_store(double * num, int op[], int type){
    char str[100];
    if(type == 5){
        sprintf(str, "(%0.f %c %0.f) %c (%0.f %c %0.f)", num[0], operator_char[(op[0])-1], num[1], operator_char[(op[1])-1], num[2], operator_char[(op[2])-1], num[3]);
    }else if(type == 4){
        sprintf(str, "%0.f %c (%0.f %c (%0.f %c %0.f))", num[0], operator_char[(op[0])-1], num[1], operator_char[(op[1])-1], num[2], operator_char[(op[2])-1], num[3]);
    }else if(type == 3){
        sprintf(str, "%0.f %c ((%0.f %c %0.f) %c %0.f)", num[0], operator_char[(op[0])-1], num[1], operator_char[(op[1])-1], num[2], operator_char[(op[2])-1], num[3]);
    }else if(type == 2){
        sprintf(str, "(%0.f %c (%0.f %c %0.f)) %c %0.f", num[0], operator_char[(op[0])-1], num[1], operator_char[(op[1])-1], num[2], operator_char[(op[2])-1], num[3]);
    }else if(type == 1){
        sprintf(str, "((%0.f %c %0.f) %c %0.f) %c %0.f", num[0], operator_char[(op[0])-1], num[1], operator_char[(op[1])-1], num[2], operator_char[(op[2])-1], num[3]);
    }
    boolean duplicate = false;
    // find if there is duplicate value
    for(int i= 0; i< result_storage.length && !duplicate; i++){
        if(strcmp(result_storage.all_combination_data[i], str) == 0){
            duplicate = true;
        }
    }
    // if there is no duplicate value than it is valid to be stored
    if(!duplicate){
        strcpy(result_storage.all_combination_data[result_storage.length], str);
        result_storage.length++;
    }
}
    
// game progression place
void games_operator(){
    for(int i= 0; i< combi_op.length; i++){
        for(int j= 0; j< combi_data.length; j++){
            // every bracket combination
            double combination_bracket1 = result_count(result_count(result_count(combi_data.all_combination_data[j][0], combi_op.all_combination_data[i][0], combi_data.all_combination_data[j][1]), combi_op.all_combination_data[i][1], combi_data.all_combination_data[j][2]), combi_op.all_combination_data[i][2], combi_data.all_combination_data[j][3]);
            double combination_bracket2 = result_count(result_count(combi_data.all_combination_data[j][0], combi_op.all_combination_data[i][0], result_count(combi_data.all_combination_data[j][1], combi_op.all_combination_data[i][1], combi_data.all_combination_data[j][2])), combi_op.all_combination_data[i][2], combi_data.all_combination_data[j][3]);
            double combination_bracket3 = result_count(combi_data.all_combination_data[j][0], combi_op.all_combination_data[i][0], result_count(result_count(combi_data.all_combination_data[j][1], combi_op.all_combination_data[i][1], combi_data.all_combination_data[j][2]), combi_op.all_combination_data[i][2], combi_data.all_combination_data[j][3]));
            double combination_bracket4 = result_count(combi_data.all_combination_data[j][0], combi_op.all_combination_data[i][0], result_count(combi_data.all_combination_data[j][1], combi_op.all_combination_data[i][1], result_count(combi_data.all_combination_data[j][2], combi_op.all_combination_data[i][2], combi_data.all_combination_data[j][3])));
            double combination_bracket5 = result_count(result_count(combi_data.all_combination_data[j][0], combi_op.all_combination_data[i][0], combi_data.all_combination_data[j][1]), combi_op.all_combination_data[i][1], result_count(combi_data.all_combination_data[j][2], combi_op.all_combination_data[i][2], combi_data.all_combination_data[j][3]));
            // if the bracket combination result is 24
            if(combination_bracket1 == 24){
                convert_operation_and_store(combi_data.all_combination_data[j], combi_op.all_combination_data[i], 1);
            }
            if(combination_bracket2 == 24){
                convert_operation_and_store(combi_data.all_combination_data[j], combi_op.all_combination_data[i], 2);
            }
            if(combination_bracket3 == 24){
                convert_operation_and_store(combi_data.all_combination_data[j], combi_op.all_combination_data[i], 3);
            }
            if(combination_bracket4 == 24){
                convert_operation_and_store(combi_data.all_combination_data[j], combi_op.all_combination_data[i], 4);
            }
            if(combination_bracket5 == 24){
                convert_operation_and_store(combi_data.all_combination_data[j], combi_op.all_combination_data[i], 5);
            }
        }
    }
}

// swapping two double variable
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// find all combination of input data using recursion
void insert_combination_to_matrix(double list[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            combi_data.all_combination_data[combi_data.length][i] = list[i];
        }
        combi_data.length++;
    }
    else {
        for (int i = start; i <= end; i++) {
            swap(&list[start], &list[i]);
            insert_combination_to_matrix(list, start + 1, end);
            swap(&list[start], &list[i]);
        }
    }
}

// get combination of input data and operator
void get_all_combination(){
    insert_combination_to_matrix(input_data.array, 0, 3);
    operator_permute();
}

// the begining of the process where we find all the combination and process it
void brute_force(){
    start_time = clock();
    get_all_combination();
    games_operator();
}

// input random data which is validated as instruction which is poker card
void input_random(){
    srand(time(NULL));
    printf("Your random input is = ");
    while(input_data.length < 4){
        input_data.array[input_data.length] = (double)(rand()%13)+1;
        if(input_data.array[input_data.length] == 13){
            printf("K ");
        }else if(input_data.array[input_data.length] == 12){
            printf("Q ");
        }
        else if(input_data.array[input_data.length] == 11){
            printf("J ");
        }else{
            printf("%0.f ", input_data.array[input_data.length]);
        }
        input_data.length++;
    }
    printf("\n");
}

// read user input and convert to double
void read_input(){
    char input[5];
    double temp;
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
    // counter for input in one line
    fgets(input, 10000, stdin);
}

// user input beginning and instruction
void input_user(){
    printf(
        "Rules:\n"
        "1. If your input more than 4 and valid than the rest of your input will be ignored\n"
        "2. If your input is not valid, the input after will replace it\n\n"
        "Please input 4 items below!\n"
    );
    read_input();
}

// user input choice with validator wheter user want to random input or input their own
void input_choice(){
    result_storage.length = 0;
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

// output part with some instruction wheter want to display on terminal or file and validator
void output_choice();

void progress_output(int choice){
    double total_time;
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    if(choice == 1){
        printf("%d solution found\n", result_storage.length);
        for(int i= 0; i< result_storage.length; i++){
            printf("%s\n", result_storage.all_combination_data[i]);
        }
        printf("Elapsed time: %f seconds\n", total_time);
    }else if(choice == 2){
        char file_name[100];
        printf("Please include the file name that you want to save in: ");
        scanf("%s", file_name);
        FILE * file;
        char path[200] = "../test/";
        strcat(path, file_name);
        file = fopen(path, "w");
        if(file == NULL){
            printf("Error opening file!\n");
        }else{
            fprintf(file, "%d solution found\n", result_storage.length);
            for(int i= 0; i< result_storage.length; i++){
            fprintf(file, "%s\n", result_storage.all_combination_data[i]);
            }
            fprintf(file, "Elapsed time: %f seconds", total_time);
        }
    }else{
        printf("Your input is wrong, Please try again!\n");
        output_choice();
    }
}

void output_choice(){
    int choice_output;
    printf(
        "\nHow do you wanna output?\n"
        "1. Terminal\n"
        "2. File\n"
        "Please include the number in front of your choice!\n"
    );
    printf("\nPlace you choice here: ");
    scanf("%d", &choice_output);
    progress_output(choice_output);
}

// restart progress
void home();

void restart_choice();

void restart_progress(char * restart){
    if(strcmp(restart, "yes") == 0){
        printf("\nOkay, let's have fun again!\n");
        home();
    }else if(strcmp(restart, "no") == 0){
        printf("\nWe will wait you back, Bye ^^!\n");
        exit(0);
    }else{
        printf("\nYour input is wrong, Please reinput!\n");
        restart_choice();
    }
}

void restart_choice(){
    char restart[10];
    printf(
        "Please include yes or no!\n"
        "Do you want to continue? "
    );
    scanf("%s", restart);
    restart_progress(restart);
}

// home page
void home(){
    printf(
"________    _____                                        \n"                            
"\\_____  \\  /  |  |     _________    _____   ____   ______\n"
" /  ____/ /   |  |_   / ___\\__  \\  /     \\_/ __ \\ /  ___/\n"
"/       \\/    ^   /  / /_/  > __ \\|  Y Y  \\  ___/ \\___ \\ \n"
"\\_______ \\____   |   \\___  (____  /__|_|  /\\___  >____  >\n"
"        \\/    |__|  /_____/     \\/      \\/     \\/     \\/ \n"
" _______   _______   _______   _______\n"
"|       | |       | |       | |       |\n"
"|   A   | |   2   | |   3   | |   4   |\n"
"|_______| |_______| |_______| |_______|\n"
        "Welcome to 24 games!\n"
        "There is 2 option that you can choose,\n"
        "You can either choose random or input yourself\n"
        "If you want to input yourself please press 1 otherwise press 2\n"
    );
    input_choice();
    brute_force();
    end_time= clock();
    output_choice();
    restart_choice();
}

// main
int main(){
    system("cls");
    home();
}