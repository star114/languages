/**
 * board.js
 * author - star114
 */

var color_map =
[
 {'value':'white', 'name':'white'},
 {'value':'red', 'name':'red'},
 {'value':'orange', 'name':'orange'},
 {'value':'yellow', 'name':'yellow'},
 {'value':'blue', 'name':'blue'},
 {'value':'black', 'name':'black'}
];

var socket;

var mapObj= {
	x : 37.537123,
	y : 127.005523,
	z : 3,
	init : function() {
		if (map == undefined || $('#map').css('display') == 'none') {
			$('#map').css('display', 'block');
			
			console.log(mapObj.x + " " + mapObj.y);
			map = new daum.maps.Map(document.getElementById('map'), {center: new daum.maps.LatLng(mapObj.x,mapObj.y), level : mapObj.z});
			
			daum.maps.event.addListener(map, 'dragend', function() {
				mapObj.x = map.getCenter().getLat();
				mapObj.y = map.getCenter().getLng();
				socket.emit('map', {'type' : 'mapmove', 'x':mapObj.x, 'y':mapObj.y});
				console.log('dragend ' + map.getCenter());
			});
			daum.maps.event.addListener(map, 'zoom_changed', function() {
				mapObj.z = map.getLevel();
				socket.emit('map', {'type' : 'zoom', 'z':mapObj.z});
				console.log('zoom ' + mapObj.z);
			});
			
			socket.emit('map', {'type':'open', 'x':mapObj.x, 'y':mapObj.y});

			$('#btn_roadview, #btn_roadview_close').show();
		}
	},
	close : function() {
		if ($('#map').css('display') == 'block') {
			$('#map').css('display', 'none');
			
			socket.emit('map', {'type':'close'});

			$('#btn_roadview, #btn_roadview_close').hide();
		}
	},
	drawfromServer : function(data) {
		if (data.type == 'open'){
			mapObj.x = data.x;
			mapObj.y = data.y;
			mapObj.init();
		}
		else if ( data.type == 'close') {
			mapObj.close();
		}
		else if ( data.type == 'mapmove') {
			mapObj.mapMove(data.x, data.y);
		}
		else if ( data.type == 'zoom') {
			mapObj.setZoom(data.z);
		}
		else if ( data.type == 'roadviewopen') {
			mapObj.x = data.x;
			mapObj.y = data.y;
			mapObj.roadview();
		}
		else if ( data.type == 'roadviewclose') {
			mapObj.roadviewClose();
		}
	},
	mapMove : function(x, y) {
		mapObj.x = x;
		mapObj.y = y;
		map.panTo(new daum.maps.LatLng(x, y));
	},
	setZoom : function(z){
		mapObj.z = z;
		map.setLevel(z);
	},
	roadview : function() {
		if ($('#roadview').css('display') == 'none') {
			
			socket.emit('map', {'type':'roadviewopen', 'x':mapObj.x, 'y':mapObj.y});
			
			$('#map').css('display', 'none');
			$('#roadview').css('display', 'block');
			
			var p = new daum.maps.LatLng(mapObj.x, mapObj.y);
			var rc = new daum.maps.RoadviewClient();
			var rv = new daum.maps.Roadview(document.getElementById('roadview'));
			
			$('#roadview').css('position', 'absolute');
			
			rc.getNearestPanoId(p, 50, function(panoid) {
				rv.setPanoId(panoid);
			});
		}
	},
	roadviewClose : function() {
		if ($('#roadview').css('display') == 'block') {
			
			socket.emit('map', {'type':'roadviewclose'});
			
			$('#roadview').css('display', 'none');
			$('#map').css('display', 'block');
		}
	}
};