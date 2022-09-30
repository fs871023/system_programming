TARGET=shell

$(TARGET): lab1.o error.o
	$(CC) -o $@ $^ 

lab1.o: lab1.c
error.o: error.c

clean:
	rm -f lab1.o error.o $(TARGET)
