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

extern "C" {
void *Jyhttp_Create();
void Jyhttp_Destroy(void *obj);
void Jyhttp_Get(void *obj, const char *path,
                response (*handler)(const request *));
void Jyhttp_Listen(void *obj, const int *port);
}

#endif // JYHTTP_HPP
