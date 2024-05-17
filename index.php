<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <script type="text/javascript" src="jquery/jquery.min.js"></script>
    <title>Realtime Web Sensor</title>
    <script type="text/javascript">
        $(document).ready(function() {
            setInterval(function() {
                $('#check_sensor_SM').load('ceksensor_Soil.php')
            }, 1000);

            $(".btn-primary").click(function() {
                var button = $(this);
                if (button.text() === "Turn on") {
                    button.text("Turn off");
                } else {
                    button.text("Turn on");
                }
            });
        });
    </script>
</head>

<body>
    <div class="container" style="text-align: center; padding-top: 10%; width: 500px">
        <h2>Kelembaban tanah</h2>
        <div class="panel panel-default">
            <div class="panel-body">
                <h1> <span id="check_sensor_SM"></span></h1>
            </div>
        </div>
    </div>
    <div class="container" style="text-align: center; padding-top: 10%; width: 500px">
        <h2>Pompa air</h2>
        <button type="button" class="btn btn-primary">Turn on</button>
    </div>
</body>

</html>