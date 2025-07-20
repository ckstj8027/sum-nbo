# Makefile

# 모든 것을 빌드
all: sum-nbo

# 실행 파일 생성
sum-nbo: main.o
	gcc -o sum-nbo main.o

# 오브젝트 파일 생성
main.o: main.c
	gcc -c -o main.o main.c

# clean 하기
clean:
	rm -f sum-nbo main.o
