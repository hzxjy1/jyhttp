#include <iostream>
#include <jyhttp.hpp>

import Socket;

Jyhttp::Jyhttp() { std::cout << "jyhttp" << std::endl; }

Jyhttp::~Jyhttp() { std::cout << "bye,jyhttp" << std::endl; }

void Jyhttp::Listen(const int &port) {
  std::cout << "Listen: " << port << std::endl;
}

Jyhttp &Jyhttp::Get(const std::string &path,
                    std::function<response(const request &)> handler) {
  std::cout << "get" << std::endl;
  request req{"aaa"};
  handler(req);
  return *this;
}