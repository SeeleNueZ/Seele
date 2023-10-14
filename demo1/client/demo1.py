import json
import socket
import rpcclient

def openreadtxt(file_name):
    with open("1.txt", "r", encoding='utf-8') as f:  # 打开文本
        data = f.read()  # 读取文本
    return data

if __name__ == '__main__':
    # d = {
    #     'method_name': "printplus",
    #     'method_args': "1",
    #     'method_kwargs': "name=1"}
    # b = json.dumps(d).encode('utf-8')
    # print(b)
    # s.send(b)  # 发送数据
    host = socket.gethostname()  # 获取本地主机名
    port = 5000  # 设置端口
    s = rpcclient.RPCClient()
    s.connect(host, port)
    print("connecting....")
    txt=openreadtxt("1.txt")
    print(txt)
    txt=str(txt)
    #txt="abcd"
    res = s.printplus(txt, name="wwwww")
    data = s.recv(1024)
    print(data.decode('utf-8'))
    s.close()



