// 引入express模块
const express=require('express');
// 创建WEB服务器
const app=express();
// 设置端口为2022
app.listen(2022);
// 引入用户路由器对象
const userRouter=require('./routers/user.js');
// 将post传递的参数转为对象
app.use(express.urlencoded({
	extended:true
}));
// 设置静态资源管理
app.use(express.static('./public'));
// 使用用户路由器,并设置前缀为 ('/v1/users')
app.use('/v1/users',userRouter);
// 在所有路由的后面设置错误处理中间件，拦截所有路由的错误，
app.use((err,req,res,next)=>{
	if(err){
		console.log(err);
	}
	res.send({code:502,msg:'服务器端错误'});
});