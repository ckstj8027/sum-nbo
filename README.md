![Image](https://github.com/user-attachments/assets/071af9fd-096d-49d4-bee6-3988311f44cc)



case 1 : 파라미터 없을 경우 
./sum-nbo        

case 2 : 4 바이트 미만 파일 일경우 (1개 일경우 예외처리 )
./sum-nbo three-byte.bin 


 case 3 : 4 바이트 미만 파일 일경우 (파일이 2개 이상일 경우는 4바이트 미만 파일은 스킵)

./sum-nbo three-byte.bin thousand.bin
./sum-nbo thousand.bin three-byte.bin


case 4 : 그외 연산 
./sum-nbo thousand.bin two-hundred.bin 

./sum-nbo thousand.bin two-hundred.bin five-hundred.bin 


case 5 : 오버플로우는 무시된다 
./sum-nbo thousand.bin two-hundred.bin five-hundred.bin max.bin



