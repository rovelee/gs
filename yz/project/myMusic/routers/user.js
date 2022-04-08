// 引入express模块
const express = require('express');
const PoolConfig = require('mysql/lib/PoolConfig');
// 创建用户路由器
const r = express.Router();
// 引入连接池对象
const pool = require('../pool.js');

// 用户名查询接口
r.post('/search',(req,res,next)=>{
    let obj = req.body;
    console.log(obj);
    pool.query("SELECT * FROM user WHERE uname=?",[obj.uname],(err,result)=>{
        if(err){next(err);return;}
        if(result.length !== 0){
            res.send({code:1,msg:'查到了一条数据'});
        }else{
            res.send({code:0,msg:'未查询到数据'});
        }
    });
});

// 查询用户信息接口
r.get('/search/:user',(req,res,next)=>{
    let obj = req.params;
    console.log(obj);
    pool.query("SELECT * FROM user WHERE uname=?",[obj.user],(err,result)=>{
        if(err){next(err);return;}
        if(result.length !== 0){
            res.send({
                code:1,
                msg:'查询到了数据',
                data:result
            });
        }else{
            res.send({code:0,msg:'未查询到数据'});
        }
    });
});

// 用户注册接口
r.post('/reg',(req,res,next)=>{
    let obj = req.body;
    console.log(obj);
    pool.query("INSERT INTO user SET?",[obj],(err,result)=>{
        if(err){next(err);return;}
        if(result.affectedRows !== 0){
            res.send({code:1,msg:'注册成功'});
        }else{
            res.send({code:0,msg:'注册失败'});
        }
    });
});

// 用户登录接口
r.post('/login',(req,res,next)=>{
    let obj = req.body;
    console.log(obj);
    pool.query("SELECT * FROM user WHERE uname=? AND upwd=?",[obj.uname,obj.upwd],(err,result)=>{
        if(err){next(err);return;}
        if(result.length !== 0){
            res.send({
                code:1,
                msg:'查询到了数据',
                data:result
            });
        }else{
            res.send({code:0,msg:'未查询到数据'});
        }
    });
});

// 用户修改信息接口
r.post('/update',(req,res,next)=>{
    let obj = req.body;
    console.log(obj);
    pool.query("UPDATE user SET? WHERE uname=?",[obj,obj.uname],(err,result)=>{
        if(err){next(err);return;}
        if(result.changedRows !== 0){
            res.send({
                code:1,
                msg:'修改成功',
                data:result
            });
        }else{
            res.send({code:0,msg:'修改失败'});
        }
    });
});

// 把用户路由器暴露出去
module.exports = r;