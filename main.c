#include <stdio.h>
#include <stdint.h>

#include "add.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일1> <파일2> ... <파일N>\n", argv[0]);
        return 0;
    }

    
   uint32_t result;

    

    result=add(argc, argv);

    if(result !=0){
        printf(" = %u(0x%08x)\n", result, result);
    }
    

    return 0;
}

