import rpcserver
import socket


def printplus(*args, **kwargs):
    print("进行一个打印的操作")
    print("打印出：",args)
    print("test: args = {}, kwargs = {}".format(args, kwargs))
    return 'the test function has been called'


if __name__ == '__main__':
    host = socket.gethostname()  # 获取本地主机名
    port = 5000  # 设置端口
    s = rpcserver.RPCServer()
    #print("pass1",host,port)
    s.register(printplus)       # 注册函数
    print("完成服务端初始化")
    s.loop(host, port)       # 要监听的 IP 和端口
    #print("pass3")