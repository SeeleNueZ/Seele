import tcpclient
import json


class RpStud:
    # 存根，封装数据ing
    def __getattr__(self, item):
        # 此时打印方法不存在，会使用该魔法方法将数据传给server
        # 存在确实不用发过去了....
        def func(*args, **kwargs):
            d = {
                'method_name': item,
                'method_args': args,
                'method_kwargs': kwargs}
            # print('已经发现不对了')
            self.send(json.dumps(d).encode('utf-8'))  # 发送数据
            # print('数据不对', json.dumps(d).encode('utf-8'))
            data = self.recv(1024)  # 接收方法执行后返回的结果
            data = data.decode('utf-8')
            print("revdata:", data)
            return data

        setattr(self, item, func)
        return func


class RPCClient(tcpclient.TcpClinet, RpStud):
    pass
