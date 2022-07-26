BINDEST = /usr/local/bin
MANDEST = /usr/local/man

TARGET = ssg

SRCS  = $(shell find ./src     -type f -name *.cpp)
HEADS = $(shell find ./include -type f -name *.h)
OBJS = $(SRCS:.cpp=.o)
DEPS = Makefile.depend

INCLUDES = -I./include
CXXFLAGS = -O2 -Wall $(INCLUDES)
LDFLAGS = -lm


all: $(TARGET)

$(TARGET): $(OBJS) $(HEADS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

run: all
	@./$(TARGET)

.PHONY: depend clean install uninstall
depend:
	$(CXX) $(INCLUDES) -MM $(SRCS) > $(DEPS)
	@sed -i -E "s/^(.+?).o: ([^ ]+?)\1/\2\1.o: \2\1/g" $(DEPS)

clean:
	$(RM) $(OBJS) $(TARGET)

install:
	@install $(TARGET) $(BINDEST)
	@mkdir -p $(MANDEST)/man1
	@install --mode=644 docs/ssg.1 $(MANDEST)/man1/ssg.1

uninstall:
	@rm $(BINDEST)/$(TARGET)
	@rm $(MANDEST)/man1/ssg.1

-include $(DEPS)