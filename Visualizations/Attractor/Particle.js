function Particle(mass, Xpos, Ypos)
{
	this.pos = createVector(Xpos, Ypos);
	this.vel = createVector(1, 0);
	this.acc = createVector(0, 0);
	this.mass = mass;

	this.update = function() 
	{
	    this.vel.add(this.acc);
	    this.pos.add(this.vel);
	    this.acc.mult(0);
  	};

  	this.display = function() 
  	{
		stroke(0);
		strokeWeight(2);
		fill(255, 127);
		ellipse(this.pos.x, this.pos.y, this.mass*20, this.mass*20);
  	};
  	
	this.applyForce = function(force) 
	{
	    var f = force.copy();
	    f.div(this.mass);
	    this.acc.add(f);
  };
}