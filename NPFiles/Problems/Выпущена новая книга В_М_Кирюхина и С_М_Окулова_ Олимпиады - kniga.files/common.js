function PopupPic(name, descr, id, width, height){
  var left=screen.width/2-width/2;
  var top=screen.height/2-height/2;
  var wnd = window.open("/popuppic.asp?name="+name+"&descr="+descr+"&id="+id, "","left="+left+",top="+top+",width="+width+",height="+height+",resizable=0,status=0,scrollbars=0");
  if(wnd)
    wnd.focus();
}

function PrintPreview(){
  var url = window.location.href;
  if(url.indexOf("?") != -1)
    url = url + "&mode=print"
  else
    url = url + "?mode=print"
  var wnd = window.open( url , "PrintPreview","width=526,height=600,resizable=1,status=0,scrollbars=1");
  if(wnd)
    wnd.focus();
}

function MailLink(){
  var url = window.location.href;
  var title = window.document.title;
  var wnd = window.open("/services/maillink.asp" , "MailLink","width=472,height=501,resizable=1,status=0,scrollbars=1");
  if(wnd)
    wnd.focus();
}

function RemoveLinks(){
  if(window.opener)
    window.opener.name = "top"
  for(i=0; i<document.links.length; i++){
    var lnk = document.links[i].href;
    if(lnk.indexOf("javascript") == -1 && lnk.indexOf("#") == -1){
      document.links[i].target="top";
      document.links[i].onclick = new Function("opener.focus();");
    }
  }
}

var imagesHidden = false;
var images = null;

function HideImages(){
  if(images == null)
    images = new Array(document.images.length);
  var selfpath = document.location.href.split("/");
  for(i=0; i<document.images.length; i++){
    if(!imagesHidden){
      var path = document.images[i].src.split("/");
      if(path.length>5 || path.length==4 || selfpath[2] != path[2]){
        images[i] = document.images[i].src;
        document.images[i].src="/images/blank.gif";
      }  
    }
    else if(images[i] != null){
      document.images[i].src=images[i];
    }
  }
  imagesHidden = !imagesHidden;
  if(imagesHidden)
    document.getElementById("hide").innerText = "Show images"
  else
    document.getElementById("hide").innerText = "Hide images"
}

function GetTitle(){
  if(opener)
    if(opener.document.title)
      this.document.title = opener.document.title;
}


function Toggle(element){
  if(element.tagName == "IMG"){
    var div = element.parentNode.parentNode.parentNode.parentNode.parentNode; //TD->TR->TBODY->TABLE->DIV
    var folder = element.parentNode.nextSibling;
    if(element.src.indexOf("_minus.gif")!=-1){
      element.src = element.src.substring(0, element.src.indexOf("_minus.gif")) + "_plus.gif";
      folder.childNodes.item(0).src = "/images/tree/folder_closed.gif";
      var childs = div.childNodes;
      for(var i=1; i< childs.length; i++){
        if(childs[i].tagName == "DIV"){
          childs[i].style.display = "none";
          childs[i].style.visibility = "hidden";
        }
      }
      div.setAttribute("expanded", "false");
    }
    else{
      element.src = element.src.substring(0, element.src.indexOf("_plus.gif")) + "_minus.gif";
      folder.childNodes.item(0).src = "/images/tree/folder_open.gif";
      var childs = div.childNodes;
      for(var i=1; i< childs.length; i++){
        if(childs[i].tagName == "DIV"){
          childs[i].style.display = "block";
          childs[i].style.visibility = "visible";
        }
      }
      div.setAttribute("expanded", "true");
    }
  }
}

function ExpandVisual(table){
  var img = table.getElementsByTagName("IMG");
  if(img.length >= 2){
    var x = img[img.length-1].src.indexOf("_closed.gif");
    if(x != -1)
      img[img.length-1].src = "/images/tree/folder_open.gif";
    x = img[img.length-2].src.indexOf("_plus.gif");
    if(x != -1)
      img[img.length-2].src = img[img.length-2].src.substring(0, x) + "_minus.gif";
  }
}

function ExpandAll(){
  var rootDiv = document.getElementById("SiteMap");
  if(rootDiv){
    var childs = rootDiv.getElementsByTagName("DIV");
    for(var i=0; i<childs.length; i++){
        if(childs[i].getAttribute("expanded") != "true"){
          ExpandVisual(childs[i].childNodes.item(0));
          childs[i].setAttribute("expanded", "true")
        }
        if(childs[i].parentNode != rootDiv){
          childs[i].style.display="block";
          childs[i].style.visibility = "visible";
        }
    }
  }
}

function CollapseVisual(table){
  var img = table.getElementsByTagName("IMG");
  if(img.length >= 2){
    var x = img[img.length-1].src.indexOf("_open.gif");
    if(x != -1)
      img[img.length-1].src = "/images/tree/folder_closed.gif";
    x = img[img.length-2].src.indexOf("_minus.gif");
    if(x != -1)
      img[img.length-2].src = img[img.length-2].src.substring(0, x) + "_plus.gif";
  }
}

function CollapseAll(){
  var rootDiv = document.getElementById("SiteMap");
  if(rootDiv){
    var childs = rootDiv.getElementsByTagName("DIV");
    for(var i=0; i<childs.length; i++){
        if(childs[i].getAttribute("expanded") == "true"){
          CollapseVisual(childs[i].childNodes.item(0));
          childs[i].setAttribute("expanded", "false")
        }
        if(childs[i].parentNode != rootDiv){
          childs[i].style.display="none";
          childs[i].style.visibility = "hidden";
        }
    }
  }
}


//'===================================================================
//'sub regw
//'Открыть окно
//'url	=	url
//'wname	=	имя окна
//'x		=	ширина
//'y		=	высота
function regw(url,wname,x,y) 
{
wwregw=window.open(url,wname,'toolbar=no,location=no,status=no,menubar=no,scrollbars=yes,width='+x+',height='+y+',resizable=yes');
top.window.wwregw.focus();
};
//'=======================================================================
//'User Info
function uinfo(uid)
{
regw('/forum/uinfo.asp?id='+uid,'user_info',screen.width*0.6,screen.height*0.6);
}

//'=================================================================
//'ввод пароля и передача его в ссылку

function apwd(url,title){
	if (title=='' || title==null) { var title='Введите пароль:'}
	if (isMSIE && !isOpera ) {
		var pwd="";
		var varResult;
		varResult = window.showModalDialog("/forum/pwd.htm",[pwd,title],"dialogHeight:100px; dialogWidth:240px; help=no;status=no");
		if (varResult != null) {
			
		document.location.href=url+escape(varResult[0]);
//		document.location.href=url+escape(pwd);
//		alert(varResult[0]);
		}
	}
	else {
		var newname=prompt(title,'');
		if (newname!=null) {
		document.location.href=url+escape(newname);
		};
		}
}

//'=======================================================================
//'подтвердить удаление

function del_confirm(a){
	if (confirm(' Вы уверены ? ')) {
	document.location.href=a;
	}
};