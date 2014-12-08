<?php get_header() ?>

<div id="content_index">
<!-- #ici code -->
	<div class="jumbotron">
		<div class="container">
        	<h1 id="tagline" class="uppercase text-jumbo text-contrast row-space-1">BIENVENUE À LA MAISON</h1>
        	<p>Louez des logements uniques auprès d'hôtes locaux dans 190+ pays.</p>
        	<a href="http://wp.local.42.fr:8080/?page_id=6">Mode d'Emploi</a>
        	<div id="blocsearch"> 
        		<?php include('searchform.php'); ?>
        	</div>
      	</div>
	</div>
</div>	
	<div class="neighborhood-guides">
        <div class="container">
            <h2>Juste pour le Weekend</h2>
            <p>Découvrez de nouveaux lieux inspirants près de chez vous.</p>
            <div class="row">
                <div class="col-md-4">
                  <div class="thumbnail">
                    <a href="#" title="Bruxelles">
                    	<img src="<?php bloginfo('template_directory'); ?>/images/Bruxelles.jpg">
                    </a>
                  </div>
                </div>
                <div class="col-md-4">
                  <div class= "thumbnail">
                  	<a href="#" title="Londres">
                    	<img src="<?php bloginfo('template_directory'); ?>/images/Londres.jpg">
                    </a>
                  </div>
                </div>
                <div class="col-md-4">
                  <div class= "thumbnail">
                   	<a href="#" title="Strasbourg">
                    	<img src="<?php bloginfo('template_directory'); ?>/images/Strasbourg.jpg">
                   </a>
                  </div>
                </div>
            </div>
        </div>
    </div>
<?php get_footer() ?>
