#ifndef JYHTTP_HPP
#define JYHTTP_HPP

#include <functional>
#include <string>

struct request;
struct response;

class Jyhttp {
public:
  Jyhttp();
  ~Jyhttp();
  Jyhttp &Get(const std::string &path,
              std::function<response(const request &)> handler);
  void Listen(const int &port);
};

struct request {
  std::string id;
  // todo
};

struct response {
  std::string id;
  // todo
};

#endif // JYHTTP_HPP
