var timer=setInterval(()=>{
	// 获取当前时间存入d
	var d=new Date();
	// 获取2022-3-23日,23点整的时间存入d1
	var d1=new Date(2022,3,23,23,0,0);
	// 获取d1和d的时间戳差值，并除1000换算成秒
	var second=(d1-d)/1000;
	// console.log(second);
	var s=parseInt(second%60);
	// console.log(s.toFixed(0));
	// 换算成分钟
	var m=parseInt((second/60)%60);
	// console.log(m.toFixed(0));
	// 换算成小时
	var h=parseInt((second/3600)%24);
	// console.log(h.toFixed(0));
	console.log(h,m,s);
},1000);