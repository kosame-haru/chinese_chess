CXX = g++
CLIFLAGS = -std=c++20 -Wall -Wextra -O2 -static

TARGET_CLI = cchess_cli.exe
SOURCE_CLI = cli/console.cpp cli/main.cpp cli/statusline.cpp cli/version.cpp cli/command.cpp

cli: $(SOURCE_CLI)
	$(CXX) $(CLIFLAGS) $(SOURCE_CLI) -o $(TARGET_CLI)

clean:
	del $(TARGET_CLI)

default:
	make cli
