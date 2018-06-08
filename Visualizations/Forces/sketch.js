function setup() 
{
    createCanvas(640, 460);
    background(51);
    noStroke();
    
    wind = createVector(0.01, 0);
    
    movers = [];
    for(var i = 0; i < 2; i++)
        movers.push(new Mover(random(1, 5),random(0, width),random(0, height/2)));
        
    liquid = new Liquid(0, height/2, width, height/2, 0.1);
}

function draw() 
{
    background(51);
    liquid.display();

    for(var i = 0; i < 2; i++){
        
        /*leftSide  = createVector( 2*(1-movers[i].location.x/width), 0);
        rightSide = createVector(-2*(  movers[i].location.x/width), 0);
        downSide  = createVector( 0, -1*(movers[i].location.y/height));*/
        movers[i].Friction();
        //because all Balls fall to the ground in the same speed 
        //Scaling gravity by mass to be more accurate
        gravity   = createVector( 0, 0.01*movers[i].mass);
        
        
        
        /*movers[i].applyForce(leftSide);
        movers[i].applyForce(rightSide);
        movers[i].applyForce(downSide);*/
        
        /*if(i > 0){
            fill("#123456");
            movers[i].applyForce(movers[i].friction);
        }else{
            fill(255);
        }*/
        
        if( movers[i].isInside(liquid) ){
            movers[i].DragForce(liquid);
        }
        
        movers[i].applyForce(wind);
        movers[i].applyForce(gravity);
        movers[i].update();
        movers[i].display();
    }
}



