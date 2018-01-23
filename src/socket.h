#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "http.h"
#include <boost/shared_ptr.hpp>
#include <uv.h>

class HttpRequest;
class WebApplication;

class Socket {
public:
  VariantHandle handle;
  boost::shared_ptr<WebApplication> pWebApplication;
  CallbackQueue* background_queue;
  std::vector<boost::shared_ptr<HttpRequest>> connections;

  Socket(boost::shared_ptr<WebApplication> pWebApplication,
         CallbackQueue* background_queue)
    : pWebApplication(pWebApplication), background_queue(background_queue)
  {
  }

  void addConnection(boost::shared_ptr<HttpRequest> request);
  void removeConnection(boost::shared_ptr<HttpRequest> request);

  virtual ~Socket();
};


// Deleter function for shared_ptr<Socket>.
void Socket_deleter(Socket*);

#endif // SOCKET_HPP
