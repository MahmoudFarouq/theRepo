function setup(){
	avl = new AVL();
	i = 1;
    createCanvas(screen.width-25, screen.height-132);
}
Delete = function(){
	btn = document.getElementById("TextArea").value;
	if(btn != "") avl.delete( btn );
	else		  alert("Text box is Empty!");
}
Insert = function(){
	btn = document.getElementById("TextArea").value;
	if(btn != "") avl.insert( btn );
	else		  avl.insert(Math.floor(Math.random(1, 100)*100));
}
Get = function(){
	btn = document.getElementById("TextArea").value;
	alert(avl.get( btn ));
}
function draw(){
    background("#123456");
    avl.display();
}