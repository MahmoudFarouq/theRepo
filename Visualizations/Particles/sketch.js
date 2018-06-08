
function setup() 
{
    createCanvas(640, 460);
    background(51);
    ps = new ParticleSystem(createVector(width/2, height/2));
}

function draw() 
{
    background(51);
    ps.run();
}