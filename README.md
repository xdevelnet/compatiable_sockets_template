# Wanna POSIX-compatiable sockets under Windows? Fuck you!

Windows doesnt care about standarts - M$ lives in ther own magic world with rainbows and ponies. Therefore, you will feel PAIN in your ass if you even try to develop native programs unsing C and berkeley sockets.

This template is created to decrease amount of pain during googling compatiable socket-oriented winshit. It contains:

1) Program with some compatibility macros collection
2) Makefile, which allows you to generate executables for both platforms immediatly, but only if you are executing "make" command under modern non-windows systems and only with gcc

Have a freaking fun.
