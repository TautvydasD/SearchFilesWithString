# TeltonikaTask
To test this project run command:

```console
make # compiles the main.c with dynlib.c and then runs ./main.o -f . -t printf
```

To test the project with diffrent variables, do the following:

```console
make

./main.o -f folder -t text
```

Other commands:

```console
make dynamic # to make dynamic library (*.so)

make rundyn # try to run dynamic library (Is broken because ldd is not found).

make exporting # exports library path
```
