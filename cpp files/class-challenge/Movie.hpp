#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>
using namespace std;

class Movie{
	private:
		string movieName;
		string rating;
		unsigned int watchedCount;
	public:
		Movie(string name, string rating, unsigned int ratingwatchedCount);
		Movie(const Movie &movie);
		Movie(Movie &&movie);
		string getName() const { return movieName; };
		string getRating() const { return rating; };
		unsigned int getWatchedCount() const { return watchedCount; };

		void incrementWatchedCount();
};

#endif