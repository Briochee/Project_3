#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

int main()
{
  // PARAMETERS TO MODIFY - BE CAREFUL NOT TO OVERWRITE YOUR FILES.

  int observations = 10000000; // number of random ints to be generated
  std::string filename = "name_that_no_important_file_has.txt"; // name of file to create
  std::string header = "A bunch of integers"; // header for output file
  int min = 5000; // minimum value
  double alpha = 3; // shape parameter. Must be >=1. Lower value clusters numbers closer to the min.
  double beta = 100; // scale parameter. Must be >0. Higher values increase range of generated values.

  // YOU SHOULD NOT NEED TO MODIFY BELOW HERE

  std::ofstream fout("test_input_10M_2-500.txt");
  // seed RNG
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);
  // define gamma distribution
  std::gamma_distribution<double> distribution (alpha,beta);

  // randomly sample gamma distribution and write to file
  fout << header << std::endl;
  for (int i=0; i<observations; ++i)
    fout << int(distribution(generator)+min) << " ";
  fout << std::endl;

  return 0;
}