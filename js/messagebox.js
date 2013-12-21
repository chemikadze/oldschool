function showTextMessage()
{
	var caption = "Message!";
	var text = document.getElementById('textInput').value;
	showMessageBox(caption, text);
}

function showMessageBox(titleStr, textStr)
{
	var buf = document.createElement('div');
	buf.innerHTML = "<div class=\"messageBox\">" +
						"<div class=\"messageBoxHeader\">" + titleStr + "</div>" +
						textStr +
						"<br/><center><input class=\"messageBoxOkButton\" type=\"button\" value=\"Ok\"></center>" +
					"</div>";
	
	var msgBox = buf.firstChild;

	msgBox.style.position = 'absolute';
	msgBox.height = 100;
	msgBox.width = 200;
	var scroll = document.documentElement.scrollTop || document.body.scrollTop
	msgBox.style.top = scroll + Math.floor((document.getElementsByTagName('body')[0].clientHeight-msgBox.height)/2) + 'px';
	msgBox.style.left= Math.floor((document.body.clientWidth-msgBox.width)/2) + 'px';

	msgBox.getElementsByTagName('input')[0].onclick = function() 
	{
		msgBox.parentNode.removeChild(msgBox);
	}

	document.body.appendChild(msgBox);
}
