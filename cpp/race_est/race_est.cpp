//github.com/ThatSmittyDude
//Race Estimator
//Estimate how many laps a race should be based on a set time
#include <iostream>

int main(){
	double lap_time;
	int race_time;
	char cautions;

	std::cout << "***Run a few test laps. Note your lap times***\n";
	std::cout << "What is an average lap time in seconds?: ";
	std::cin >> lap_time;
	std::cout << "How long would you like the race to be in minutes?: "; 
	std::cin >> race_time;
	std::cout << "Will there be cautions? y/n: ";
	std::cin >> cautions;

	if(cautions == 'y' || cautions == 'Y'){
		int race_laps, race_seconds;
		race_seconds = race_time * 60;
		race_laps = (race_seconds / lap_time) * 0.33;
		std::cout << "Your recommended lap count: " << race_laps << std::endl;
		return 0;
	}else{
		int race_seconds, race_laps;
		race_seconds = race_time * 60;
		race_laps = (race_seconds / lap_time) * 0.8;
		std::cout << "Your recommended lap count: " << race_laps << std::endl;
		return 0;
		}
}
