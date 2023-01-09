#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "securewrite.h"

int main(){
    FILE *o1, *o2, *o3;
    write_to_customer_otp(1, 2, 3, o1);
    read_back_data(1, 2, 3, o2);
    lock_data(o3);
    return 0;
}