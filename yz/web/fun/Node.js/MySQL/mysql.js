// 引入express模块
const express=require('express');
// 引入MySQL模块
const mysql=require('mysql');
// 创建WEB服务器
const app=express();
// 创建连接池对象
const pool=mysql.createPool({
    host:'127.0.0.1',
    port:'3306',
    user:'root',
    password:'',
    database:'tedu',
    connectionLimit:15
});
// 设置端口
app.listen(2022);

// 获取post传递的参数
app.use(express.urlencoded({
    extended:true
}));

// 添加员工的接口
app.post('/v1/emps',(req,res)=>{
    // 将获取的参数存入对象
    var obj=req.body;
    // console.log(obj);
    // 将获取的数据插入员工表emp
    pool.query('INSERT INTO emp SET?',[obj],(err,result)=>{
        // err:可能产生的错误
        if(err){
            throw err;
        }
        // result:成功的结果
        // console.log(result);
        console.log('插入成功');
    });
});

// 删除员工的接口
app.delete('/v1/emps',(req,res)=>{
    // 获取传递的参数，删除该员工
    var obj=req.body;
    pool.query('DELETE FROM emp WHERE eid=?',[obj.eid],(err,result)=>{
        if(err){
            throw err;
        }
        if(result.affectedRows===0){
            res.send({code:500,msg:'删除失败'});
        }else{
            res.send({code:200,msg:'删除成功'});
        }
    });
});

// 修改数据的接口
app.put('/v1/emps',(req,res)=>{
    // 获取传递的参数，修改该员工数据
    var obj=req.body;
    pool.query('UPDATE emp SET salary=? WHERE eid=?',[obj.salary,obj.eid],(err,result)=>{
        if(err){
            throw err;
        }
        console.log(result);
    });
});