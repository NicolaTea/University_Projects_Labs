import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("193.231.20.76",6969))
msg,addr=s.recv(2)
print(msg)