CC=gcc
OUTPUT_DIR=build
SRC_DIR=src
TARGET=$(OUTPUT_DIR)/math.a
COMPILE=$(CC) -c -o $@ $^

all:postbuild

postbuild:build
	rm $(OUTPUT_DIR)/*.o

build:prebuild
	@$(MAKE) $(TARGET)

prebuild:clean
	mkdir $(OUTPUT_DIR)

$(TARGET):$(OUTPUT_DIR)/Vector.o $(OUTPUT_DIR)/Circle.o $(OUTPUT_DIR)/Rectangle.o
	ar rcs $@ $^

$(OUTPUT_DIR)/Vector.o:$(SRC_DIR)/Vector.cpp
	$(COMPILE)

$(OUTPUT_DIR)/Circle.o:$(SRC_DIR)/Circle.cpp
	$(COMPILE)

$(OUTPUT_DIR)/Rectangle.o:$(SRC_DIR)/Rectangle.cpp
	$(COMPILE)

clean:
	rm -rf $(OUTPUT_DIR)
