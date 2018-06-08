function setup() 
{
    createCanvas(640, 460);
    background(51);
    stroke(255);
    strokeWeight(2);
    
    bs1 = new BasicShape(50, 4, 1, 8);
}

function draw() 
{
    background(51);
    translate(width/2, height/2);
    bs1.draw();
}

function BasicShape(length, maxGen, curGen, ratio)
{
    this.length = length; this.curLength = 0;
    this.left = this.right = this.up = this.down = null;
    
    this.draw = function(){
        this.curLength = ( this.curLength > this.length ? this.curLength:this.curLength+1 );
        push();
        line(-this.length/ratio,-this.length/ratio, this.curLength   ,-this.length/ratio);
        line( this.length/ratio,-this.length/ratio, this.length/ratio, this.curLength);
        line( this.length/ratio, this.length/ratio,-this.curLength   , this.length/ratio);
        line(-this.length/ratio, this.length/ratio,-this.length/ratio,-this.curLength);
        pop();
        
        this.callChilds();
    }
    this.callChilds = function(){
        if(curGen > maxGen || this.curLength < this.length)
            return;
        
        this.left  = (this.left  === null ?  new BasicShape(length, maxGen, curGen+1, ratio):this.left);
        this.right = (this.right === null ?  new BasicShape(length, maxGen, curGen+1, ratio):this.right);
        this.up    = (this.up    === null ?  new BasicShape(length, maxGen, curGen+1, ratio):this.up);
        this.down  = (this.down  === null ?  new BasicShape(length, maxGen, curGen+1, ratio):this.down);

        push();
        translate(this.length, -this.length/ratio*2);
        this.left.draw();
        pop();
        
        push();
        translate(-this.length, this.length/ratio*2);
        this.right.draw();
        pop();
        
        push();
        translate(this.length/ratio*2, this.length);
        this.up.draw();
        pop();
        
        push();
        translate(-2*this.length/ratio, -this.length);
        this.down.draw();
        pop();
    }
}