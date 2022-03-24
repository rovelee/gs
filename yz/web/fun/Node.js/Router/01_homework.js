// 创建WEB服务器，托管静态资源到public目录，在目录下创建文件login.html，点击提交向服务器发请求(post /mylogin),响应'登陆成功，欢迎：xxx';添加中间件拦截对/mylogin的请求，如果用户名是root，响应'该用户不可用',否则往后执行
const express=require('express');
const app=express();
const loginRouter=require('./login.js');
app.listen(2022);

// 设置静态资源管理文件public
app.use(express.static('./public'));
// 路由器方法
// 使用路由器，并添加前缀为/login
app.use('/login',loginRouter);


// 路由方法
/*// 将post传递的值转为对象
app.use(express.urlencoded({
	extended:true
}));
// 创建函数fn();
function fn(req,res,next){
	if(req.body.uname==='root'){
		res.send('该用户不可用。');
	}else{
		next();
	}
}
// 设置中间件
app.use('/mylogin',fn);
app.post('/mylogin',(req,res)=>{
	res.send(`
		登录成功！<br>
		欢迎：${req.body.uname}
		`);
});*/