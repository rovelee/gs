// 引入express模块
const express=require('express');
// 引入数据库模块
const mysql=require('mysql');
// 创建连接池对象
const pool=mysql.createPool({
	host:'127.0.0.1',
	port:'3306',
	user:'root',
	password:'',
	database:'xz',
	connectionLimit:15 //连接池的数量，默认也是15个
});

// 将连接池对象暴露出去
module.exports=pool;