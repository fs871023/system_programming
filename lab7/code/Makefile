TARGET=a.out

$(TARGET): lab5_stu.o
	gcc $^ -o $@
lab5_stu.o : lab5_stu.c apue.h
	gcc $^ -o $@

clean:
	rm -f *.o *.out
