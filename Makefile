all:
	i686-w64-mingw32-gcc udppayloadresponser.c -o udppayloadresponser32.exe -Wall -Wextra -Wno-unused-but-set-variable -Wno-unused-variable --std=c99 -lws2_32
	c99 udppayloadresponser.c -o udppayloadresponser -Wall -Wextra -Wno-unused-but-set-variable -Wno-unused-variable
clean:
	rm -f udppayloadresponser udppayloadresponser32.exe
