import json
import socket


# s=socket.socket()
# host = socket.gethostname()  # 获取本地主机名
# port = 5000  # 设置端口
# s.connect((host,port))
# print("123")
# print(s.recv(1024).decode('utf-8'))
# s.close()

class TcpClinet(object):
    def __init__(self):
        self.sock = socket.socket()

    # 类似于封装这些方法，本质上和上面写的一样
    def connect(self, host, port):
        # host = socket.gethostname()  # 获取本地主机名
        # port = 5000  # 设置端口
        self.sock.connect((host, port))

    def send(self, data):
        self.sock.send(data)
        print("data:",data)

    def recv(self, length):
        a = self.sock.recv(length)
        return a

    def close(self):
        return self.sock.close()
