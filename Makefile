Headers := include/binary_sort_tree.h
Objects := obj/binary_sort_tree.o obj/main.o

binary_sort_tree.out: ${Objects} ${Headers}
	g++ ${Objects} -o binary_sort_tree.out

obj/binary_sort_tree.o: src/binary_sort_tree.cpp ${Headers}
	g++ -c src/binary_sort_tree.cpp -o obj/binary_sort_tree.o

obj/main.o: src/main.cpp ${Headers}
	g++ -c src/main.cpp -o obj/main.o

run:
	./binary_sort_tree.out
