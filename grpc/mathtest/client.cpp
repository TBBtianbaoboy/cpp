#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include <grpcpp/support/status.h>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "mathtest.grpc.pb.h"
#include "mathtest.pb.h"

using std::string;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using mathtest::MT;
using mathtest::MathRequest;
using mathtest::MathReply;

class MathTestClient{
    public:
        MathTestClient(std::shared_ptr<Channel> channel):stub_(MT::NewStub(channel)){}
        int getValue(int a,int b){
            MathRequest request;
            request.set_a(a);
            request.set_b(b);

            MathReply reply;

            ClientContext context;

            Status status = stub_->getValue(&context,request,&reply);

            if (status.ok()){
                return reply.result();
            }else{
                std::cout << status.error_code() << ":" << status.error_message() << std::endl;
                return -1;
            }
        }

    private:
        std::unique_ptr<MT::Stub> stub_;
};

void Run(){
    string address("0.0.0.0:5000");
    MathTestClient client(
            grpc::CreateChannel(address,
            grpc::InsecureChannelCredentials()
            )
        );
    int resp;
    int a = 5;
    int b = 10;
    resp = client.getValue(a,b);
    std::cout << "a * b = " << resp << std::endl;
}

int main(){
    Run();
    return 0;
}


