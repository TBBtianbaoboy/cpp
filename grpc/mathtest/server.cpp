#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/support/status.h>
#include <string>

#include <grpcpp/grpcpp.h>
#include "mathtest.grpc.pb.h"

using std::string;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using mathtest::MT;
using mathtest::MathRequest;
using mathtest::MathReply;

class MathServiceImp final:public MT::Service {
    Status getValue(
            ServerContext* context,
            const MathRequest* req,
            MathReply* resp
            )override{
        int a = req->a();
        int b = req->b();
        resp->set_result(a*b);
        return Status::OK;
    }
};

void Run(){
    string address("0.0.0.0:5000");
    MathServiceImp service;

    ServerBuilder builder;
    builder.AddListeningPort(address,grpc::InsecureServerCredentials()); 
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout <<"Server listening on port: " << address << std::endl;

    server->Wait();
}

int main(){
    Run();
    return 0;
}


