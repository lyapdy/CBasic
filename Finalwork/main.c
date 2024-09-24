#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "temp_functions.h"

char file_name[256];
int a;
int y, m, d, h, mi, t;
int rez, nm, check, error;
FILE *f;
struct temperature month[12] = {0};
union u union_month = {0};

int main(int argc, char *argv[]) {

    print_info(); 
    
    check = scan_keys(argc, argv, file_name, union_month, rez, nm);
    
    error = scan_data(month, f, file_name, a, y, m, d, h, mi, t);

    print_stats(month, check, error);
    
    return 0;
}