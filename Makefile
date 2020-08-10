.PHONY: algorithms clean binarySearch bubbleSort nwd

default: algorithms

algorithms:
	mkdir -p _build && cd _build && cmake .. && make -j && ctest

binarySearch:
	cd binarySearch && mkdir -p build && cd build && cmake .. && make -j && ./binarySearchTests

bubbleSort:
	cd bubbleSort && mkdir -p build && cd build && cmake .. && make -j && ./areEqual-ut && ./bubbleSort-ut

nwd:
	cd nwd && mkdir -p build && cd build && cmake .. && make -j && ./Nwd-ut

clean:
	rm -rf ./_gtest
	rm -rf ./_build
	rm -rf ./googletest/build
	rm -rf ./binarySearch/build
	rm -rf ./bubbleSort/build
	rm -rf ./nwd/build
