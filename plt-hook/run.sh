gcc -fPIC -shared -o libhaha.so haha.c
gcc -fPIC -shared -o libhello.so hello.c -lhaha -L.
