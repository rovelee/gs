// 引入express模块
const express=require('express');
// 创建用户路由器
const r=express.Router();
// 引入连接池对象
const pool=require('../pool.js');
// 设置中间件，拦截reg注册页面传递的信息，对其验证
function fn(req,res,next){
	var phone=/^1[3-9]\d{9}$/.test(req.body.phone);
	var email=/^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$/.test(req.body.email);
	if(!phone){
		res.send({code:500,msg:'手机号码格式错误'});
		return;
	}else if(!email){
		res.send({code:500,msg:'邮箱格式错误'});
		return;
	}else{
		next();
	}
}
r.use('/reg',fn);

// 用户注册接口 (post /reg)
r.post('/reg',(req,res,next)=>{
	var obj=req.body;
	pool.query('INSERT INTO xz_user SET?',[obj],(err,result)=>{
		if(err){
			next(err);
			return;
		}
		res.send({code:200,msg:'创建成功'});
	});
});

// 删除用户接口 (delete /:uid)
r.delete('/:uid',(req,res,next)=>{
	var obj=req.params;
	pool.query('DELETE FROM xz_user WHERE uid=?',[obj.uid],(err,result)=>{
		if(err){
			next(err);
			return;
		}
		if(result.affectedRows!==0){
			res.send({code:200,msg:'删除成功'});
		}else{
			res.send({code:500,msg:'删除失败'});
		}
	});
});

// 修改信息接口 (put /)
r.put('/',(req,res,next)=>{
	var obj=req.body;
	pool.query('UPDATE xz_user SET? WHERE uid=?',[obj,obj.uid],(err,result)=>{
		if(err){
			next(err);
			return;
		}
		if(result.changedRows!==0){
			res.send({code:200,msg:'修改成功'});
		}else{
			res.send({code:500,msg:'修改失败'});
		}
	});
});

// 用户登录接口 (post /login)
r.post('/login',(req,res,next)=>{
	var obj=req.body;
	// 判断是否为空
	if(obj.uid===''){
		res.send({code:401,msg:'账号不能为空'});
		return;
	}else if(!obj.upwd){
		res.send({code:402,msg:'密码不能为空'});
		return;
	}
	pool.query('SELECT * FROM xz_user WHERE uid=? AND upwd=?',[obj.uid,obj.upwd],(err,result)=>{
		if(err){
			next(err);
			return;
		}
		if(result.length!==0){
			res.send({code:200,msg:'登录成功'});
		}else{
			res.send({code:500,msg:'用户名或密码错误'});
		}
	});
});

// 找回密码接口 (post /getpwd)
r.post('/getpwd',(req,res,next)=>{
	var obj=req.body;
	pool.query('SELECT * FROM xz_user WHERE uid=? AND email=?',[obj.uid,obj.email],(err,result)=>{
		if(err){
			next(err);
			return;
		}
		if(result.length!==0){
			pool.query('UPDATE xz_user SET upwd=? WHERE uid=?',[obj.upwd,obj.uid],(err,result)=>{
				if(err){
					next(err);
					return;
				}
				if(result.changedRows!==0){
					res.send({code:200,msg:'修改成功'});
				}else{
					res.send({code:500,msg:'新密码不能和原密码相同'});
				}
			});
		}else{
			res.send({code:500,msg:'用户信息错误'});
		}
	});
});


// 将路由器对象暴露出去
module.exports=r;