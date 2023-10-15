参考了https://www.cnblogs.com/wanghuizhao/p/17237670.html
Network Service 直接使用Python Socket相关的API实现
.传输数据使用JSON，在Socket层被压成了二进制
client下属
demo1.py：测试代码
1.py 一个简单的验证代码
1.txt 等待打印的文件
rpcclient.py 中间层
tcpclient 传输层
server下属
1.py 一个简单的验证代码
rpcserver.py 中间层，包括存根和可以使用的函数组
server.py 上层，函数真正的实现地方
tcpserver.py 传输层

使用方法：运行server.py，然后另起一个终端运行demo1.py
可以在server.py中看见1.txt的文本，demo1运行后会自动关闭，可以修改后再次打印

bug和问题:1.好像会多一组括号，或许是去封装的时候没处理好
2.server需要一直开着，而且，没有实现关掉的方法，现在是用Windows直接关掉进程的方式关掉的

3.没有处理超大文件，事实上如果文件里面的内容太多应该要分段发的，没事实现这个
