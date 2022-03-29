var phone='13812345678';
// 使用正则表达式去验证一个手机号码
var reg=/^1[3-9]\d{9}$/.test(phone);
if(!reg){
	console.log('不是一个手机号码');
}