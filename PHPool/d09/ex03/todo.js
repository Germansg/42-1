var data = '';
var nbr = 0;

$(document).ready(function()
{
		initElem();
});

function initElem()
{
	var tab = select();
	for (var i = 0; i < tab.length; ++i)
	{
		if (tab[i] != '')
		{
			++nbr;
			createElem(unescape(tab[i]), false);
			data += tab[i] + ":";
		}
	}
	return ;
}

function get_id(event)
{
	var div = $('#ft_list')[0];
	var tab = $('div');
	for (var i in tab)
	{
		if (tab[i] == event)
			return ((tab.length - 1) - i);
	}
	return (-1);
}

// 1 mois
function expires()
{
	var d = new Date();
	d.setTime(d.getTime() + (30*24*60*60*1000));
	var expires = "expires="+d.toUTCString();
	return (expires);
}

function deleteElem(event)
{
	var res = confirm('Are you sure ?');
	if (res)
	{
		--nbr;
		var id_del = get_id(event.target);
		var tab = data.split(":");
		data = '';
		for (var i = 0; i < tab.length; ++i)
		{
			if (tab[i] && i != id_del)
				data += tab[i] + ":";
		}
		var parent = $('#ft_list')[0];
		$(event.target).remove();
		delete_(data);
	}
}

function createElem(text, create)
{
	var parent = $('#ft_list')[0];
	var div = $("<div></div>").text(text);
	$(div).click(deleteElem);
	if (parent)
		$(parent).prepend(div, parent.firstChild);
	if (create == true)
		data += escape(text) + ":";
}

function promptUp()
{
	var val = prompt("Quel 'to do' voulez-vous ajouter ?:", "")
	if (val != '')
	{
		createElem(val, true);
		insert(escape(val));
		++nbr;
	}
}

// ------------------ AJAX ------------------- \\

function insert(val)
{
	$.ajax({
	   url : 'insert.php',
	   type : 'GET', 
	   data : 'val=' + val + '&nbr=' + nbr,
	   dataType : 'html'
	});
}

function delete_(val)
{
	$.ajax({
	   url : 'delete.php',
	   type : 'GET', 
	   data : 'val=' + val,
	   dataType : 'html'
	});
}

function select()
{
	var jqXHR = $.ajax({
	   url : 'select.php',
	   async: false,
	   dataType : 'html'
	});
	var tab = jqXHR.responseText.split(":");
	return (tab);
}