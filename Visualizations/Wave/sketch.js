var time = 0;
var x = 0;
var prev_time = 0;
var prev_x = 0;

function setup()
{
    createCanvas(650, 650);
    background(51);
    stroke(255);
    strokeWeight(2);
    translate(width/2, height/2);
    line(0, 300, 0, -300);
    line(300, 0, -300, 0);
    A = 50;
    w = 3;
    PHI = 0;
}

function X(t)
{
    return 1 + 0.5*cos( radians(2*PI*t) ) + cos( radians(4*PI*t) ) + 2/3 * cos( radians(6*PI*t) );
}

function draw()
{
    prev_x = x;
    prev_time = time;

    x = X(time);
    translate(width/2, height/2);
    line(prev_time, -20*prev_x, time, -20*x);

    time+=0.5;
}
