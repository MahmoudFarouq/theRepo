function setup() 
{
    createCanvas(640, 640);
    background(51);
    stroke(255);
    strokeWeight(2);
    noFill();
    theta = 1;
    //noLoop();
}

function Circular(gen)
{
    ellipse(0, 0, 150, 150);
    ellipse(0, 0, 300, 300);
    
    ellipse(75, 0, 150, 150);
    ellipse(0, 75, 150, 150);
    ellipse(0, -75, 150, 150);
    ellipse(-75, 0, 150, 150);

    
    ellipse(cos(radians(45 ))*75, sin(radians( 45))*75, 150, 150);
    ellipse(cos(radians(135))*75, sin(radians(135))*75, 150, 150);
    ellipse(cos(radians(225))*75, sin(radians(225))*75, 150, 150);
    ellipse(cos(radians(315))*75, sin(radians(315))*75, 150, 150);

    if(gen > 2) return;
    
    push();
    translate(75, 0);
    Circular(gen+1);
    pop();
    push();
    translate(0, 75);
    Circular(gen+1);
    pop();
    push();
    translate(-75, 0);
    Circular(gen+1);
    pop();
    push();
    translate(0, -75);
    Circular(gen+1);
    pop();
    
    push();
    translate(cos(radians(45))*75, sin(radians(45))*75);
    Circular(gen+1);
    pop();
    push();
    translate(cos(radians(135))*75, sin(radians(135))*75);
    Circular(gen+1);
    pop();
    push();
    translate(cos(radians(225))*75, sin(radians(225))*75);
    Circular(gen+1);
    pop();
    push();
    translate(cos(radians(315))*75, sin(radians(315))*75);
    Circular(gen+1);
    pop();
    
}



function draw() 
{
    background(51);
    translate(width/2, height/2);
    rotate( radians(theta++) );
    
    Circular(2);
    
    
    //noLoop();
}




