function Wind(Xpos, Ypos)
{
	this.pos = createVector(Xpos, Ypos);
	this.vel = createVector(random(4, 6), 0);

	this.update = function()
	{
		this.pos = this.pos.add(this.vel);
		this.edges();
		this.mouseInput();
	}
	this.display = function()
	{
		fill(255);
		noStroke();
		ellipse(this.pos.x, this.pos.y, 5,5);
	}
	this.edges = function()
	{
		if(this.pos.x > width)
		{
			this.pos.x = 0;
		}
	}
	this.mouseInput = function()
	{
		if(mouseIsPressed)
		{
			this.vel = this.vel.mult(1.2);
		}
	}
}