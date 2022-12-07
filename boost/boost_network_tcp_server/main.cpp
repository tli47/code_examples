#include <boost/asio.hpp>
#include <iostream>

using namespace std;

/**
 * 一段tcp server的例子代码
 */

int main(int argc, char** argv) {
    try {
        cout << "server start..." << endl;
        // io_service对象
        boost::asio::io_service ios;
        //绑定端口6688
        boost::asio::ip::tcp::acceptor acceptor(
            ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 6688));
        cout << acceptor.local_endpoint().address() << endl;

        char msgFromClient[256];
        char msgToClient[256];
        // socket对象
        boost::asio::ip::tcp::socket sock(ios);
        //阻塞等待socket连接
        acceptor.accept(sock);
        while (1) {
            // sock.receive(boost::asio::buffer(msgFromClient));
            boost::asio::read(sock, boost::asio::buffer(msgFromClient));

            cout << "client:" << sock.remote_endpoint().address()
                 << "; msgFromClient: " << msgFromClient << endl;

            // handle the message form client
            string tmp = string(msgFromClient) + "<< handled";
            strcpy(msgToClient, tmp.c_str());

            // sock.write_some(boost::asio::buffer(msgToClient));
            boost::asio::write(sock, boost::asio::buffer(msgToClient));

            cout << "msgToClient: " << msgToClient << endl;
        }
    } catch (exception& e) {
        cout << "exception: " << e.what() << endl;
    }
    std::cout << "Hello, world! server" << std::endl;
    return 0;
}
