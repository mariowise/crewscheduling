<html>
	<head>
		<title>Resultado</title>

		<link rel="stylesheet" href="/css/style.css">
		<script type="text/javascript" src="/js/jquery.js"></script>
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
							<div id="services"></div>
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
			var service = { id: '5', partialFitness: 0, remainingRest: '0:0', tripList: [{ id: 0, line: 'L2', initTime: '6:30', initStation: 0, endTime: '7:30', endStation: 1 }, { id: 1, line: 'L5', initTime: '9:40', initStation: 1, endTime: '10:50', endStation: 2 }, { id: 2, line: 'L2', initTime: '12:0', initStation: 3, endTime: '13:34', endStation: 0 }], restList: [], time: { id: '105', type: 'lunch', initTime: '7:33', endTime: '9:3' } }
			var totalWidth = $('#services').width()
			
			$(service.tripList).each(function (index, elem) {
				var newOne = $('<div></div>')
					newOne.html(elem.id)
					.appendTo('#services')

				
			})
		</script>
	</body>
</html>