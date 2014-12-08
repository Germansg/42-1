<form id="searchform" method="get" action="<?php echo $_SERVER['PHP_SELF']; ?>">
	<input type="text" value="<?php _e("Recherchez ici..."); ?>" name="s" id="searchbox" onfocus="if (this.value == '<?php _e("Faites ici votre recherche"); ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e("Faites ici votre recherche"); ?>';}" />
	<input type="submit" id="searchsubmit" value="<?php _e("Rechercher"); ?>"/>
</form>
