<?php

	function ft_is_sort($tab)
	{
		$tmp = $tab;
		sort($tab);
		if ($tmp === $tab)
			return(1);
		else
			return(0);
	}
?>
