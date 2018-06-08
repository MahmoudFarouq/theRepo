var particle1;
var particle2;
var windObj = [];

function setup() 
{
	createCanvas(650, 540);
	particle1 = new Particle(1, width/2);
	particle2 = new Particle(2, width/2+200);
	
	for(i = 0; i < height; i++)
	{
		windObj[i]  = new Wind(i, i*2);
	}
}

function draw() 
{
	background(51);
	
	var gravity = createVector(0, 0.1);
	var wind    = createVector(0.1, 0);
	
	
	particle1.update();
	particle1.display();
	particle1.applyForce(gravity.mult(particle1.mass));
	particle1.applyForce(wind);
	
	particle2.update();
	particle2.display();
	particle2.applyForce(gravity.mult(particle2.mass));
	particle2.applyForce(wind);
	
	stroke(255);
	line(particle1.pos.x,particle1.pos.y,particle2.pos.x,particle2.pos.y);
	line(particle1.pos.x,particle1.pos.y-25,particle2.pos.x,particle2.pos.y+50);
	line(particle1.pos.x,particle1.pos.y+25,particle2.pos.x,particle2.pos.y-50);
	
	for(i = 0; i < height; i++)
	{
		windObj[i].update();
		windObj[i].display();
	}

}