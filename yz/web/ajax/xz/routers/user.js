// 引入express模块
const express = require('express');
// 创建用户路由器
const r = express.Router();
// 引入连接池对象
const pool = require('../pool.js');

// 用户注册
r.post('/update',(req,res,next)=>{
    let obj = req.body;
    pool.query('INSERT INTO xz_user SET?',[obj],(err,result)=>{
        if(err){next(err);return;}
        console.log(result);
        if(result.affectedRows !== 0){
            res.send({code:1,msg:'数据插入成功'});
        }else{
            res.send({code:0,msg:'数据插入失败'});
        }
    });
});

// 用户登录接口
r.post('/login',(req,res,next)=>{
    let obj = req.body;
    console.log(obj);
    pool.query('SELECT * FROM xz_user WHERE uname=? AND upwd=?',[obj.uname,obj.upwd],(err,result)=>{
        if(err){next(err);return;}
        if(result.length !== 0){
            res.send({code:1,msg:'查询到了数据'});
        }else{
            res.send({code:0,msg:'未查询到数据'});
        }
    });
});


// 暴露用户路由器
module.exports = r;