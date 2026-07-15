import socket

# create a socket object
s=socket.socket()
print("Socket succesfully created")

# reserve a port on your computer in our
# case it is 12345 but it can be anything
port=12345

#we bind to the port
s.bind(('',port))
print ("socket binded to %s" %(port))

#put the socket into listening mode
s.listen(5)
print ("socket is listening")

while True:
    # Establish connection with client.
    c, addr = s.accept()
    print('Got connection from', addr)

    # send a thank you message to the client. encoding to send byte type.
    c.send('Thank you for connecting'.encode())

    # Close the connection with the client
    c.close()

    # Breaking once connection closed
    break

#passing an empty string to bind->server can listen to incoming connections from other computers as well
#if we would have passed 127.0.0.1->listen only to those calls made within the local computer
#server in listening mode->5 means that 5 connections are kept waiting if the server is busy
#if a 6th socket tries to connect because we put the 5 it will be refused