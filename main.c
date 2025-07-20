#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>  // ntohl 사용을 위한 헤더

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일1> <파일2> ... <파일N>\n", argv[0]);
        return 1;
    }

    FILE *file;
    uint32_t temp;   // 부호 없는 32비트 정수 !! 
    uint32_t sum = 0;  
    int i;

    printf("연산 시작:\n");

    for (i = 1; i < argc; i++) {
        
        file = fopen(argv[i], "rb");
        if (file == NULL) {
            printf("%s: 파일 열기 실패\n", argv[i]);
            continue; 
        }

        // 4바이트 파일만 처리하도록 하기 
        unsigned int bytes = fread(&temp, 1, sizeof(temp), file);
       
        if (bytes != sizeof(temp)) {
            printf("4바이트만 지원됩니다. %s 파일을 건너뜁니다. \n", argv[i]);
            fclose(file);
            continue;
        }
        

        // 역방향(리틀 엔디언) -> 네트워크 바이트 오더 (정방향) 으로 바꾸는 함수 
        temp = ntohl(temp);

   //     printf("%s: %u (0x%08x)\n", argv[i], temp, temp);

        printf("%u(0x%08x)", temp, temp);

        if(i+1 < argc){
            printf(" + ");
        }



        // 정수 덧셈에서 발생하는 overflow는 무시 ! 
        // 4바이트에서 0xff ff ff ff 은 32비트 상에서 최대 값인 4294967295인데 이 수에 +1
        //을 하게되면 순환 형식으로 0으로 되어서 마치 -1 연산하는것 처럼 보이게 되네요 
         
        sum += temp;

        fclose(file);
    }

    
    printf(" = %u(0x%08x)\n", sum, sum);

    return 0;
}

