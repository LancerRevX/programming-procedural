build:
	gcc main.c matrix.c container.c square_matrix.c diagonal_matrix.c lower_triangular_matrix.c -oapp.exe

build-debug:
	gcc -g main.c matrix.c container.c square_matrix.c diagonal_matrix.c lower_triangular_matrix.c -oapp.exe