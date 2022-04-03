// 引入express模块
const express = require('express');
// 创建服务器
const app = express();
// 设置端口为2022
app.listen(2022)
// 引入管理员路由器
const adminRouter = require('./routers/admin.js');
// 引入cors
const cors = require("cors");

// 将传递的参数存入对象
app.use(express.urlencoded({
    extended:true
}));

//跨域设置(所有域名)
app.use(cors({
    origin:['http://localhost:8848','http://127.0.0.1:8848'],
    origin:['http://localhost:5500','http://127.0.0.1:5500'],  //指定接收的地址
    methods:['GET','POST','DELETE','PUT'],  //指定接收的请求类型
    alloweHeaders:['Content-Type','Authorization']  //指定header
}));

// 设置静态资源管理
app.use(express.static('./public'));

// 使用管理员路由器，并添加前缀为 /v1/admin
app.use('/v1/admin',adminRouter);

// 在所有路由的后面设置错误处理中间件，拦截所有路由的错误
app.use((err,req,res,next)=>{
    if(err){
        console.log(err);
    }
    res.send({code:502,msg:'服务器端错误'});
});