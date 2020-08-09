.PHONY: binarySearch bubbleSort algorithm clean

binarySearch:
	cd binarySearch && mkdir -p build && cd build && cmake .. && make -j && ./binarySearchTests

bubbleSort:
	cd bubbleSort && mkdir -p build && cd build && cmake .. && make -j && ./areEqual-ut && ./bubbleSort-ut

algorithm:
	mkdir -p _build && cd _build && cmake .. && make -j && ctest

default: algorithm

clean:
	rm -rf ./_gtest
	rm -rf ./_build
	rm -rf ./googletest/build
	rm -rf ./binarySearch/build
	rm -rf ./bubbleSort/build
