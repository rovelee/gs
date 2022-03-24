// 引入express模块
const express=require('express');
// 设置路由器
const r=express.Router();

// 将post传递的值转为对象
r.use(express.urlencoded({
	extended:true
}));
function fn(req,res,next){
	// 如果登录的用户名为'root'
	if(req.body.uname==='root'){
		res.send('该用户不可用。');
	}else{
		// 否则将继续执行/mylogin路由
		next();
	}
}
// 设置中间件,拦截对/mylogin的请求
r.use('/mylogin',fn);
// 添加路由(post /mylogin)
r.post('/mylogin',(req,res)=>{
	res.send(`
		登录成功！<br>
		欢迎：${req.body.uname}
		`);
});
// 添加路由(get /reg)
r.get('/reg',(req,res)=>{
	res.sendFile(__dirname+'/reg.html');
});

// 添加路由(post /myreg)
r.post('/myreg',(req,res)=>{
	// console.log(req.body);
	res.send(`
		注册成功！<br>
		用户名：${req.body.uname}<br>
		邮箱：${req.body.email}<br>
		电话：${req.body.phone}
		`);
});

module.exports=r;