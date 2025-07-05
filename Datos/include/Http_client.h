#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>
#include <curl/curl.h>
#include <stdexcept>

class Http_client
{
public:
    static std::string dowladUrl(std::string url);
};

#endif // HTTP_CLIENT_H