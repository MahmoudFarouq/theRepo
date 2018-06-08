var Node = function (value) 
{
    this.left = null;
    this.right = null;
    this.value = value;
	this.balance = 0;
	this.pos = createVector(screen.width/2, 0);
	this.newPos = createVector(0, 0);
	this.setPos = function(vec){
	    this.newPos.x = vec.x; this.newPos.y = vec.y;
	}
	this.display = function(){
	    if(this.left != null){
	        stroke("#FF33CC");
			strokeWeight(2);
	        line(this.pos.x, this.pos.y, this.left.pos.x, this.left.pos.y);
	        this.left.display();
	    }
	    if(this.right != null){
	        stroke("#FF33CC");
			strokeWeight(2);
	        line(this.pos.x, this.pos.y, this.right.pos.x, this.right.pos.y);
	        this.right.display();
	    }
	    fill("#53D9F5");
		noStroke();
	    ellipse(this.pos.x, this.pos.y, 40, 40);
	    fill("#003366");
	    text(this.value, this.pos.x-6, this.pos.y+2)
		noStroke();
	    this.update();
	}
	this.update = function(){
	    if(Math.abs(this.pos.x - this.newPos.x)  < 3 && Math.abs(this.pos.y - this.newPos.y) < 3)
	        return;
	    var direction = p5.Vector.sub(this.newPos, this.pos);
	    var moveDir = direction.normalize();
		moveDir = moveDir.mult(5);
	    this.pos.add(moveDir);
	}
};