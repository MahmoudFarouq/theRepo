function setup() 
{
    createCanvas(800, 800);
    background(51);
    strokeWeight(2);
    stroke(255);
}

function draw() 
{
    translate(width/2, height/2);
    
    push();
    
    DrawCanvas(0, 0, 1);
    
    pop();
    noLoop();

}

function DrawCanvas(x, y, gen)
{
    translate(x, y);
    if(gen > 3)
        return;
    
    push();
    translate(50, 50);
    DrawBasicShape(0);
    pop();
    
    push();
    translate(50, -50);
    DrawBasicShape(0);
    pop();
    
    push();
    translate(-50, 50);
    DrawBasicShape(0);
    pop();
    
    push();
    translate(-50, -50);
    DrawBasicShape(0);
    pop();
    
    push();
    DrawCanvas(100,  100, gen+1);
    pop();
    push();
    DrawCanvas(100, -100, gen+1);
    pop();
    push();
    DrawCanvas(-100, 100, gen+1);
    pop();
    push();
    DrawCanvas(-100, -100, gen+1);
    pop();
}


function DrawBasicShape(angle)
{
    if(angle == 360)
        return;
    rotate( radians(angle) );       //angle*PI/180
    line(0, 30, 25, -30);
    line(0, 30, -25, -30);
    line(25, -30, 0, -55);
    line(-25, -30, 0, -55);
    DrawBasicShape(angle+45);
}



