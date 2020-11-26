// Javascipt to retrieve input file in Gavel Graph creator
function loadBenchmark(text){
	// Make ajax request to send input text to flask
	$.ajax({
  		type : 'POST',
  		url : "/graph",
  		contentType: "application/json; charset=utf-8",
  		data : JSON.stringify({'data': text}), // Send data as JSON variable
		dataType: "json",
		success:function(data) {
			if(data.redirect)
			{
				window.location.href = data.redirect; // On success redirect to url sent by flask function
				return false;
			}
	 	 }
		  
	});
}

