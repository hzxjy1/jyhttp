#include <iostream>
#include <jyhttp.hpp>

void foo(const request& req, response& res) {
  std::cout << req.id << std::endl;
}

int main() {
  Jyhttp jyhttp;
  jyhttp.Get("/", foo);
  jyhttp.Listen(8080);
  return 0;
}