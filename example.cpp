#include <jyhttp.hpp>
#include <iostream>

response foo(const request &req) {
  std::cout << req.id << std::endl;
  response res = response();
  return res;
}

int main() {
  Jyhttp jyhttp;
  jyhttp.Get("/", foo);
  jyhttp.Listen(8080);
  return 0;
}