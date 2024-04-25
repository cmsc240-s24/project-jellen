all: MovieStoreAPI static-analysis run-unit-tests 

MovieStoreAPI: MovieStoreAPI.o Actor.o Cart.o Director.o Genre.o JellenReview.o Movie.o Personnel.o GenericAPI.o 
	g++ -lpthread MovieStoreAPI.o Actor.o Cart.o Director.o Genre.o JellenReview.o Personnel.o GenericAPI.o -o MovieStoreAPI

MovieStoreAPI.o: MovieStoreAPI.cpp Actor.h Cart.h Director.h Genre.h JellenReview.h Movie.h Personnel.h GenericAPI.h persistence.h
	g++ -Wall -c MovieStoreAPI.cpp 

Cart.o: Cart.cpp Cart.h
	g++ -Wall -c Cart.cpp 

Genre.o: Genre.cpp Genre.h
	g++ -Wall -c Genre.cpp 

JellenReview.o: JellenReview.cpp JellenReview.h
	g++ -Wall -c JellenReview.cpp 

Movie.o: Movie.cpp Movie.h Genre.h JellenReview.h Personnel.h
	g++ -Wall -c Movie.cpp 

Personnel.o: Personnel.cpp Personnel.h
	g++ -Wall -c Personnel.cpp

Actor.o: Actor.cpp Actor.h Personnel.h
	g++ -Wall -c Actor.cpp

Director.o: Director.cpp Director.h Personnel.h
	g++ -Wall -c Director.cpp

GenericAPI.o: GenericAPI.cpp GenericAPI.h Actor.h Cart.h Director.h Genre.h JellenReview.h Movie.h Personnel.h
	g++ -Wall -c GenericAPI.cpp 

GenericAPITest: GenericAPITest.cpp GenericAPI.o Actor.o Cart.o Director.o Genre.o JellenReview.o Movie.o Personnel.o
	g++ -lpthread GenericAPITest.cpp GenericAPI.o Actor.o Cart.o Director.o Genre.o JellenReview.o Movie.o Personnel.o -o GenericAPITest

persistenceTest: persistenceTest.cpp persistence.h Genre.o
	g++ -lpthread persistenceTest.cpp Genre.o -o persistenceTest

GenreTest: GenreTest.cpp Genre.cpp Genre.h Genre.o
	g++ -lpthread GenreTest.cpp Genre.o -o GenreTest

run-unit-tests: GenericAPITest persistenceTest
	./GenericAPITest    ;\
	./persistenceTest	;\
	./GenreTest

static-analysis:
	cppcheck *.cpp

clean:
	rm -f *.o MovieStoreAPI