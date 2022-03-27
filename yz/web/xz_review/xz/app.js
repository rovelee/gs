// 引入express模块
const express=require('express');
// 创建WEB服务器
const app=express();
// 设置端口为2022
app.listen(2022);
// 引入用户路由器
const userRouter=require('./routers/user.js');

// 将post传递的参数转为对象
app.use(express.urlencoded({
	extended:true
}));

// 设置静态资源管理
app.use(express.static('./public'));
// 使用用户路由器，并添加前缀为 /v1/users
app.use('/v1/users',userRouter);


// 在所有路由的后面，添加错误处理中间件，拦截所有路由的错误
app.use((err,req,res,next)=>{
	// err:接收传递过来的错误
	if(err){
		// 将错误原因打印出来，便于调试
		console.log(err);
	}else{
		res.send({code:502,msg:'服务器端错误'});
	}
});