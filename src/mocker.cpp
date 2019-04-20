#include "mocker.h"

int Mocker::generateRandomInt (int min) {
  std::uniform_int_distribution <std::mt19937::result_type> distribution(min, MAX);
  return distribution(rng);
}

char Mocker::generateRandomChar () {
  int increment = generateRandomInt() % 26;
  return 'a' + increment;
}

float Mocker::generateRandomFloat () {
  std::uniform_int_distribution <std::mt19937::result_type> distribution(MIN, MAX);
  return distribution(rng);
}
