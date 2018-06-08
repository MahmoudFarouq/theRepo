function setup(){
    createCanvas(640,360);
    
    os = new Oscillator();
    
}
function draw() {
    os.oscillate();
    os.display();
}


function Oscillator()
{
    this.angle      = createVector(0, 0);
    this.velocity   = createVector(random(-0.05,0.05),random(-0.05,0.05));
    this.amplitude  = createVector(random(width/2),random(height/2));

    this.oscillate = function() {
        this.angle.add(this.velocity);
    }
    this.display = function() {
        x = sin(this.angle.x)*this.amplitude.x;
        y = sin(this.angle.y)*this.amplitude.y;
        push();
        translate(width/2,height/2);
        stroke(0);
        fill(175);
        line(0,0,x,y);
        ellipse(x,y,16,16);
        pop();
    }

}




/*function setup(){
    createCanvas(640,360);
}
function draw() {
    background(51);
    period = 120;
    amplitude = 100;
    x = amplitude * cos(TWO_PI * frameCount / period);
    stroke(255);
    fill(175);
    translate(width/2,height/2);
    line(0,0,x,0);
    ellipse(x,0,20,20);
}*/














/*angle = 0;
aVelocity = 0;
aAcceleration = 0.001;

function setup() 
{
    createCanvas(640, 460);
    background(51);
    stroke(255);
}

function draw() 
{
    background(51);
    translate(width/2,height/2);
    rotate(angle);
    line(-100,0,100,0);
    ellipse(100,0,50,50);
    ellipse(-100,0,50,50);
    
    aVelocity += aAcceleration;
    angle += aVelocity;
    angle %= 360;
}*/