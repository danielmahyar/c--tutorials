#include <iostream>
#include <string>
#include <vector>
#include "Movies.hpp"
using namespace std;


void addMovie(Movies&, string, string, unsigned int);
void incrementWatchCount(Movies&, string);


int main(){

	Movies movies;

	movies.displayMovies();

	addMovie(movies, "THE BEST ACTION FILM EVER", "GP-13", 1);
	
	movies.displayMovies();

	incrementWatchCount(movies, "THE BEST ACTION FILM EVER");

	addMovie(movies, "Fast and furios 2", "R", 100'000'000);

	movies.displayMovies();

	return 0;
}

void addMovie(Movies &movies, string name, string rating, unsigned int watchCount){
	if(movies.addMovie(name, rating, watchCount))
		cout << "Film added" << endl;
	else
		cout << "Invalid information given" << endl;
}

void incrementWatchCount(Movies &movies, string movieName){
	if(movies.incrementWatchCount(movieName))
		movies.displayMovies();
	else
		cout << "The movie does not exist" << endl;
}