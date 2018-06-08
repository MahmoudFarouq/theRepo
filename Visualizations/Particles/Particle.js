function Particle(l)
{
    this.location     = l.copy();
    this.acceleration = createVector(0, 0);
    this.velocity     = createVector(0, 0);
    this.lifeSpan     = 255;
    this.mass         = 1;
    
    
    this.isDead = function(){
        if (this.lifeSpan < 0.0) {
            return true;
        } else {
            return false;
        }
    }
    
    this.applyForce = function(force){
        f = force.copy();
        f.div(this.mass);
        this.acceleration.add(f);
    }
    
    this.run = function(){
        this.update();
        this.display();
    }
    this.update = function() {
        this.velocity.add(this.acceleration);
        this.location.add(this.velocity);
        this.lifeSpan-=1;
        //this.acceleration.mult(0);
    }
    this.display = function() {
        stroke(random(255), random(255), random(255), this.lifespan);
        fill(random(255), random(255), random(255), this.lifeSpan);
        
        push();
        translate(this.location.x, this.location.y);
        rotate(radians(90)+this.velocity.heading());
        triangle(0  , 0,-25, 50,+25, 50);
        pop();
    }
}