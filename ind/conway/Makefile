TARGET:= main
DIR:=../../framework/
SRC:=conway.cpp
CXX:=clang++
CXXFLAGS :=-Wall -std=c++11 -g
LDFLAGS := -lframework -lpthread -lGL -lGLEW -lsfml-system -lsfml-window
default: $(TARGET)
	
lib:
	make -j9 -C $(DIR) 
$(TARGET): $(SRC) lib
	$(CXX) $(SRC) -I$(DIR) -L$(DIR) $(LDFLAGS) $(CXXFLAGS) -o $(TARGET)
clean:
	rm $(TARGET)
	make clean -C $(DIR)
	