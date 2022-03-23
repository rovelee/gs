// 使用Node.js下的express框架创建WEB服务器
// 引入框架
const express=require('express');
// 创建服务器
const app=express();
// 设置端口为2022
app.listen(2022,()=>{
	console.log('服务器启动成功');
});
// 使用路由传参，获取响应
app.get('/shopping',(req,res)=>{
	// req:请求的对象，res:响应的对象
	// 设置响应的内容并发送
	res.send('商品首页');
});
app.get('/shopping/:pname',(req,res)=>{
	// 设置响应的内容并发送
	res.send('商品详情页：'+req.params.pname);
});

// 使用get传递参数，获取响应
app.get('/login',(req,res)=>{
	res.sendFile(__dirname+'/login.html');
});
app.get('/mylogin',(req,res)=>{
	res.send('登陆成功！</br>'+'欢迎：'+req.query.uname+'</br>密码：'+req.query.upwd);
});