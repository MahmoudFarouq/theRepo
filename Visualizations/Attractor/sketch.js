var attractor;
var particle;

function setup() 
{
	createCanvas(640, 580);
	attractor = new Attractor();
	particle  = new Particle (1, 200, 100);
}

function draw() 
{
	background(51);
	attractor.display();
	
	var force = attractor.calculateAttraction(particle);
	particle.applyForce(force);
	
	
	particle.update();
	particle.display();
}