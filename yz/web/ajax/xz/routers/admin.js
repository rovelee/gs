// 引入express模块
const express = require('express');
// 引入连接池对象
const pool = require('../pool.js');
// 创建管理员路由器
const r = express.Router();

// 管理员登录接口
r.post('/login',(req,res,next)=>{
    let obj = req.body;
    console.log(obj);
    pool.query('SELECT * FROM admin WHERE a_names=? AND a_pwd=?',[obj.a_name,obj.a_pwd],(err,result)=>{
        if(err){
            next(err);
            return;
        }
        if(result.length !== 0){
            res.send({
                code:1,
                msg:'查询到了数据'
            });
        }else{
            res.send({
                code:0,
                msg:'未查询到数据'
            });
        }
    });
});

// 将管理员路由器暴露出去
module.exports=r;