OPCIONS = -D_JUDGE_ -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Usuarios.o Usuario.o Cursos.o Curso.o Sesiones.o Sesion.o Problemas.o Cjt_identificadores.o
	g++ -o program.exe program.o Usuarios.o Usuario.o Cursos.o Curso.o Sesiones.o Sesion.o Problemas.o Cjt_identificadores.o $(OPCIONS)

program.o: program.cc Usuarios.hh Cursos.hh
	g++ -c program.cc  $(OPCIONS)

Cursos.o: Cursos.hh Curso.hh
	g++ -c Cursos.cc  $(OPCIONS)

Curso.o: Curso.cc
	g++ -c Curso.cc  $(OPCIONS)

Sesiones.o: Sesiones.cc Sesion.hh
	g++ -c Sesiones.cc  $(OPCIONS)

Sesion.o: Sesion.cc BinTree.hh
	g++ -c Sesion.cc  $(OPCIONS)

Usuarios.o: Usuarios.cc Usuario.hh
	g++ -c Usuarios.cc  $(OPCIONS)

Usuario.o: Usuario.cc
	g++ -c Usuario.cc  $(OPCIONS)

Problemas.o: Problemas.cc
	g++ -c Problemas.cc  $(OPCIONS)

Cjt_identificadores.o: Cjt_identificadores.cc
	g++ -c Cjt_identificadores.cc $(OPCIONS)

doxygen:
	doxygen Doxyfile

tar:
	tar -cvf practica.tar program.cc Usuarios.cc Usuario.cc Cursos.cc Curso.cc Sesion.cc Sesiones.cc Problemas.cc Usuarios.hh Usuario.hh Cursos.hh Curso.hh Sesion.hh Sesiones.hh Problemas.hh Cjt_identificadores.hh Cjt_identificadores.cc html.zip Makefile
clean:
	rm -f *.o
	rm -f program.exe

