

example_factory: example_factory.cc
	g++ -std=c++11 example_factory.cc -o example_factory

example_register_in_creator: example_register_in_creator.cc
	g++ -std=c++11 example_register_in_creator.cc -o example_register_in_creator

example_non_standard: example_non_standard.cc
	g++ -std=c++11 example_non_standard.cc -o example_non_standard

main: base.cc child1.cc child2.cc child3.cc main.cc
	g++ -std=c++11 base.cc child1.cc child2.cc child3.cc main.cc -o main

clean:
	rm -f example_register_in_creator example_factory example_non_standard main
