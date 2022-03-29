const express=require('express');
const app=express();
app.listen(2022);
// 引入注册路由器模块
const userRouter=require('./routers/user.js');
// 获取post传递的参数
app.use(express.urlencoded({
    extended:true
}));
// 设置静态资源管理
app.use(express.static('./public'));
// 使用路由器，添加前缀为 /reg
app.use('/v1/users',userRouter);

// 在所有路由的后边，添加错误处理中间件，拦截所有路由的错误
app.use((err,req,res,next)=>{
	// err:接收的传递过来的错误
	if(err){
		// 为了调试，需要查看错误原因
		console.log(err);
	}
	// 响应服务器端错误
	res.send({code:502,msg:'服务器端错误'});
});