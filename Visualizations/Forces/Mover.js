
function Mover(m, x, y)
{
    this.mass           = m;
    this.location       = createVector(x, y);
    this.velocity       = createVector(0, 0);
    this.acceleration   = createVector(0, 0);


    this.update = function(){
        this.velocity.add(this.acceleration);
        this.location.add(this.velocity);
        this.acceleration.mult(0);
        this.checkEdges();
    }
    this.display = function()
    {
        stroke(0);
        ellipse(this.location.x, this.location.y, this.mass*10, this.mass*10);
    }
    this.checkEdges = function()
    {
        if( this.location.x < 0){
            this.location.x = 0;
            this.velocity.x *= -1;
        }
        if( this.location.x > width){
            this.location.x = width;
            this.velocity.x *= -1;
        }
        if( this.location.y > height){
            this.location.y = height;
            this.velocity.y *= -1;
        }
    }
    /* Net Force equals mass times acceleration. */
    this.applyForce = function(force){
        //Copy of force Vector
        f = force.copy();
        // A = F/M;
        f.div(this.mass);
        //force accumulation: not F = A*M, its F = sum(A)*M;
        this.acceleration.add(f);
    }
    //Friction = mu * N * V(unit vector)
    this.Friction = function(){
        vel = this.velocity.copy();
        v = vel.normalize();
        v.mult(-1);
        
        mu = 0.01;   //coefficient of friction
        N = 1;       //normal force
        
        this.friction = v.mult(mu*N);
    }
    
    //Drag Force = (-0.5) * rho * v^2 * A * C_d * V(unit vector);
    this.DragForce = function(l){
        // SimplyFied F_d = v^2 * c_d * V(unit vector) * -1
        
        vel = this.velocity.copy(l); //l => Liquid
        v = vel.normalize();
        v.mult(-1);

        rho = l.rho;           //coefficient of Drag
        speed = v.mag();       //speed of object
        
        this.dragForce = v.mult(rho*speed*speed);
        
        this.applyForce(this.dragForce);
    }
    
    this.isInside = function(l) {
        if (this.location.x > l.x && this.location.x < l.x+l.w
         && this.location.y > l.y && this.location.y < l.y+l.h)
        {
            return true;
        } else {
            return false;
        }
    }
    
}
function Liquid(x_, y_, w_, h_, c_)
{
    this.x = x_;
    this.y = y_;
    this.w = w_;
    this.h = h_;
    this.rho = c_;

    this.display = function() {
        noStroke();
        fill(175);
        rect(this.x,this.y,this.w,this.h);
    }
}



