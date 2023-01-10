#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_line(FILE* fp){
    int bufflen = 255;
    char buff[bufflen];
    
    while(fgets(buff, bufflen, fp)){
        printf("%s\n", buff);
    }
    return 0;
}

int write_to_customer_otp(int start_row, int num_rows_to_program, int value){
    // command base
    char cmd[100];
    strcpy(cmd, "/opt/vc/bin/vcmailbox 0x00038021");
    // add row to program into string twice
    int n1 = 8 + num_rows_to_program * 4;
    char buf[10];
    sprintf(buf, "%d", n1);
    strcat(cmd, " ");
    for(int i = 0; i < 2; i++){
        strcat(cmd, buf);
        strcat(cmd, " ");
    }
    //reset buffer and add start_row
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "%d", start_row);
    strcat(cmd, buf);
    strcat(cmd, " ");
    //reset buffer and add number
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "%d", num_rows_to_program);
    strcat(cmd, buf);
    strcat(cmd, " ");
    //reset buffer and add in value twice
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "%d", value);
    for(int i = 0; i < 2; i++){
        strcat(cmd, buf);
        strcat(cmd, " ");
    }
    printf("cmd: %s\n",cmd);
    //put output in file pointer for access
    FILE* output;
    output = popen(cmd, "r");
    read_line(output);
    return 0;
}

int read_back_data(int start_row, int num_rows, int blocks_to_read){
    //command base
    char cmd[100];
    strcpy(cmd, "/opt/vc/bin/vcmailbox 0x0030021");
    // add row to program into string twice
    int n1 = 8 + num_rows * 4;
    char buf[10];
    sprintf(buf, "%d", n1);
    strcat(cmd, " ");
    for(int i = 0; i < 2; i++){
        strcat(cmd, buf);
        strcat(cmd, " ");
    }
    //reset buffer and add start_num
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "%d", start_row);
    strcat(cmd, buf);
    strcat(cmd, " ");
    for(int i = 0; i < blocks_to_read; i++){
        strcat(cmd, "0");
        strcat(cmd, " ");
    }
    printf("cmd: %s\n", cmd);
    //put output in file pointer for access
    FILE* output;
    output = popen(cmd, "r");
    read_line(output);
    return 0;
}

int lock_data(){
    char* cmd = "/opt/vc/bin/vcmailbox 0x0038021 8 8 0xffffffff 0xaffe0000";
    FILE* output;
    output = popen(cmd, "r");
    read_line(output);
    return 0;
}

