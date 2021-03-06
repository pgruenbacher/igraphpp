#ifndef IGRAPHPP_EXCEPTION_HPP_
#define IGRAPHPP_EXCEPTION_HPP_

#include <stdexcept>

#include <igraph/igraph.h>

namespace igraph {

class Exception : public std::exception {
 public:
  explicit Exception(int code) : std::exception(), errno_(code){};

  virtual ~Exception() throw() {}

  virtual const char *what() const throw() {
    return igraph_strerror(static_cast<int>(errno_));
  }

 private:
  int errno_;
};

static inline int SafeCall(int ret) {
  if (IGRAPH_UNLIKELY(ret != IGRAPH_SUCCESS)) throw Exception(ret);
  return ret;
}

}  // namespace igraph

#endif  // IGRAPHPP_EXCEPTION_HPP_
