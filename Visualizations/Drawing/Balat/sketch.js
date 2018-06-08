len = 40;

function setup() 
{
    createCanvas(screen.width, screen.height);
    background("#fdfdfd");
    translate(width/2, height/2);
    LevelOne();
    noLoop();
}

function LevelOne(dontLoop){
    
    for(var i = 0; i < 5; i++){
        push();
        rotate( radians(126 + i*72 ));
        ShapeOne();
        pop();
    }
    if(!dontLoop)
        LevelTwo();
}

function LevelTwo(dontLoop){
    for(var i = 0; i < 5; i++){
        push();
        rotate( radians(i*72 ));
        translate(len+len*cos(radians(72)), len*sin(radians(72)));
        ShapeTwo();
        pop();
    }
    if(!dontLoop)
        LevelThree();
}

function LevelThree(dontLoop){
    for(var i = 0; i < 5; i++){
        push();
        rotate( radians(i*72));
        translate(len+2*cos( radians(72) )*len, 0);
        for(var j = 0; j < 3; j++){
            push();
            rotate( radians(18 + j*72));
            ShapeOne();
            pop();
        }
        pop();
    }
    if(!dontLoop)
        LevelFour();
}

function LevelFour(dontLoop){
    for(var i = 0; i < 5; i++){
        push();
        rotate( radians(i*72));
        translate(len+2*cos( radians(72) )*len+2*len*sin(radians(54)), 0);
        rotate( radians(-36));
        ShapeTwo();
        translate(0, -2*len*sin(radians(72)));
        ShapeTwo();
        pop();
    }
    if(!dontLoop)
        LevelFive();
}

function LevelFive(dontLoop){
    for(i = 0; i < 5; i++){
        push();
        rotate(radians(i*72));
        
        translate((len+2*len*cos(radians(36)))*cos(radians(36)),
                 -(len+2*len*cos(radians(36)))*sin(radians(36)));
        push();
        rotate(radians(54));
        translate(0, -2*len*cos(radians(36)));
        rotate(radians(180));
        ShapeOne();
        pop();
        
        push();
        secQotr = 2*len*sin(radians(72));
        translate(0, -secQotr);
        rotate(radians(180));
        ShapeTwo();
        pop();
        
        push();
        rotate(radians(108));
        ShapeTwo();
        pop();
        
        push();
        rotate(radians(-18));
        translate(0, -len);
        ShapeOne();
        pop();
        
        push();
        rotate(radians(126));
        translate(0, -len);
        ShapeOne();
        pop();
        
        pop();
    }
    if(!dontLoop)
        LevelSix();
}

function LevelSix(dontLoop){
    
    for(i = 0; i < 5; i++){
        push();
        rotate(radians(i*72));
        translate((len+4*len*cos(radians(36)))*cos(radians(36)),
                 -(len+4*len*cos(radians(36)))*sin(radians(36)));
        for(var j = 0; j < 4; j++){
            push();
            rotate( radians(-54+j*72));
            ShapeOne();
            pop();
        }
        pop();
    }
    if(!dontLoop)
        LevelSeven();
}

function LevelSeven(dontLoop){
    
    for(i = 0; i < 5; i++){
        push();
        rotate(radians(i*72));
        translate(-(len+4*len*cos(radians(36))), 0);
        
        push();
        translate(-cos(radians(36))*2*len*cos(radians(36)),
                  sin(radians(36))*2*len*cos(radians(36)));
        rotate( radians(108));
        ShapeTwo();
        pop();
        push();
        translate(-cos(radians(36))*2*len*cos(radians(36)),
                  -sin(radians(36))*2*len*cos(radians(36)));
        rotate( radians(180));
        ShapeTwo();
        pop();
        push();
        translate(-cos(radians(108))*2*len*cos(radians(36)),
                  -sin(radians(108))*2*len*cos(radians(36)));
        rotate( radians(252));
        ShapeTwo();
        pop();
        
        pop();
    }
    if(!dontLoop)
        LevelEight();
}

function LevelEight(dontLoop){
    
    for(var k = 0; k < 5; k++){
        push();
        rotate(radians(k*72));
        translate(-(len+4*len*cos(radians(36))), 0);
        for(var j = 0; j < 3; j++){
            push();
            rotate(radians(-72+j*72));
            translate(-(2*len*cos(radians(72))+len), 0);
            rotate(radians(72));
            for(var i = 0; i < 3; i++){
                push();
                rotate( radians(126 + i*72 ));
                ShapeOne();
                pop();
                if(i > 0){
                    push();
                    rotate( radians(i*72 ));
                    translate(len+len*cos(radians(72)), len*sin(radians(72)));
                    ShapeTwo();
                    pop();
                }
            }
            pop();
        }
        pop();
    }
}

function ShapeTwo(){
    
    push();
    
    angle = 72;
    
    rotate(radians(180));
    
    rightPoint = createVector(len*cos(radians(    angle)), len*sin(radians(    angle)));
    leftPoint  = createVector(len*cos(radians(180-angle)), len*sin(radians(180-angle)));
    downPoint  = p5.Vector.add(rightPoint, leftPoint);
    
    line(0           , 0           , rightPoint.x, rightPoint.y);
    line(0           , 0           , leftPoint.x , leftPoint.y );
    line(leftPoint.x , leftPoint.y , downPoint.x , downPoint.y );
    line(rightPoint.x, rightPoint.y, downPoint.x , downPoint.y );
    partOfLen = len*cos(radians(angle));
    
    translate(len*cos(radians(angle)), len*sin(radians(angle)));
    for(var i = 0; i < 144; i++){
        stroke("#ff2a7f");
        line( cos(radians(-108-i))*partOfLen, sin(radians(-108-i))*partOfLen, 0, 0 );
        stroke(0);
        point( cos(radians(-108-i))*partOfLen, sin(radians(-108-i))*partOfLen);
    }
    translate(-2*len*cos(radians(angle)), 0);
    for(i = 0; i < 144; i++){
        stroke("#404080");
        line( cos(radians(angle-i))*partOfLen, sin(radians(angle-i))*partOfLen, 0, 0 );
        stroke(0);
        point( cos(radians(angle-i))*partOfLen, sin(radians(angle-i))*partOfLen);
    }
    pop();
}

function ShapeOne(){
    
    push();
    
    rotate(radians(180));
    
    rightPoint = createVector(len*cos(radians( 54)), len*sin(radians( 54)));
    leftPoint  = createVector(len*cos(radians(126)), len*sin(radians(126)));
    downPoint  = p5.Vector.add(rightPoint, leftPoint);
    
    line(0           , 0           , rightPoint.x, rightPoint.y);
    line(0           , 0           , leftPoint.x , leftPoint.y );
    line(leftPoint.x , leftPoint.y , downPoint.x , downPoint.y );
    line(rightPoint.x, rightPoint.y, downPoint.x , downPoint.y );

    translate(0, downPoint.y);

    //enzel ta7t w ersem 2 cpart of circle
    strokeWeight(1.2);
    for(var i = 0; i < 72; i++){
        partOfLen = (len-len*cos(radians(72)));
        
        stroke("#ff2a7f");
        line(cos(radians(-54-i))*len, sin(radians(-54-i))*len,
             cos(radians(-54-i))*partOfLen, sin(radians(-54-i))*partOfLen);
        
        stroke(0);
        point(cos(radians(-54-i))*len, sin(radians(-54-i))*len);
        point(cos(radians(-54-i))*partOfLen, sin(radians(-54-i))*partOfLen);
        
    }
    //etla3 fo2 w ersem 1 cpart of circle
    smallPartOfLen = len-partOfLen;
    translate(0, -downPoint.y);
    for(i = 0; i < 72; i++){
        stroke("#404080");
        line( cos(radians(54+i))*smallPartOfLen, sin(radians(54+i))*smallPartOfLen, 0, 0 );
        //draw upper circle part
        stroke(0);
        point(cos(radians(54+i))*smallPartOfLen, sin(radians(54+i))*smallPartOfLen);
    }
    pop();
}













