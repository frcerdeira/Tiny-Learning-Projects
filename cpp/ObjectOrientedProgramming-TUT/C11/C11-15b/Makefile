##
# C11-15-b
#
# @file
# @version 0.1

output: main.o Point3d.o Vector3d.o
	g++ main.o Point3d.o Vector3d.o -o output
main.o: main.cpp
	g++ -c main.cpp
Point3d.o: Point3d.cpp Point3d.h
	g++ -c Point3d.cpp
Vector3d.o: Vector3d.cpp Vector3d.h
	g++ -c Vector3d.cpp
clean:
	rm *.o output

# end
