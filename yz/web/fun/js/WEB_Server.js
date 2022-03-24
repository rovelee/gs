// 引入http模块
const http=require('http');
// 创建WEB服务器
const app=http.createServer();
// 设置端口为2022
app.listen(2022,()=>{
	console.log('WEB服务器启动成功');
});

// 请求WEB服务器
// 域名
// http:localhost:2022
// IP地址
// http:127.0.0.1:2022

// 接收请求，通过事件监听请求，并做出回应
app.on('request',(req,res)=>{
	// req 请求的对象，res 响应的对象
	// 设置响应头的信息
	res.setHeader('Content-Type','text/html;charset=utf-8');
	// 设置响应到浏览器的内容
	res.write('木大木大木大木大！！！');
	// 结束并发送响应
	res.end();
});