# Setting Compile
CC = g++
CFLAGS = -Wall -g 

# service name define
TARGET = program-service

# sorce file list all
SRCS = $(wildcard *.cpp)

# save object file root (save in "/obj")
OBJDIR = obj

# Build OBJ file
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

# clean OBJ and TARGET
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean