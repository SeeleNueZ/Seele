import socket
import json

s = socket.socket()  # 创建 socket 对象
host = socket.gethostname()  # 获取本地主机名
port = 5000  # 设置端口
s.bind((host, port))  # 绑定端口
print("123")
s.listen(5)  # 等待客户端连接
while True:
    c, addr = s.accept()  # 建立客户端连接
    print('连接地址：', addr)
    a = c.recv(1024).decode('utf-8')
    a = json.loads(a)
    print(a)
    c.send("欢迎访问菜鸟教程！".encode('utf-8'))
    c.close()  # 关闭连接
    break
s.close()
