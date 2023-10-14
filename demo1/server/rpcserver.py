import json

import tcpserver


class RpStud:
    # 存根，人话就是可以使用的函数们
    def __init__(self):
        self.funcs = {}

    # 注册函数，用于维护整个可以使用的函数列表
    def register(self, fn, name=None):
        if name is None:
            name = fn.__name__
        self.funcs[name] = fn


class JsonRpc:
    def __init__(self):
        self.data = None

    def from_data(self, data):
        self.data = json.loads(data.decode('utf-8'))

    def call_method(self, data):
        self.from_data(data)
        method_name = self.data['method_name']
        method_args = self.data['method_args']
        method_kwargs = self.data['method_kwargs']
        if (method_name in self.funcs):
            res = self.funcs[method_name](*method_args, **method_kwargs)
        else:
            res = 'Please use the correct function'
        data = {"res": res}
        return json.dumps(data)


class RPCServer(tcpserver.TcpServer, JsonRpc, RpStud):
    def __init__(self):
        JsonRpc.__init__(self)
        tcpserver.TcpServer.__init__(self)
        RpStud.__init__(self)

    def loop(self, host, port):
        # print("pass3")
        self.bind_listen(host, port)
        # print("pass3")
        print('Server begin.....', '{}:{}.'.format(host, port))
        while True:
            self.accpect()

    def process_request(self, data):
        self.from_data(data)
        return self.call_method(data)
