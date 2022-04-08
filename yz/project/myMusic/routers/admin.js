// 引入express模块
const express = require('express');
// 创建管理员路由器
const r = express.Router();
// 引入连接池对象
const pool = require('../pool.js');


// 管理员登录接口
r.post('/login',(req,res,next)=>{
    let obj = req.body;
    console.log(obj);
    pool.query("SELECT * FROM admin WHERE aname=? AND apwd=?",[obj.aname,obj.apwd],(err,result)=>{
        if(err){next(err);return;}
        if(result.length !== 0){
            res.send({code:1,msg:'查询到了数据'});
        }else{
            res.send({code:0,msg:'未查询到数据'});
        }
    });
});

// 遍历用户列表接口
r.get('/list',(req,res,next)=>{
    pool.query("SELECT * FROM user",(err,result)=>{
        if(err){next(err);return;}
        if(result.length !== 0){
            res.send({
                code:1,
                msg:'查询到了所有信息',
                data:result
            });
        }else{
            res.send({code:0,msg:'未查询到数据'});
        }
    });
});

// 删除用户接口
r.delete('/del/:uid',(req,res,next)=>{
    let obj = req.params;
    console.log(obj);
    pool.query("DELETE FROM user WHERE uid=?",[obj.uid],(err,result)=>{
        if(err){next(err);return;}
        if(result.affectedRows !== 0){
            res.send({code:1,msg:'删除成功'});
        }else{
            res.send({code:0,msg:'删除失败'});
        }
    });
});

// 查询用户信息接口
r.get('/search/:uid',(req,res,next)=>{
    let obj = req.params;
    console.log(obj);
    pool.query("SELECT * FROM user WHERE uid=?",[obj.uid],(err,result)=>{
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

// 修改用户信息接口
r.post('/update',(req,res,next)=>{
    let obj = req.body;
    console.log(obj);
    pool.query("UPDATE user SET? WHERE uid=?",[obj,obj.uid],(err,result)=>{
        if(err){next(err);return;}
        if(result.changedRows !== 0){
            res.send({code:1,msg:'修改成功'});
        }else{
            res.send({code:0,msg:'修改失败'});
        }
    });
});

// 将管理员路由器暴露出去
module.exports = r;