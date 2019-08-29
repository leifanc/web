#include <stdlib.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <functional>
#include <map>
#include "request.h"

using namespace std;

class Service{
public:
    bool init();
    bool set_response(const string& path, function<void (Request)> r);
    bool listen(const string& port);    
    void close();
    Service(Service&) = delete;
    Service& operator=(Service&) = delete;
private:
    
    int serv_sock;
    int clnt_sock;
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;

    map<string, function<void (Request)>> function_map;

};