#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "Movie.hpp"
#include <vector>
using namespace std;

class Movies{
	private:
		vector<Movie> *movies;
	public:
		Movies();
		~Movies();
		bool addMovie(string movieName, string rating, unsigned int watchCount);
		bool addMovie(const Movie &movie);
		bool incrementWatchCount(const string movieName);
		void displayMovies();
};

#endif