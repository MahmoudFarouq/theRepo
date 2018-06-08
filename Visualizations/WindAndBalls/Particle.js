function Particle(mass, Xpos)
{
	this.pos = createVector(Xpos, 100);
	this.vel = createVector(0, 0);
	this.acc = createVector(0, 0);
	this.mass = mass;

	this.update = function()
	{
		this.pos = this.pos.add(this.vel);
		this.vel = this.vel.add(this.acc);
		this.edges();
		this.mouseInput();
		
		
		this.acc.set(0, 0);			//setting the acceleration to 0, because acc can't, or at least here is "sor3a sabta"
	}
	this.display = function()
	{
		fill(255);
		noStroke();
		ellipse(this.pos.x, this.pos.y, this.mass*50,this.mass*50);
	}
	this.applyForce = function(force)
	{
		force = force.div(this.mass);
		this.acc.add(force);
	}
	this.edges = function()
	{
		if(this.pos.y > height)
		{
			this.vel.y *= -1;
			this.pos.y = height;
			this.vel.mult(0.9);
		}
		if(this.pos.x > width)
		{
			this.vel.x *= -1;
			this.pos.x = width;
		}
		if(this.pos.y <= 0) {this.pos.y = 0;this.vel.y *= -1;}
		if(this.pos.x <= 0) {this.pos.x = 0;this.vel.x *= -1;}
	}
	this.mouseInput = function()
	{
		if(mouseIsPressed)
		{
			this.vel = this.vel.add(0.2);
		}
	}
}