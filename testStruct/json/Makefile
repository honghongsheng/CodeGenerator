INCLUDE=-I../
TARGET=libjsoncpp.a
OBJS:=$(patsubst %.cpp,%.o,$(wildcard *.cpp))

all:$(TARGET)
	cp -f $(TARGET) ../../lib/ 

$(TARGET):${OBJS}
	$(AR) r $(TARGET) ${OBJS}

.cpp.o:
	$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf $(TARGET)
	rm -f $(OBJS)
	rm -f ../../lib/$(TARGET)
