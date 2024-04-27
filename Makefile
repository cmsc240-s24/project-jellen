all: MovieStoreAPI #static-analysis run-unit-tests 

MovieStoreAPI: MovieStoreAPI.o Actor.o Director.o Genre.o JellenReview.o Personnel.o GenericAPI.o Movie.o
	g++ -lpthread MovieStoreAPI.o Actor.o Director.o Genre.o JellenReview.o Personnel.o GenericAPI.o Movie.o -o MovieStoreAPI

MovieStoreAPI.o: MovieStoreAPI.cpp Actor.h Director.h Genre.h JellenReview.h Movie.h Personnel.h GenericAPI.h persistence.h
	g++ -Wall -c MovieStoreAPI.cpp 

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

GenericAPI.o: GenericAPI.cpp GenericAPI.h Actor.h Director.h Genre.h JellenReview.h Personnel.h Movie.h
	g++ -Wall -c GenericAPI.cpp 

GenericAPITest: GenericAPITest.cpp GenericAPI.o Actor.o Director.o Genre.o JellenReview.o Personnel.o Movie.o
	g++ -lpthread GenericAPITest.cpp GenericAPI.o Actor.o Director.o Genre.o JellenReview.o Personnel.o Movie.o -o GenericAPITest

persistenceTest: persistenceTest.cpp persistence.h Genre.o
	g++ -lpthread persistenceTest.cpp Genre.o -o persistenceTest

GenreTest: GenreTest.cpp Genre.cpp Genre.h Genre.o
	g++ -lpthread GenreTest.cpp Genre.o -o GenreTest

DirectorTest: DirectorTest.cpp Director.cpp Director.h Personnel.o
	g++ -lpthread DirectorTest.cpp Director.o Personnel.o -o DirectorTest 	

ActorTest: ActorTest.cpp Actor.cpp Actor.h Personnel.o
	g++ -lpthread ActorTest.cpp Actor.o Personnel.o -o ActorTest

JellenReviewTest: JellenReviewTest.cpp JellenReview.cpp JellenReview.h
	g++ -lpthread JellenReviewTest.cpp JellenReview.o -o JellenReviewTest 

PersonnelTest: PersonnelTest.cpp Personnel.cpp Personnel.h
	g++ -lpthread PersonnelTest.cpp Personnel.o -o PersonnelTest 

MovieTest: MovieTest.cpp Movie.o Genre.o Personnel.o JellenReview.o Actor.o Director.o
	g++ -lpthread MovieTest.cpp Movie.o Genre.o Personnel.o JellenReview.o Actor.o Director.o -o MovieTest

run-unit-tests: GenericAPITest persistenceTest GenreTest DirectorTest ActorTest JellenReviewTest PersonnelTest
	./GenericAPITest    ;\
	./persistenceTest	;\
	./GenreTest			;\
	./DirectorTest		;\
	./ActorTest			:\
	./JellenReviewTest  ;\
	./PersonnelTest		;\
	

#static-analysis:
#	cppcheck *.cpp

clean:
	rm -f *.o MovieStoreAPI GenericAPITest persistenceTest GenreTest DirectorTest JellenReviewTest PersonnelTest
