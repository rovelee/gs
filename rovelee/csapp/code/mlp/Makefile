

# 使用 “-S” 生成汇编文件 mstore.s
smstore: mstore.c
	gcc -Og -S mstore.c
# 使用 “-c” 命令行选项，编译并汇编代码生成目标代码文件 mstore.o 
cmstore: mstore.c
	gcc -Og -c mstore.c
# 使用反汇编器查看二进制目标代码文件的汇编格式，
# 在Linux系统中，带‘d'命令行标志的程序 objdump 可以反汇编
dmstore: mstore.o
	objdump -d mstore.o

clean:
	rm -f *.o *.s