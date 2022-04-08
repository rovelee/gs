// 引入mysql模块
const mysql = require('mysql');
// 创建连接池对象
const pool = mysql.createPool({
    host:'127.0.0.1',
    port:'3306',
    user:'root',
    password:'',
    database:'music',
    connectionLimit:15
});

// 把连接池对象暴露出去
module.exports = pool;