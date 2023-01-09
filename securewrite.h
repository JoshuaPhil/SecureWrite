#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_to_customer_otp(int start_row, int num_rows_to_program, int value, FILE* output){
    // command base
    char cmd[100];
    strcpy(cmd, "/opt/vc/bin/vcmailbox 0x00038021");
    // add row to program into string twice
    int n1 = 8 + num_rows_to_program * 4;
    char buf[10];
    itoa(n1, buf, 10);
    strcat(cmd, " ");
    for(int i = 0; i < 2; i++){
        strcat(cmd, buf);
        strcat(cmd, " ");
    }
    //reset buffer and add start_row
    memset(buf, 0, sizeof(buf));
    itoa(start_row, buf, 10);
    strcat(cmd, buf);
    strcat(cmd, " ");
    //reset buffer and add number
    memset(buf, 0, sizeof(buf));
    itoa(num_rows_to_program, buf, 10);
    strcat(cmd, buf);
    strcat(cmd, " ");
    //reset buffer and add in value twice
    memset(buf, 0, sizeof(buf));
    itoa(value, buf, 10);
    for(int i = 0; i < 2; i++){
        strcat(cmd, buf);
        strcat(cmd, " ");
    }
    printf("cmd: %s\n",cmd);
    //put output in file pointer for access
    output = popen(cmd, "r");
    return 0;
}

int read_back_data(int start_row, int num_rows, int blocks_to_read, FILE* output){
    //command base
    char cmd[100];
    strcpy(cmd, "/opt/vc/bin/vcmailbox 0x0030021");
    // add row to program into string twice
    int n1 = 8 + num_rows * 4;
    char buf[10];
    itoa(n1, buf, 10);
    strcat(cmd, " ");
    for(int i = 0; i < 2; i++){
        strcat(cmd, buf);
        strcat(cmd, " ");
    }
    //reset buffer and add start_num
    memset(buf, 0, sizeof(buf));
    itoa(start_row, buf, 10);
    strcat(cmd, buf);
    strcat(cmd, " ");
    for(int i = 0; i < blocks_to_read; i++){
        strcat(cmd, "0");
        strcat(cmd, " ");
    }
    printf("cmd: %s\n", cmd);
    //put output in file pointer for access
    output = popen(cmd, "r");
    return 0;
}

int lock_data(FILE* output){
    char* cmd = "/opt/vc/bin/vcmailbox 0x0038021 8 8 0xffffffff 0xaffe0000";
    output = popen(cmd, "r");
}
