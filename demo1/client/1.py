import json
import socket

s = socket.socket()
host = socket.gethostname()  # 获取本地主机名
port = 5000  # 设置端口
s.connect((host, port))
print("123")
d = {
    'method_name': "printplus",
    'method_args': "1",
    'method_kwargs': "name=1"}
b = json.dumps(d).encode('utf-8')
s.send(b)
print(s.recv(1024).decode('utf-8'))
s.close()
