
async_tcp_echo_server : async_tcp_echo_server.cpp
	g++ -std=c++11 async_tcp_echo_server.cpp -o async_tcp_echo_server -lboost_system


blocking_tcp_echo_client : blocking_tcp_echo_client.cpp
	g++ -std=c++11 blocking_tcp_echo_client.cpp -o blocking_tcp_echo_client -lboost_system


clean:
	rm -f async_tcp_echo_server blocking_tcp_echo_client
