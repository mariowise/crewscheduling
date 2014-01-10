<html>
	<head>
		<title>Resultado</title>

		<link rel="stylesheet" href="/css/style.css">
		<script type="text/javascript" src="/js/jquery.js"></script>
		<script type="text/javascript" src="/js/rawData.js"></script>
	</head>
	<body>
		<div class="wrapper">
			<header>
				<div class="container">
					<div class="row">
						<div class="col-xs-12">
							<h2>Resultado del Crew Scheduling Problem - Services Assignament</h2>
							<p>This shows a solution for the assignament between Trips (Tasks) and Services.</p>
						</div>
					</div>
				</div>
			</header>
			<section>
				<div class="container">
					<div class="row">
						<div class="col-xs-12">
							<?php /*
							<form action="/" method="post">
								<textarea name="problem" id="" rows="10" style="width: 100%"></textarea>
								<input type="submit" value="Solve">
							</form>
							<div>
								<?php if(isset($_POST['problem'])) : ?>

									<?php echo $_POST['problem']; ?>

								<?php endif; ?>
							</div>
							*/?>
							<div id="services">
								
							</div>
						</div>
					</div>
				</div>
			</section>
			<div class="footer-ghost"></div>
			<footer>
				<div class="container">
					<div class="row">
						
					</div>
				</div>
			</footer>
		</div>

		<script type="text/javascript">
			var service = rawData
			var tw = $('#services').width()
			
			$(service).each(function (index, elem1) {
				var newOne = $('<div></div>')
					newOne.html(elem1.id)
						.addClass('service')
					.appendTo('#services')

				$(elem1.blocks).each(function (index, elem2) {
					setTimeout(function () {
					if(index == 0) {
						var offset = $('<div></div>')
							offset
								.addClass('offset')
								.css('width', (elem2.offset / 86400)*(tw -100) + 'px')
								.appendTo($(newOne))
					}

					var newBlock = $('<div></div>')
						newBlock.html(elem2.id)
							.addClass('block')
							.addClass(elem2.type)
							.attr('initTime', elem2.initTime)
							.attr('endTime', elem2.endTime)
							.css('width', (elem2.width / (86400))*(tw -100) + 'px')
						.appendTo($(newOne))

					switch(elem2.type) {
						case "Trip":
							$(newBlock).attr('id', 'trip-' + elem2.id)
							$(newBlock).attr('title', 'c: ' + elem2.driving + ' - cc: ' + elem2.continuousDriving)
							break;
						case "Rest":
							$(newBlock).html('R')
							break;
						case "Lunch":
							$(newBlock).html('L')
							break;
						case "Fat":
							$(newBlock).html('')
							break;
						case "Leisure":
							$(newBlock).html('Oc')
							break;
					}

					$(newBlock).fadeIn(250)
					$(newBlock).css('display', 'inline-block')
					}, 250 * index)
				})
			})
		</script>
	</body>
</html>