#include<stdio.h>
#include"my_hash.h"
#include<math.h>
#include<stdarg.h>


void test(int a[]){
    printf("%x\n", a);
    a[0] = 10;
}

double average(int n_values, ...){
    va_list args;
    double sum = 0.0;
    va_start(args, n_values);
    for(int i = 0; i < n_values; ++i){
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum / n_values;
}

int main(){
    int a[5] = {1,2,3,4,5};
    printf("%x\n", a);
    printf("%x\n", &a[0]);

    // struct hash *dict = NULL;
    // add(&dict, 1, "one");
    // add(&dict, 2, "two");
    // add(&dict, 4, "four");
    // add(&dict, 3, "three");
    // sort_by_id(&dict);
    // print_hash(&dict);

    // struct hash *test = find_id(&dict, 1);
    // if(test){
    //     printf("%s\n", test->name);
    //     // delete_id(&dict, test);
    //     delete_all(&dict);
    // }else{
    //     printf("not found\n");
    // }

}