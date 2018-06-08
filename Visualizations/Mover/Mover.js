var Mover = function(maxSpeed)
{
    this.location     = createVector(random(width), random(height));
    this.velocity     = createVector(0,0);
    this.acceleration = createVector(0,0);

    this.update = function()
    {
        mouse = createVector(mouseX, mouseY);
        dir   = p5.Vector.sub(mouse, this.location);
        dir.normalize();
        this.acceleration = dir;
        
        this.location.add(this.velocity);
        this.velocity.add(this.acceleration);
        this.velocity.limit(maxSpeed);
        
        this.checkEdges();
    }
    this.display = function()
    {
        fill(random(255));
        push();
        rectMode(CENTER)
        translate(this.location.x, this.location.y);
        angle = radians(-90) + this.velocity.heading(); //atan2(this.velocity.y,this.velocity.x);
        rotate(angle);
        triangle(0,0,-25,-25,25,-25);
        pop();
    }
    this.checkEdges = function()
    {
        if( this.location.x < 0){
            this.location.x = width;
        }
        if( this.location.x > width){
            this.location.x = 0;
        }
        if( this.location.y < 0 ){
            this.location.y = height;
        }
        if( this.location.y > height){
            this.location.y = 0;
        }
    }
}