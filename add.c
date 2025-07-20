#include "add.h"
#include <stdint.h> 
#include <stdio.h>

#include <arpa/inet.h>  // ntohl() 함수 로드 

uint32_t add(int argc, char *argv[])
{   
     uint32_t temp;   // 부호 없는 32비트 정수
    uint32_t sum = 0;  
    int i;
    FILE* file;

    int skip_flag=0;
    

     for (i = 1; i < argc; i++) {
        
        file = fopen(argv[i], "rb");
        if (file == NULL) {
            printf("%s: 파일 열기 실패\n", argv[i]);
            continue; 
        }

        // 4바이트 파일만 처리하도록 하기 
        unsigned int bytes = fread(&temp, 1, sizeof(temp), file);
       
        if (bytes != sizeof(temp)) {
            
            fclose(file);
            if (argc==2){
                printf("4바이트만 지원됩니다. %s 파일을 확인해주세요 \n", argv[i]);
                return 0; 
            }
            
            else {
           //     printf("4바이트만 지원됩니다. %s 파일은 \n", argv[i]);
                skip_flag=1;
                continue;
            }
           
        }
       


         
                
        // 역방향(리틀 엔디언) -> 네트워크 바이트 오더 (정방향) 으로 바꾸는 함수 
 //       printf("before: 0x%08x\n",temp);
        temp = ntohl(temp);
  //      printf("after: 0x%08x\n",temp);

        

   //     printf("%s: %u (0x%08x)\n", argv[i], temp, temp);
        
        
         if(!skip_flag){

            if(i!=1&&i+1 < argc){
            printf(" + ");
        }
            
        }
        
        printf("%u(0x%08x)", temp, temp);

        



        // 정수 덧셈에서 발생하는 overflow는 무시 ! 
        // 4바이트에서 0xff ff ff ff 은 32비트 상에서 최대 값인 4294967295인데 이 수에 +1
        //을 하게되면 순환 형식으로 0으로 되어서 마치 -1 연산하는것 처럼 보이게 되네요 
         
        sum += temp;

        fclose(file);


 }
        

   

    return sum ;

}


