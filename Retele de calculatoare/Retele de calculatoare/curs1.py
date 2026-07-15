import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(("0.0.0.0",5555))
s.sendto(b"xxx",("127.0.0.1",5555))
print(s.recvfrom(5))