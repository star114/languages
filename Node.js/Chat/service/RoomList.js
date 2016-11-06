/**
 *  RoomList.js
 *  author - star114
 */


app.get('/roomlist', function(req, res) {
	res.header("Access-Control-Allow-Origin", "*");
	res.header("Access-Control-Allow-Headers", "X-Requested-With");
	res.send({"roomdata": io.sockets.adapter.rooms, "clientid":"", "nickname":"", "roomname":roomnames});
});
