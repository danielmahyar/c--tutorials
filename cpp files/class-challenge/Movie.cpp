#include "Movie.hpp"
#include <string>
#include <iostream>
using namespace std;

Movie::Movie(string name = "None", string rating = "G", unsigned int watchedCount = 0)
	: movieName {name}, rating {rating}, watchedCount {watchedCount} { cout << "Construction" << endl; }

Movie::Movie(const Movie &movie) 
	: Movie(movie.getName(), movie.getRating(), movie.getWatchedCount()){ cout << "Copy constructor" << endl; }

Movie::Movie(Movie &&movie)
	: Movie(movie.getName(), movie.getRating(), movie.getWatchedCount()){ cout << "Move constructor" << endl; }

void Movie::incrementWatchedCount() {
	watchedCount += 1;
}