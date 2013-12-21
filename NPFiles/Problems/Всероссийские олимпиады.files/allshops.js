var Shops = '<table width=186 border=0 cellspacing=0 align=center bgcolor=#662985 cellpadding=0><tr><td align=center valign=top><nobr>'+
'<img src="http://u4001.82.spylog.com/cnt?cid=400182&p=0" alt="SpyLOG" border="0" width=1 height=1 >'+
'<a target=_blank href="http://www.megashop.ru/"><img src=http://www-banner.chat.ru/mshop.gif border=0></a>'+
'<a target=_blank href="http://www.kenga.ru/"><img src=http://www-banner.chat.ru/kenga.gif border=0></a></nobr><br><nobr>'+
'<a target=_blank href="http://www.aromat.ru/"><img src=http://www-banner.chat.ru/aromat.gif border=0></a>'+
'<a target=_blank href="http://www.bolero.ru/"><img src=http://www-banner.chat.ru/bolero.gif border=0></a></nobr><br><nobr>'+
'<a target=_blank href="http://www.cup.ru/"><img src=http://www-banner.chat.ru/cup.gif border=0></a>'+
'<a target=_blank href="http://www.wstore.ru/"><img src=http://www-banner.chat.ru/wstore.gif border=0></a></nobr><br>'+
'</td></tr></table><br>';
var Img = 'logo.gif';
var URL = 'http://www.allshops.ru';
var Width = 165;
var Height = 80;
var ALT = 'Allshops';
var MinWidth = 0;
var MainImgDir = 'http://www-banner.chat.ru/';
var ImgFile = MainImgDir+Img;
var TopImgFile = MainImgDir+'allshops.gif';
var TopImgAlt = 'Allshops';
var UpButton = MainImgDir+'up.gif';
var UpButtonAlt = "Развернуть";
var DownButton = MainImgDir+'down.gif';
var DownButtonAlt = "Свернуть";
var CloseButton = MainImgDir+'close.gif';
var CloseButtonAlt = "Закрыть";
var TurnOnButton = MainImgDir+'turn_on.gif';
var TurOnButtonAlt = "Развернуть";
var TurnOffButton = MainImgDir+'turn_off.gif';
var TurnOffButtonAlt = "Свернуть";
var DownBgcolor = '#421B57';
var CloseButtonHTML = '<a href="javascript:setState__(-1)" onMouseOver="window.status=\''+CloseButtonAlt+'\';return true" onMouseOut="window.status=\'\';return true"><img src="'+CloseButton+'" width=16 height=16 alt="'+CloseButtonAlt+'" border=0></a></td></tr></table></td></tr>';
var DownButtonHTML = '<a href="javascript:setState__(0)" onMouseOver="window.status=\''+DownButtonAlt+'\';return true" onMouseOut="window.status=\'\';return true"><img src="'+DownButton+'" width=16 height=16 alt="'+DownButtonAlt+'" border=0></a>'  + CloseButtonHTML;
var UpButtonHTML = '<a href="javascript:setState__(2)" onMouseOver="window.status=\''+UpButtonAlt+'\';return true" onMouseOut="window.status=\'\';return true"><img src="'+UpButton+'" width=16 height=16 alt="'+UpButtonAlt+'" border=0></a>' + CloseButtonHTML;
var Part1 = '<table border=0 cellspacing=0 cellpadding=0 bgcolor=black width='+186+'><tr><td height=1 bgcolor=#9A9A9A>';
var Part2 = '<table border=0 cellspacing=0 cellpadding=0 bgcolor=#34114A width='+186+'><tr><td align=left><img src="'+TopImgFile+'" width=88 height=16 alt="'+TopImgAlt+'" border=0></td><td align=right>';
var Part3 = '</td><table border=0 cellspacing=0 cellpadding=0 width=186><tr><td bgcolor=#662985 align=center><a href="'+URL+'" target=_top><img src="'+ImgFile+'" width='+Width+' height='+Height+' border=0 alt="'+ALT+'"></A><br></td></tr><tr></td><td bgcolor='+DownBgcolor+' height=12 align=center><a href="javascript:setState__(2)" onMouseOver="window.status=\'Развернуть\';return true" onMouseOut="window.status=\'\';return true"><img src="'+TurnOnButton+'" width=88 height=16 alt="'+TurOnButtonAlt+'" border=0></a><br></td></tr></table></td></tr></table>';
var Part4 = '<tr><td><table border=0 cellspacing=0 cellpadding=0 width=186><tr><td bgcolor=#662985 align=center><a href="'+URL+'" target=_top><img src="'+ImgFile+'" width='+Width+' height='+Height+' border=0 alt="'+ALT+'"></A></td></tr><tr><td bgcolor=#662985 align=center>'+Shops+'</td></tr><tr></td><td bgcolor='+DownBgcolor+' height=12 align=center><a href="javascript:setState__(1)" onMouseOver="window.status=\'Свернуть\';return true" onMouseOut="window.status=\'\';return true"><img src="'+TurnOffButton+'" width=88 height=16 alt="'+TurnOffButtonAlt+'" border=0></a><br></td></tr></table></td></tr></table>';
var GlobalWidth = 186;
var GlobalHeight = 400;
var DisplayType = 2;
var timeOut = 90000;
var timeOut1 = 90000;
var allowStayOnTop = true;
var confirm = allowStayOnTop;
var touched = false;

function is__()
{
 this.n=(document.layers)?true:false;
 this.o=(navigator.userAgent.indexOf('Opera')!=-1)?true:false;
 this.i=(document.all&&(!this.o))?true:false;
 this.d=(document.getElementById)?true:false;
}
var is=new is__();
function stor__()
{
	if(is.n&&(top.frames.length>0))
		return top.frames[0];
	else
		return top;
}
var st__=stor__();
me__=_s=_won=_n=0;

w__=document.body.clientWidth;
h__=document.body.clientHeight;

function met__(e,x,y)
{
 if(is.n) e.moveTo(x,y);
 else if(is.i) {
  e.style.pixelLeft=x;
  e.style.pixelTop=y;
 } else {
  e.style.left=x;
  e.style.top=y;
 }
}

var p1__;
var p2__;
var t__;
var closed__ = false;

function write__()
{
	document.writeln('<div style="position:absolute;left:0;top:0;visibility: hidden;" id=part1__>'+
		Part2+UpButtonHTML+'</div>');
	document.writeln('<div style="position:absolute;left:0;top:0;visibility: hidden;" id=part2__>'+
		Part1+Part2+DownButtonHTML+Part3+'</div>');
	document.writeln('<div style="position:absolute;left:0;top:0;visibility: hidden;" id=turn__>'+
		Part1+Part2+DownButtonHTML+Part4+'</div>');

	if(is.i)
	{
		p1__=document.all.part1__;
		p2__=document.all.part2__;
		t__=document.all.turn__;
	}else
	{
		p1__=document.getElementById('part1__');
		p2__=document.getElementById('part2__');
		t__=document.getElementById('turn__');
	}
	move__();
}

function sev__(e, v)
{
	if(is.n) e.visibility=v;
	else if(e.style) e.style.visibility=v;
}

function setState__(n)
{
	h = 'hidden';
	v = 'visible';
	if(n==-1)
	{
		sev__(p1__,h);sev__(p2__,h);sev__(t__,h);
		closed__=true;
	}
	if(n==0)
	{
		sev__(p1__,v);sev__(p2__,h);sev__(t__,h);
	}
	if(n==1)
	{
		sev__(p1__,h);sev__(p2__,v);sev__(t__,h);
	}
	if(n==2)
	{
		sev__(p1__,h);sev__(p2__,h);sev__(t__,v);
	}
}

function move__()
{
	if(closed__) return;
	x = document.body.scrollLeft+w__-GlobalWidth-1;
	met__(p1__,x,0);
	met__(p2__,x,0);
	met__(t__,x,0);
}

function stayOnTop__() 
{
	if(closed__) return;
	if (!touched) timer2 = setTimeout("setState__(-1);", timeOut1);
	if (!allowStayOnTop) return false;
	x = document.body.scrollLeft+w__-GlobalWidth-1;
	y = document.body.scrollTop;
	met__(p1__,x,y);
	met__(p2__,x,y);
	met__(t__,x,y);
	setTimeout("stayOnTop__()", 100);
	return true;
}

function begin__()
{
	setState__(1);
	if(is.i) 
		window.onresize=move__;
	else 
		addEventListener("resize",move__,false);
	
	if (allowStayOnTop) stayOnTop__()
	else setTimeout("setState__(-1);", timeOut);
}

function wait__()
{
	if(top.frames.length>st__._n)
	{
		setTimeout("self.wait__()", 1000);
		return;
	}
	
	if(self.me__==st__._won) begin__();
}

function start__()
{
	w=w__;
	h=h__;
	if (w<GlobalWidth || h<GlobalHeight) return;
	write__();
	if(!DisplayType)
		{if (w<MinWidth) return false;}
	else
	if(DisplayType==1 && top.frames.length>0)
	{
		if(is.i) 
		{
			if(st__._n==null) 
				st__._s=st__._won=st__._n=0;
		} 
		else 
		{
			if(isNaN(st__._n)) 
				st__._s=st__._won=st__._n=0;
		}
		
		self._s=w*h;
		if(self._s>st__._s)
		{
			st__._s=self._s;
			self.me__ = st__._won = ++st__._n;
		}
		else
			self.me__ = ++st__._n;

		setTimeout("self.wait__()", 1000);
		return;
	}

	begin__();
}

if(!is.n)start__();
