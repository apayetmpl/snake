TARGET=snake.exe
CPP_FILES=main.cpp commandLineView.cpp snakeView.cpp snakeModel.cpp snakeController.cpp
OBJECTS=$(CPP_FILES:%.cpp=%.o)
build:$(TARGET)
$(TARGET): $(OBJECTS)
		g++ -o $(TARGET) $(OBJECTS) -lncurses
%.o: %.cpp
		g++ -I . -c $?
clean:
		rm $(OBJECTS) $(TARGET)
