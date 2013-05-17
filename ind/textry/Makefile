TARGET:= main
DIR:=../../framework/
SRC:=mygl.cpp
CXX:=g++
CXXFLAGS :=-Wall -std=c++11 -g
LDFLAGS := -lframework -lpthread -lGL -lGLEW -lsfml-system -lsfml-window -lSOIL
default: $(TARGET)
	
lib:
	make -j9 -C $(DIR) 
$(TARGET): $(SRC) lib
	g++ $(SRC) -I$(DIR) -L$(DIR) $(LDFLAGS) $(CXXFLAGS) -o $(TARGET)
clean:
	make clean -C $(DIR)
	rm $(TARGET)