all: clock lru_aging lru_counter lru_stack

clock: clock.cpp
	g++ -std=c++14 clock.cpp -o clock

lru_aging: lru_aging.cpp
	g++ -std=c++14 lru_aging.cpp -o lru_aging

lru_counter: lru_counter.cpp
	g++ -std=c++14 lru_counter.cpp -o lru_counter

lru_stack: lru_stack.cpp
	g++ -std=c++14 lru_stack.cpp -o lru_stack

clean:
	rm lru_aging lru_counter lru_stack clock