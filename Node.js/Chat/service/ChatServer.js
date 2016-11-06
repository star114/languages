/**
 * ChatServer.js
 * author - star114
 */
var numOfRooms = 0;

io.use(function(socket, next) {
	  var handshakeData = socket.request;
	  // make sure the handshake data looks good as before
	  // if error do this:
	    // next(new Error('not authorized');
	  // else just call next
	  next();
	});

io.sockets.on('connection', function(socket) {
	console.log('a user connected');
	socket.on('roommake', function(data) {
		console.log("roomname : " + data.roomname + ", nickname : " + data.nickname);
		socket.join(data.roomname);
		
		// Manage Global Data
		// each socket.id can be participated in one chat room.
		//if (undefined == participated[socket.id])
		//	participated[socket.id] = new Array(); 
		participated[socket.id] = data.roomname;
		
		//if (undefined == roomnames[data.roomname])
		//	roomnames[data.roomname] = new Array(); 
		//roomnames[data.roomname].push(socket.id);
		if (undefined == roomnames[data.roomname])
			roomnames[data.roomname] = 0;
		roomnames[data.roomname]++;
		nicknames[socket.id] = data.nickname;
		
		// add the client's roomname and username to the global list
		//numOfRooms++;
		// 방목록 전송
		io.sockets.emit('roomlist', {"roomdata": io.sockets.adapter.rooms, "clientid":socket.id, "nickname":data.nickname, "roomname":roomnames});
		io.sockets.in(data.roomname).emit('intro', data.nickname);
	});
	socket.on('message', function(data) {
		io.sockets.in(participated[socket.id]).emit('message_send', {'msg':data.msg, 'from':nicknames[socket.id]});
	});
	socket.on('disconnect', function() {
		console.log('a user disconnected');
		// 방목록 전송
		if (undefined != participated[socket.id]) {
			io.sockets.in(participated[socket.id]).emit('message_send_disconnect', {'msg':'', 'from':nicknames[socket.id], 'clientid':socket.id, 'count':roomnames[participated[socket.id]]});

			roomnames[participated[socket.id]]--;
			if (0 == roomnames[participated[socket.id]])
				roomnames[participated[socket.id]] = undefined;
			nicknames[socket.id] = undefined;
			participated[socket.id] = undefined;
		}
		else {
			console.log('not participated in chat room');
		}
	});
	socket.on('leave', function() {
		console.log('leave from the room');
		// 방목록 전송
		if (undefined != participated[socket.id]) {
			io.sockets.in(participated[socket.id]).emit('message_send_disconnect', {'msg':'', 'from':nicknames[socket.id], 'clientid':socket.id, 'count':roomnames[participated[socket.id]]});

			for (var sid in io.sockets.adapter.rooms[participated[socket.id]])
			{
				if (sid == socket.id)
					delete io.sockets.adapter.rooms[participated[socket.id]][sid];	
			}
			socket.leave(roomnames[participated[socket.id]]);
			roomnames[participated[socket.id]]--;
			if (0 == roomnames[participated[socket.id]])
				roomnames[participated[socket.id]] = undefined;
			nicknames[socket.id] = undefined;
			participated[socket.id] = undefined;
			
			socket.emit('room_research', null);	
		}
		else {
			console.log('not participated in chat room');
		}
	});
	
});