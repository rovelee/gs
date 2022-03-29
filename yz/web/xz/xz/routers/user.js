// 引入express模块
const express=require('express');
// 引入连接池对象
const pool=require('../pool.js');
// 创建路由器对象
const r=express.Router();


function fn(req,res,next){
	var reg=/^1[3-9]\d{9}$/.test(req.body.phone);
	if(!reg){
		res.send({code:405,msg:'手机号码格式错误'});
		return;
	}else{
		next();
	}
}
r.use('/myreg',fn);

// 用户注册接口
r.post('/reg',(req,res,next)=>{
	var obj=req.body;
	// console.log(obj);
	pool.query('INSERT INTO xz_user SET?',[obj],(err,result)=>{
		if(err){
			// throw err;
			// 交给下一个错误处理的中间件
			next(err);
			// 阻止往后执行
			return;
		}
		console.log('注册成功');
		res.send({code:200,msg:'注册成功'});
	});
});

// 用户删除接口
r.delete('/delete/:uid',(req,res,next)=>{
	var str=req.params.uid;
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

// 修改信息接口
r.put('/update',(req,res,next)=>{
	var obj=req.body;
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

// 用户登录接口
r.post('/login',(req,res,next)=>{
	var obj=req.body;
	pool.query('SELECT * FROM xz_user WHERE uid=? AND upwd=?',[obj.uid,obj.upwd],(err,result)=>{
		if(err){
			next(err);
			return;
		}else{
			if(result[0]){
				res.send({code:200,msg:'登陆成功'});
			}else{
				res.send({code:500,msg:'用户名或密码错误'});
			}
		}
	});

});

// 找回密码接口
r.post('/getpwd',(req,res,next)=>{
	// 获取用户输入的信息
	var obj=req.body;
	// 根据信息查询数据
	pool.query('SELECT * FROM xz_user WHERE uid=? AND email=?',[obj.uid,obj.email],(err,result)=>{
		if(err){
			next(err);
			return;
		}else{
			// 如果查询到了
			if(result[0]){
				// 将该用户的密码修改为新密码
				pool.query('UPDATE xz_user SET upwd=? WHERE uid=?',[obj.upwd,obj.uid],(err,result,next)=>{
					if(err){
						next(err);
						return;
					}else{
						res.send({code:200,msg:'修改密码成功'});
					}
				});
			}else{
				res.send({code:500,msg:'用户信息错误'});
			}
		}
	});
});

module.exports=r;