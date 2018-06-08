function setup() 
{
    createCanvas(640, 640);
    background(51);
    strokeWeight(2);
    stroke(255);
}

function draw() 
{
    translate(width/2-150, height/2);

    push();
    rotate( radians(-60) );
    line(0, 0, 300, 0);
    MakeTri(0, 0, 300, 0, 1);
    pop();
    
    push();
    translate(150, -259.8);
    rotate( radians(60) );
    line(0, 0, 300, 0);
    MakeTri(0, 0, 300, 0, 1);
    pop();
    
    push();
    translate(300, 0);
    rotate( radians(180) );
    line(0, 0, 300, 0);
    MakeTri(0, 0, 300, 0, 1);
    pop();
    
    
    noLoop();
}
function MakeTri(x1, y1, x2, y2, gen)
{
    if(gen > 4)
        return;
    
    stroke( 51 ); //"#159465"
    strokeWeight(3.5);
    line(x2/3, y1, x2*2/3, y2);
    stroke(255);
    strokeWeight(2);
    line(x2/3, y1, x2/3+x2/6, (x2/3)*sin(30));
    line(x2/3+x2/6, (x2/3)*sin(30), x2*2/3, y1);
    
    push();
    MakeTri(x1, y1, x2/3, 0, gen+1);
    pop();
    
    push();
    translate(x2*2/3, y2);
    MakeTri(0, 0, x2/3, 0, gen+1);
    pop();
    
    push();
    translate(x2/3, y2);
    rotate( radians(-63) );
    MakeTri(0, 0, x2/3, 0, gen+1);
    pop();
    
    push();
    translate(x2/3+x2/6, (x2/3)*sin(30));
    rotate( radians(63) );
    MakeTri(0, 0, x2/3, 0, gen+1);
    pop();
    
    
}












