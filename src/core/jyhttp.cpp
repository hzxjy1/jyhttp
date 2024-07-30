#include <iostream>
#include <jyhttp.hpp>

import JySockets;

static inline JySockets::Socket* ConvertToJysocket(void* socket_ptr) {
  return static_cast<JySockets::Socket*>(socket_ptr);
}

Jyhttp::Jyhttp() {
  auto ret = JySockets::GetSocket();
  if (ret.has_value()) {
    socket_ptr = ret.value();
  } else {
    std::terminate();  // Error
  }
  std::cout << "Jyhttp" << std::endl;
}

Jyhttp::Jyhttp(const Jyhttp& obj) {
  auto ret = JySockets::GetSocket();
  if (ret.has_value()) {
    socket_ptr = ret.value();
  } else {
    std::terminate();  // Error
  }
  // TODO: Copy values of obj
};

Jyhttp::~Jyhttp() {
  delete socket_ptr;
  std::cout << "Bye,jyhttp" << std::endl;
}

void Jyhttp::Listen(const int& port) {
  std::cout << "Listen: " << port << std::endl;
}

Jyhttp& Jyhttp::Get(const std::string& path,
                    void (*handler)(const request& req, response& res)) {
  socket_ptr->CreateSocket();
  std::cout << "Get" << std::endl;
  return *this;
}