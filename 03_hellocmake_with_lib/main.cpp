#include "answer/answer.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  const auto url = "https://api.wolframalpha.com/v1/"
                   "result?appid=YAPKJY-8XT9VEYPX9&i=what+is+ultimate+answer";
  std::string expected_answer = answer::find_the_ultimate_answer(url);

  for (;;) {
    std::cout << "What is the ultimate answer?" << std::endl;
    int answer;
    std::cin >> answer;

    if (std::to_string(answer) == expected_answer) {
      std::cout << "Correct!" << std::endl;
      break;
    }
  }
  return 0;
}
