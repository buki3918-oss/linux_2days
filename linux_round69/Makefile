CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = student_report_cli

all: $(TARGET)

$(TARGET): student_report_cli.c
	$(CC) $(CFLAGS) student_report_cli.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET) students.txt report.txt

clean:
	rm -f $(TARGET) report.txt
