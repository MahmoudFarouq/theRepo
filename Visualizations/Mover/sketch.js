function setup() 
{
    createCanvas(640, 560);
    background(51);
    stroke(255);
    strokeWeight(2);
    
    mover = new Mover(5);
}

function draw() 
{
    mover.display();
    mover.update();
}




