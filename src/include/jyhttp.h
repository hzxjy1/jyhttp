#ifndef JYHTTP
#define JYHTTP

#include <functional>
#include <string>

struct request;
struct response;

class Jyhttp {
 public:
  Jyhttp();
  ~Jyhttp();
  Jyhttp& Get(const std::string& path,
              std::function<response(const request&)> handler);
  void Listen(const int& port);
};

struct request {
  std::string id;
};

struct response {
  std::string id;
};

#endif
