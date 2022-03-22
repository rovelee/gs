// 声明变量存储定时器执行次数 
var i=1;
// 设置周期定时器，每隔3s执行一次
var timer=setInterval(function(){
	console.log('Hello!');
	// 每执行一次次数加一
	i++;
	// 当执行次数大于三时，执行清除定时器
	if(i>3){
	clearInterval(timer);
}
},3000);