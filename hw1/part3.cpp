#include <fstream>
#include <iostream>
using namespace std;

class Movie {
public:

/*For the class Movie, I decided not to include any setter functions for the values of
name, rating, or earnings after they had been implemented. There is really no need to edit
these values. If there are duplicate movies, mergedmovie will create a new movie. Earnings should
only be increased if more people watch the movies, which the movieshowing function takes care of.
Therefore, only getter functions were included along with the constructors to protect the
validity of the values.
*/

  Movie(){
    movieName = "N/A";
    movieRating = "N/A";
    movieEarnings = 0.00;
  }

  Movie(string name, string rating, float earnings){
    movieName = name;
    movieRating = rating;
    movieEarnings = earnings;
  }

  float getEarnings(){
    return movieEarnings;
  }

  string getName(){
    return movieName;
  }

  string getRating(){
    return movieRating;
  }

  void MovieShowing(int n){
    double ticketPrice = 12.00;
    float totalEarnings = ticketPrice * n;
    movieEarnings = movieEarnings + totalEarnings;
  }

  Movie MergeMovie(Movie m){
    string mergedName, mergedRating;
    float mergedEarnings;

/*The following if statement first determines whether or not the two movies
have the same name. Then, it ensures that the most aggressive movie rating is chosen
for the mergedMovie. Afterwards, it calculates the totalearnings. Finally,
it creates mergedmovie with the parameters given.
*/

    if (movieName == m.getName()){
      mergedName = movieName;

      if (movieRating == "G" || m.getRating() == "G"){
        mergedRating = "G";
      }
      else if (movieRating == "PG" || m.getRating() == "PG"){
        mergedRating = "PG";
      }
      else if (movieRating == "PG-13" || m.getRating() == "PG-13"){
        mergedRating = "PG-13";
      }
      else {
        mergedRating = "R";
      }

      mergedEarnings = m.getEarnings()+movieEarnings;
    }

    else{
      mergedName = "Could not combine. ";
      mergedRating = "N/A";
      mergedEarnings = 0.00;
    }
    Movie mergedMovie(mergedName, mergedRating, mergedEarnings);
    return mergedMovie;
  }

private:
  string movieName;
  string movieRating;
  float movieEarnings;
};

int main() {
  Movie test1("Avengers", "PG-13", 10000);
  Movie test2("Star Wars", "R", 50000);
  Movie test3("Avengers", "G", 30000);
  Movie test4;

  Movie test5 = test1.MergeMovie(test3);
  Movie test6 = test2.MergeMovie(test4);

  test1.MovieShowing(50);

  cout<<"Test 1: "<<test1.getName()<<", "<<test1.getRating()<<", "<<test1.getEarnings()<<endl;
  cout<<"Test 2: "<<test2.getName()<<", "<<test2.getRating()<<", "<<test2.getEarnings()<<endl;
  cout<<"Test 3: "<<test3.getName()<<", "<<test3.getRating()<<", "<<test3.getEarnings()<<endl;
  cout<<"Test 4: "<<test4.getName()<<", "<<test4.getRating()<<", "<<test4.getEarnings()<<endl;
  cout<<"Test 5: "<<test5.getName()<<", "<<test5.getRating()<<", "<<test5.getEarnings()<<endl;
  cout<<"Test 6: "<<test6.getName()<<", "<<test6.getRating()<<", "<<test6.getEarnings()<<endl;


}
