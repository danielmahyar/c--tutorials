#include <iostream>
#include "Movies.hpp"
using namespace std;

bool movieExists(const string, const vector<Movie>*);

Movies::Movies(): movies{new vector<Movie>}{
	cout << movies << endl;
}

Movies::~Movies(){
	delete movies;
}

bool Movies::addMovie(string name, string rating, unsigned int watchedCount){
	if(movieExists(name, movies)) return false;

	Movie movie {name, rating, watchedCount};
	(*movies).push_back(movie);

	return true;

}

bool Movies::addMovie(const Movie &movie){
	if(movieExists(movie.getName(), movies)) return false;

	(*movies).push_back(movie);
	return true;
}

bool Movies::incrementWatchCount(const string movieName){
	for(Movie &movie : (*movies))
		if(movie.getName() == movieName){
			cout << "Incrementing: " << movie.getName() << endl;
			movie.incrementWatchedCount();
			return true;
		}

	return false;
}

void Movies::displayMovies(){
	cout << "\n=====================" << endl << endl;	
	cout << "Current films here: " << endl;
	if((*movies).size() > 0)
		for (Movie movie : *movies)
			cout << "- " << movie.getName() << " " << movie.getRating() << " " << movie.getWatchedCount() << endl;
	else 
		cout << "No movies to display" << endl;
	
	cout << "\n=====================" << endl << endl;	
}

/**
 * @brief 
 * Checks if movie name exists in movie vector
 * @param name Name of new movie
 * @param movies Movies vector from Movies object
 * @return true if name exists else false
 */
bool movieExists(string name, const vector<Movie> *movies){
	for (Movie movie : *movies)
		if (movie.getName() == name)
			return true;
	return false;
}