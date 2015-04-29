var data = '';

$(document).ready(function()
{
	if ($.cookie("ft_list"))
		initElem();
});

function initElem()
{
	var cookies = $.cookie("ft_list");
	var value = cookies;
	data = value;
	var ntab = value.split(":");
	for (var val in ntab)
	{
		if (ntab[val])
			createElem(unescape(ntab[val]), false);
	}
	return (cookies);
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

function deleteElem(event)
{
	var res = confirm('Are you sure ?');
	if (res)
	{
		var id_del = get_id(event.target);
		var ntab = data.split(":");
		data = '';
		for (var i = 0; i < ntab.length; ++i)
		{
			if (ntab[i] && i != id_del)
				data += ntab[i] + ":";
		}
		var parent = $('#ft_list')[0];
		$(event.target).remove();
		$.cookie("ft_list", data, { expires : 30 });
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
	{
		data += escape(text) + ":";
		$.cookie("ft_list", data, { expires : 30 });
	}
}

function promptUp()
{
	var val = prompt("Quel 'to do' voulez-vous ajouter ?:", "")
	if (val != '')
		createElem(val, true);
}
