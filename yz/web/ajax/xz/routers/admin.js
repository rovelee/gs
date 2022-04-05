// 引入express模块
const express = require('express');
// 创建管理员路由器
const r = express();
// 引入连接池对象
const pool = require('../pool.js');

// 管理员登录接口
r.post('/login',(req,res,next)=>{
    let obj = req.body;
    console.log(obj);
    if(obj.aname === 'root' && obj.apwd === '123456'){
        res.send({code:1,msg:'管理员信息正确'});
    }else{
        res.send({code:0,msg:'管理员信息错误'});
    }
});

// 用户列表接口
r.get('/list',(req,res,next)=>{
    pool.query('SELECT * FROM xz_user',(err,result)=>{
        if(err){next(err);return;}
        res.send({
            code:1,
            msg:'查到了所有的数据',
            data:result
        });
    });
});

// 修改信息接口
r.put('/update',(req,res,next)=>{
    let obj = req.body;
    pool.query("UPDATE xz_user SET? WHERE uid=?",[obj,obj.uid],(err,result)=>{
        if(result.changedRows !== 0){
            res.send({code:1,msg:'修改成功'});
        }else{
            res.send({code:0,msg:'修改失败'});
        }
    });
});

// 删除用户接口
r.delete('/del/:uid',(req,res,next)=>{
    let obj = req.params;
    console.log(obj);
    pool.query('DELETE FROM xz_user WHERE uid=?',[obj.uid],(err,result)=>{
        if(err){next(err);return;}
        if(result.affectedRows !== 0){
            res.send({code:1,msg:'删除成功'});
        }else{
            res.send({code:0,msg:'删除失败'});
        }
    });
});


// 将管理员路由器暴露出去
module.exports = r;