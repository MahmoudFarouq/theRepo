function ParticleSystem(loc){
    this.particles = [];
    this.origin    = loc;
    
    this.addParticle = function(){
        this.particles.push(new Particle(createVector(loc.x, loc.y)));
        this.particles[this.particles.length-1].
                applyForce(createVector(random(-0.03, 0.03), random(-0.03, 0.03)));
    }
    
    this.run = function(){
        this.addParticle();
        
        for(var i = 0; i < this.particles.length; i++){
            
            /*this.particles[this.particles.length-1].
                applyForce(createVector(noise(-0.03, 0.03), noise(-0.03, 0.03)));*/
            
            this.particles[i].run();
            if(this.particles[i].isDead()){
                this.particles.splice(i, 1);
            }
        }
    }
}