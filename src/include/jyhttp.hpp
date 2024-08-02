#ifndef JYHTTP_HPP
#define JYHTTP_HPP
#define SOCKET_FD int

#include <string>

struct request;
struct response;
namespace JySockets {
class Socket;
}

class Jyhttp {
 public:
  Jyhttp();
  Jyhttp(const Jyhttp& obj);
  ~Jyhttp();
  Jyhttp& Get(const std::string& path, void (*)(const request&, response&));
  void Listen(const int& port);

 private:
  JySockets::Socket* socket_ptr;  // Type: JySockets::Socket
};

struct request {
  std::string id;
  // TODO
};

struct response {
  std::string id;
  // TODO
};

namespace JySockets {
class Socket {
 public:
  virtual const SOCKET_FD CreateSocket() = 0;
  virtual std::string GetRawText() = 0;
  virtual bool WriteOut() = 0;
};
}  // namespace JySockets
#endif  // JYHTTP_HPP
