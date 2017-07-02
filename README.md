# Wanna POSIX-compatiable sockets under Windows?
# Fuck you then!

Windows doesn't care about standards - M$ lives in their own magic world with rainbows and ponies. Therefore, you will feel PAIN in your ass if you even try to develop native programs unsing C and berkeley sockets.

The purpose if this template is to decrease amount of pain during googling compatiable socket-oriented windowsshit. It contains:

1) Program with some compatibility macros collection
2) Makefile, which allows you to generate executables for both platforms immediatly, but only if you are executing "make" command under modern non-windows systems and only with gcc

The actual program activity is responding to any udp packet with two packets. It was created for my own personal tests and I don't really care about it anymore.

Have a freaking fun.
