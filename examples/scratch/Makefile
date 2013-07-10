TARGET:= main
DIR:=../../framework/
MATDIR:=../../../mat
SRC:=main.cpp
CXX:=g++
CXXFLAGS :=-Wall -std=c++11 -g
LDFLAGS := -lframework -lpthread -lGL -lGLEW -lsfml-system -lsfml-window
default: $(TARGET)
	
lib:
	make -j9 -C $(DIR) 
$(TARGET): $(SRC) lib
	g++ $(SRC) -I$(DIR) -I$(MATDIR) -L$(DIR) $(LDFLAGS) $(CXXFLAGS)  -o $(TARGET)
clean:
	rm $(TARGET)
	make clean -C $(DIR)
	
