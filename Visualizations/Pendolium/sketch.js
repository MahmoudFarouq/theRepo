function setup()
{
    createCanvas(640, 460);
    stroke(255);
    
    len = 150;
    origin = createVector(width/2, 0);
    bob    = createVector(width/2, len);
    
    G     = 1;
    angle = PI/4;
    aVel  = 0.0;
    aAcc  = 0.0;
}

function draw()
{
    background(51);
    
    bob.x = origin.x+len*cos(radians(90)+angle);
    bob.y = origin.y+len*sin(radians(90)+angle);
    
    line(origin.x, origin.y, bob.x, bob.y);
    ellipse(bob.x, bob.y, 25, 25);
    
    aAcc = -1*(G/len)*sin(angle);
    
    aVel  += aAcc;
    angle += aVel;
    
    aVel *= 0.99;
    
}













