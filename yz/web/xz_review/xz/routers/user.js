// 引入express模块
const express=require('express');
// 创建用户路由器对象
const r=express.Router();
// 引入连接池对象
const pool=require('../pool.js');

// 设置中间件，对用户注册时填写的信息进行格式验证
function fn(req,res,next){
	var phone=/^1[3-9]\d{9}$/.test(req.body.phone);
	var email=/^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$/.test(req.body.email);
	if(!phone){
		res.send({code:500,msg:'手机号码格式错误'});
		return;
	}else if(!email){
		res.send({code:500,msg:'邮箱格式错误'});
	}else{
		next();
	}
}
r.use('/reg',fn);

// 创建用户注册接口 (post /reg)
r.post('/reg',(req,res,next)=>{
	// res.send('success');
	// 将post传递的参数存入对象obj
	var obj=req.body;
	// 执行插入SQL命令
	pool.query('INSERT INTO xz_user SET?',[obj],(err,result)=>{
		if(err){
			// 将可能出现的错误传递到错误处理中间件
			next(err);
			// 阻止后续代码执行
			return;
		}
		// send方法会自动把对象转为json
		res.send({code:200,msg:'创建成功'});
	});
});

// 创建删除用户接口 (delete /delete/:id)
r.delete('/delete/:uid',(req,res,next)=>{
	// 将delete路由传递的参数存入字符串str
	var str=req.params.uid;
	// 执行删除SQL命令
	pool.query('DELETE FROM xz_user WHERE uid=?',[str],(err,result)=>{
		if(err){
			next(err);
			return;
		}
		if(result.affectedRows===0){
			res.send({code:500,msg:'删除失败'});
		}else{
			res.send({code:200,msg:'删除成功'});
		}
	});
});

// 修改用户数据接口 (put /update)
r.put('/update',(req,res,next)=>{
	// 将put传递的参数存入对象obj
	var obj=req.body;
	// 执行修改SQL命令
	pool.query('UPDATE xz_user SET? WHERE uid=?',[obj,obj.uid],(err,result)=>{
		if(err){
			next(err);
			return;
		}
		if(result.changedRows===0){
			res.send({code:500,msg:'修改失败'});
		}else{
			res.send({code:200,msg:'修改成功'});
		}
	});
});

// 用户登录接口 (post /login)
r.post('/login',(req,res,next)=>{
	// 将post传递的参数存入对象obj
	var obj=req.body;
	// 执行查询SQL命令，查看数据库中是否存在该数据，确定账号密码是否正确
	pool.query('SELECT * FROM xz_user WHERE uid=? AND upwd=?',[obj.uid,obj.upwd],(err,result)=>{
		if(err){
			next(err);
			return;
		}
		if(result.length!==0){
			res.send({code:200,msg:'登陆成功'});
		}else{
			res.send({code:500,msg:'用户名或密码错误'});
		}
	});
});

// 找回密码接口 (post /getpwd)
r.post('/getpwd',(req,res,next)=>{
	// 将post传递的参数保存到对象obj
	var obj=req.body;
	// 执行查询SQL命令，查看数据库中是否存在该数据，确定账号密码是否正确
	pool.query('SELECT * FROM xz_user WHERE uid=? AND email=?',[obj.uid,obj.email],(err,result)=>{
		if(err){
			next(err);
			return;
		}
		// 如果账号密码正确，将用户输入的账号的密码改为用户输入的新密码
		if(result.length!==0){
			// 执行修改SQL命令
			pool.query('UPDATE xz_user SET upwd=? WHERE uid=?',[obj.upwd,obj.uid],(err,result)=>{
				if(err){
					next(err);
					return;
				}
				if(result.changedRows===0){
					res.send({code:500,msg:'修改失败'});
				}else{
					res.send({code:200,msg:'修改成功'});
				}
			});
		}else{
			// 如果账号密码错误
			res.send({code:500,msg:'用户信息错误'});
		}
	});
});


// 将路由器对象暴露出去
module.exports=r;