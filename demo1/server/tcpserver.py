import json
import socket  # 导入 socket 模块
from base64 import encode


# s = socket.socket()  # 创建 socket 对象
# host = socket.gethostname()  # 获取本地主机名
# port = 5000  # 设置端口
# s.bind((host, port))  # 绑定端口
# print("123")
# s.listen(5)  # 等待客户端连接
# while True:
#     c, addr = s.accept()  # 建立客户端连接
#     print('连接地址：', addr)
#     c.send("欢迎访问菜鸟教程！".encode('utf-8'))
#     c.close()  # 关闭连接
#     break
# s.close()


class TcpServer:
    def __init__(self):
        self.sock = socket.socket()

    def bind_listen(self, host, port):
        # host = socket.gethostname()  # 获取本地主机名
        # port = 5000  # 设置端口
        self.sock.bind((host, port))
        # print("------")
        self.sock.listen(5)

    def accpect(self):
        c, addr = self.sock.accept()  # 建立客户端连接
        a = c.recv(1024)
        b = json.loads(a.decode('utf-8'))
        print("recive:", b)
        a=self.process_request(a)
        c.sendall("完成操作".encode('utf-8'))
        c.close()

    def replyplus(self, c, addr, data):
        c.send("已经全部接收".encode('utf-8'))
        c.close()

    def send(self, data):
        self.sock.send(data)
        print("data:", data)

    def recv(self, length):
        a = self.sock.recv(length)
        return a

    def close(self):
        return self.sock.close()
