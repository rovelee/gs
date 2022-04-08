// 引入express模块
const express = require('express');
// 创建服务器
const app = express();
// 设置端口3000
app.listen(3000);
// 引入管理员路由器对象
const adminRouter = require('./routers/admin.js');
// 引入用户路由器对象
const userRouter = require('./routers/user.js');

// 引入cors模块
const cors = require('cors');
//跨域设置(所有域名)

app.use(cors({
    origin:['http://localhost:8848','http://127.0.0.1:8848'],
    origin:['http://localhost:5500','http://127.0.0.1:5500'],  //指定接收的地址
    methods:['GET','POST','DELETE','PUT'],  //指定接收的请求类型
    alloweHeaders:['Content-Type','Authorization']  //指定header
}));


// 把传递的参数转为对象
app.use(express.urlencoded({
    extended:true
}));
// 设置静态资源管理
app.use(express.static('./public'));
// 挂载用户路由器，并设置前缀为 /v1/users
app.use('/v1/admin',adminRouter);
// 挂载用户路由器，并设置前缀为 /v1/users
app.use('/v1/users',userRouter);

// 在所有路由的后面，设置错误处理中间件，拦截路由的错误
app.use((err,req,res,next)=>{
    if(err){
        console.log(err);
    }
    res.send({code:502,msg:'服务器端错误'});
});