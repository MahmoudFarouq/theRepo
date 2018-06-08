rotationVar = 90;
function setup() {
  createCanvas(800, 600);
  stroke(255);
  noFill();
}

function draw() {
  background(51);
  translate(400, 300);
  rotate(radians(rotationVar));
  //line(-400, 0, 400, 0);
  //line(0, -300, 0, 300);    
  ellipse(0, 0, 300, 300);
  //noLoop();
  RecursiveCircles_1(150, 4, rotationVar++);
  
}


function RecursiveCircles_1(r, recNum, degree){
  if(!recNum)
    return;
  push();
  translate(r/2, 0);
  ellipse(0, 0, r, r);
  rotate(radians(-degree));
  RecursiveCircles_1(r/2, recNum-1, degree);
  pop();
  push();
  translate(-r/2 , 0);
  ellipse(0, 0, r, r);
  rotate(radians(-degree));
  RecursiveCircles_1(r/2, recNum-1, degree);
  pop();
}

function RecursiveCircles_2(r, recNum, degree){
  if(!recNum)
    return;
  push();
  translate(r/2, 0);
  ellipse(0, 0, r, r);
  rotate(radians(-degree));
  RecursiveCircles_2(r/2, recNum-1, degree);
  pop();
  push();
  translate(-r/2 , 0);
  ellipse(0, 0, r, r);
  rotate(radians(-degree));
  RecursiveCircles_2(r/2, recNum-1, degree);
  pop();
  push();
  translate(0, r/2);
  ellipse(0, 0, r, r);
  rotate(radians(-degree));
  RecursiveCircles_2(r/2, recNum-1, degree);
  pop();
  push();
  translate(0, -r/2);
  ellipse(0, 0, r, r);
  rotate(radians(-degree));
  RecursiveCircles_2(r/2, recNum-1, degree);
  pop();
}

function RecursiveCircles_3(r, recNum, degree){
  if(!recNum)
    return;
  push();
  translate(r/2, 0);
  ellipse(0, 0, r, r);
  rotate(radians(-degree));
  RecursiveCircles_3(r/2, recNum-1, degree);
  pop();
  push();
  translate(-r/2 * cos(radians(60)), r/2 * sin(radians(60)));
  ellipse(0, 0, r, r);
  rotate(radians(-degree));
  RecursiveCircles_3(r/2, recNum-1, degree);
  pop();
  push();
  translate(-r/2 * cos(radians(60)), -r/2 * sin(radians(60)));
  ellipse(0, 0, r, r);
  rotate(radians(-degree));
  RecursiveCircles_3(r/2, recNum-1, degree);
  pop();
}
