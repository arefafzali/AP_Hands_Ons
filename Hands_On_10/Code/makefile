COMPILER = g++
COMPILER_FLAGS = --std=c++11
a.out: hands-on-10.o CourseClass.o StudentClass.o
	${COMPILER} ${COMPILER_FLAGS} hands-on-10.o CourseClass.o StudentClass.o

hands-on-10.o: hands-on-10.cpp CourseClass.h StudentClass.h
	${COMPILER} ${COMPILER_FLAGS} -c hands-on-10.cpp

CourseClass.o: CourseClass.cpp CourseClass.h
	${COMPILER} ${COMPILER_FLAGS} -c CourseClass.cpp

StudentClass.o: StudentClass.cpp StudentClass.h
	${COMPILER} ${COMPILER_FLAGS} -c StudentClass.cpp

clean:
	rm *.o
	rm a.out
