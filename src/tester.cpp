#include <iostream>
#include "tester.h"
#include "color.h"

int passed = 0;
int failed = 0;

void check (bool condition, const std::string& msg) {
  if (condition) {
    passed++;
    std::cout << Color::green << Color::bold << "OK" << std::endl << Color::normal;
  } else {
    failed++;
    std::cout << Color::red << Color::bold << "!OK" << std::endl << Color::normal;
  }
}

void print (const std::string& msg) {
  const int WIDTH = 50;
  const std::string pad(WIDTH, '#');
  const int left = (WIDTH - int(msg.size())) / 2;
  const int right = WIDTH - int(msg.size()) - left;
  const std::string lspaces(left, ' ');
  const std::string rspaces(right, ' ');
  std::cout << Color::yellow << Color::bold;
  std::cout << pad << std::endl;
  std::cout << lspaces << msg << rspaces << '\n';
  std::cout << pad << std::endl;
  std::cout << Color::normal;
}

void Tester::execute() {
  print("RUNNING TESTS");
  Mocker mocker;

  for (int j = 0; j < NUMBER_OF_TESTS; ++j) {
    std::cout << Color::blue << Color::underline << "Running test " << j + 1 << std::endl << Color::normal;
    unsigned int size = mocker.generateRandomInt(10);
    List <Integer> integers;
    List <Float> floats;

    for (int i = 0; i < int(size); ++i) {
      integers.insert(2 * i + 1);
      floats.insert(20.f / (i + 1.f) + 2.f);
    }
    check(isSorted(integers), "The integers list has problems");
    check(isSorted(floats), "The floats list has problems");

    for (int i = 0; i < 5; ++i) {
      integers.remove(2 * i + 1);
      floats.remove(20.f / (i + 1.f) + 2.f);
    }

    int newSize = size - 5;
    check(integers.size() == newSize, "The size function has problems");
    check(floats.size() == newSize, "The size function has problems");
    check(isSorted(integers), "The integers list has problems");
    check(isSorted(floats), "The floats list has problems");
  }
  std::cout << Color::blue << Color::bold << Color::underline << "Results\n" << Color::normal;
  std::cout << Color::blue << Color::bold << "Passed " << passed << std::endl << Color::normal;
  std::cout << Color::blue << Color::bold << "Failed " << failed << std::endl << Color::normal;
  print("TESTS FINISHED" );
}

template <typename T>
bool Tester::isSorted(List<T> &list) {
  for (int i = 1; i < list.size(); ++i) {
    if ((std::is_same <T, Integer>::value) && list[i - 1] > list[i]) {
      return false;
    } else if ((std::is_same <T, Float>::value) && list[i - 1] < list[i]) {
      return false;
    }
  }
  return true;
}
