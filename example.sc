//objects: camera,light,sphere,cylinder,cone,plane
//syntax: type: val1x,val1y,val1z val2 val3 ...
//camera: position(x3float x,y,z) direction(x3float x,y,z)
camera: 0,0,0 0,0,1
//light: position(x3float x,y,z) spec_color(x3int r,g,b) intensity(float, 0.1..0.9 total) spec_power(int)
light: 299,-10,299 255,255,255 0.3 24
light: 10,200,200 255,255,255 0.6 12
//sphere: position(x3float x,y,z) color(x3int r,g,b) radius(float)
//sphere: -100,0,500 255,0,0 100
//sphere: 100,40,400 0,255,0 30
sphere: -100,90,400 0,0,255 30
sphere: 30,100,30 0,0,255 30
sphere: 0,-100,0 0,255,0 30
sphere: -70,-100,600 100,255,255 50
cylinder position(x3float x,y,z) color(x3int r,g,b) axis(x3float x,y,z) radius(float)
cylinder: -50,20,400 255,0,0 0,1,0 10
cone position(x3float x,y,z) color(x3int r,g,b) axis(x3float x,y,z) radius(float)
cone: 50,20,400 255,0,255 0,1,0 0.3
//plane position(x3float x,y,z) color(x3int r,g,b) direction(x3float x,y,z)
//box
plane: 0,300,0 0,0,255 0,-1,0
plane: 0,-300,0 0,255,0 0,1,0
plane: 300,0,0 255,0,0 -1,0,0
plane: -300,0,0 0,0,255 1,0,0
plane: 0,0,700 0,255,0 0,0,-1
plane: 0,0,-700 255,0,0 0,0,1
