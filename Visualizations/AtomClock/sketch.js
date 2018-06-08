function setup() 
{
    createCanvas(650, 650);
    background(51);
    stroke(255);
    strokeWeight(2);
    a = 30;
    b = 100;
    maxLength = 250;
    normalStroke = 2;

    inc1 = 25      //starting pos
    inc2 = 120      //starting pos
    inc3 = 205      //starting pos
}

function draw() {
    
    translate(width/2, height/2);
    background(51);
    push();
    DrawFullThing();
    pop();
    Clock();
}

function Clock(){
    seconds  = radians((360/60)*second() - 90); 
    secondsX = cos(seconds)*100;
    secondsY = sin(seconds)*100;
    line(0, 0, secondsX, secondsY);
    
    minutes  = radians((360/60)*minute() -90 + seconds ); 
    minutesX = cos(minutes)*70;
    minutesY = sin(minutes)*70;
    line(0, 0, minutesX, minutesY);
    
    hours  = radians((360/12)*hour() -90 + minutes); 
    hoursX = cos(hours)*50;
    hoursY = sin(hours)*50;
    line(0, 0, hoursX, hoursY);
    
    DrawClockFrame();
}

function DrawClockFrame(){
    var radius = 150
    noFill();
    ellipse(0, 0, 300, 300);
    for(var i = 1; i <= 12; i++){
        rotate( radians(30) );
        line(0, 150, 0, i%3 == 0 ? 130:140 );
    }
}

function DrawFullThing(){
    ellipse(0, 0, 20, 20);
    fill(255);
    
    rotate( radians(90) );
    inc1 = DrawAtom(inc1);
    rotate( radians(120) );
    inc2 = DrawAtom(inc2);
    rotate( radians(300) );
    inc3 = DrawAtom(inc3);
}

function DrawAtom(increment){
    var curStrokeW = 0;
    var strokeIncrement = 0.02;
    
    for(theta = increment; theta < maxLength+increment; theta++){
        strokeWeight(curStrokeW);
        radius = EllipseRadius(a, b, radians(theta));
        xPos = Math.cos((theta/180)*Math.PI)*radius;
        yPos = Math.sin((theta/180)*Math.PI)*radius;
        point(xPos, yPos);
        curStrokeW += strokeIncrement;
    }
    increment += 10;        //speed
    increment %= 360;
    return increment;
}
function EllipseRadius(a, b, theta_radians){
    //with "horizontal" semi-axis a and "vertical" semi-axis b is
    r = (a*b)/sqrt( sq(a, 2) * sq(sin(theta_radians), 2) + sq(b, 2) * sq(cos(theta_radians), 2) );
    return r;
}






