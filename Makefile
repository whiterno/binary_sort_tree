Headers := include/binary_sort_tree.h include/bin_sort_tree_dump.h
Objects := obj/binary_sort_tree.o obj/bin_sort_tree_dump.o obj/main.o

binary_sort_tree.out: ${Objects} ${Headers}
	g++ ${Objects} -o binary_sort_tree.out

obj/binary_sort_tree.o: src/binary_sort_tree.cpp ${Headers}
	g++ -c src/binary_sort_tree.cpp -o obj/binary_sort_tree.o

obj/bin_sort_tree_dump.o: src/bin_sort_tree_dump.cpp ${Headers}
	g++ -c src/bin_sort_tree_dump.cpp -o obj/bin_sort_tree_dump.o

obj/main.o: src/main.cpp ${Headers}
	g++ -c src/main.cpp -o obj/main.o

run:
	./binary_sort_tree.out

target:
	mkdir log
	touch log/dump.dot
	touch log/dump.html

clean:
	rm -r log
	rm binary_sort_tree.out
