CC=g++
CFLAGS = -std=c++2a -g -Wall `pkg-config --libs --cflags opencv4`
TARGET = img_loader

all : $(TARGET)

$(TARGET):.$(TARGET).o
	$(CC) $(CFLAGS) $^ -o $@
.$(TARGET).o : $(TARGET).cc
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	rm -f $(TARGET) *.o *.gch .*.o .*.gch