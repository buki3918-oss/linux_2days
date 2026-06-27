CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = student_report_app
OBJS = main.o student.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

run: $(TARGET)
	./$(TARGET) students.txt report.txt

clean:
	rm -f $(TARGET) $(OBJS) report.txt
