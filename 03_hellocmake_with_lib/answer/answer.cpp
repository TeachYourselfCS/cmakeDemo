#include "answer/answer.hpp"
#include <string>

#include <curl/curl.h>

namespace answer {
int find_the_ultimate_answer() { return 42; }

std::string find_the_ultimate_answer(const std::string &url) {
  const auto curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  const auto write_func = [](char *ptr, size_t size, size_t nmemb,
                             void *userdata) {
    auto &result = *static_cast<std::string *>(userdata);
    result.append(ptr, size * nmemb);
    return size * nmemb;
  };
  using WriteFunction = size_t (*)(char *, size_t, size_t, void *);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
                   static_cast<WriteFunction>(write_func));
  std::string result = "";
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
  curl_easy_perform(curl); // 暂时不考虑请求失败的情况
  curl_easy_cleanup(curl);
  return result;
}
} // namespace answer
