#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "temp_functions.h"

float average_value(struct temperature* month, int n) {
    long signed int sum_f = month[n].sum, count_f = month[n].count;
    float average_f = 0.0;
    average_f = sum_f / count_f;
    if (average_f == 0.0) {
        return 0.0;
    }
    else {
        return average_f;
    }
}

int max_value(struct temperature* month, int n, int t) {
    int max_f;
    if (month[n].count != 0) {
        max_f = month[n].max_t;
    }
    else {
        max_f = -100;
    }
    if (t > max_f) {
        max_f = t;
    }
    return max_f; 
}

int min_value(struct temperature* month, int n, int t) {
    int min_f;
    if (month[n].count != 0) {
        min_f = month[n].min_t;
    }
    else {
        min_f = 100;
    }
    if (t < min_f) {
        min_f = t;
    }
    return min_f; 
}

float average_value_year(struct temperature* month) {
    float sum_year = 0, count_year = 12.0, average_year = 0.0;
    for (int i = 1; i <= 12; i++) {
        sum_year += average_value(month, i);
    }
    average_year = sum_year / count_year;
    if (average_year == 0.0) {
        return 0.0;
    }
    else {
        return average_year;
    }
}

int max_value_year(struct temperature* month) {
    int max_year = month[1].max_t;
    for (int i = 2; i <= 12; i++) {
        if (month[i].max_t > max_year) {
            max_year = month[i].max_t;
        }
    }
    return max_year; 
}

int min_value_year(struct temperature* month) {
    int min_year = month[1].min_t;
    for (int i = 2; i <= 12; i++) {
        if (month[i].min_t < min_year) {
            min_year = month[i].min_t;
        }
    }
    return min_year; 
}

void print_space() {
    printf("\n");
}

void print_info() {
    print_space();
    printf("This console application is a project for course 'Basic Programming in C'.\n");
    printf("This console application displays average, minimal and maximal temperature per each month and per a year.\n");
}

int scan_keys(int argc, char *argv[], char *file_name, union u union_month, int rez, int nm) {
    int check = 0;
    while ((rez = getopt(argc, argv, "hf:m:")) != -1) {
        switch(rez) {
            case 'h': printf("Set of supported keys by the application:\n\
                -h Description of the application functionality. List of keys that handles the given application and their purpose.\n\
                -f <filename.csv> input csv file to process.\n\
                -m <month number> if this key is given, then output only statistics for the specified month.\n"); break;
            case 'f': strcpy(file_name, optarg);
                print_space();
                printf("Input csv file to process: %s\n", file_name);
                check = 365; break;
            case 'm': strcpy(union_month.ch, optarg);
                print_space();
                switch(union_month.i) {
                    case 49: nm = 1; break;
                    case 50: nm = 2; break;
                    case 51: nm = 3; break;
                    case 52: nm = 4; break;
                    case 53: nm = 5; break;
                    case 54: nm = 6; break;
                    case 55: nm = 7; break;
                    case 56: nm = 8; break;
                    case 57: nm = 9; break;
                    case 12337: nm = 10; break;
                    case 12593: nm = 11; break;
                    case 12849: nm = 12; break;
                }
                printf("Current month: %d\n", nm); 
                check = nm; break;
            case '?': print_space(); 
                printf("Error found! No such key %s exists. Try -h for help.\n", argv[optind-1]); break;
        }
    }
    return check;
}

int scan_data(struct temperature* month, FILE *f, char *file_name, int a, int y, int m, int d, int h, int mi, int t) {
    _Bool check_error = false, error_text = true;
    int error = 0; 
    f = fopen(file_name, "r");
    while ((a = (fscanf(f, "%d; %d; %d; %d; %d; %d", &y, &m, &d, &h, &mi, &t))) != EOF) {
        if (a != 6) {
            check_error = true;
            if (check_error && error_text) {
                print_space();
                printf("Error list\n");
                check_error = false;
                error_text = false;
            }
            char error[100] = {0};
            fscanf(f, "%[^\n]", error);
            fprintf(stderr, "Error string: %s\n", error);
        } else {
            month[m].info.year = y;
            month[m].info.day = d;
            month[m].info.month = m;
            month[m].info.hour = h;
            month[m].info.min = mi;
            month[m].min_t = min_value(month, m, t);
            month[m].max_t = max_value(month, m, t);
            month[m].sum += t;
            month[m].count++;
        }
    }
    if (f == NULL) { 
        print_space();
        printf("Can't open file %s! Please try again.\n", file_name);
        print_space();
        return error = 1;
    }
    fclose(f);
}

void print_stats(struct temperature* month, int check, int error) {
    if (check != 0 && check != 365 && error != 1) {
        print_space();
        printf("Stats per a choosen month\n"); 
        printf("Average = %0.2f Min = %d Max = %d Count = %ld\n", average_value(month, check), month[check].min_t, month[check].max_t, month[check].count);
        print_space();
    }
    else if (check == 365 && error != 1) {
        print_space();
        printf("Stats per each month\n");
        for (int i = 1; i <= 12; i++) {
            printf("Month %d Average = %0.2f Min = %d Max = %d Count = %ld\n", i, average_value(month, i), month[i].min_t, month[i].max_t, month[i].count);
        }
        print_space();
        printf("Stats per a year\n");
        printf("Average = %0.2f Min = %d Max = %d\n", average_value_year(month), min_value_year(month), max_value_year(month));
        print_space();
    }
}