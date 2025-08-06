# Makefile for sort project
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# 编译所有文件
quick_sort: 
	$(CC) $(CFLAGS) ./quick_sort/quick_sort.c ./utils.c ./quick_sort/quick_sort_test.c -o quick_sort_test

# 运行测试
quick_sort_test: quick_sort
	./quick_sort_test

# 默认目标
all: quick_sort

# 测试目标
test: quick_sort_test

# 清理编译文件
clean:
	rm -f quick_sort_test
