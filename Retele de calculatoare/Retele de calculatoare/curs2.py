import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(("0.0.0.0",7777))
s.sendto(b"Nicola Tea",("193.231.20.76",7777))
print(s.recvfrom(5))
