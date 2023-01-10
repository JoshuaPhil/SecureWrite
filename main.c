#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "securewrite.h"



int main(){
    write_to_customer_otp(1, 2, 3);
    read_back_data(1, 2, 3);
    lock_data();
    return 0;
}
