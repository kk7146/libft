
# libft
C 표준 라이브러리의 주요 함수를 직접 구현

## 주요 기능
문자열 처리 함수 구현: strlen, strdup, strjoin, strncmp, strchr 등
메모리 관리 함수 구현: memset, memcpy, calloc, bzero 등
문자 판별 함수 구현: isdigit, isalpha, toupper, tolower 등
입출력 함수 구현: putchar_fd, putstr_fd, putendl_fd, putnbr_fd 등
연결 리스트 (Linked List) 모듈 구현:
t_list 구조체 정의
lstnew, lstadd_front, lstadd_back, lstmap, lstdelone, lstclear 등

## 빌드 및 사용법
# 라이브러리 빌드
make

# 생성된 정적 라이브러리
libft.a

# 사용 예시
gcc main.c libft.a -o program
