import sorcerer.KEY_CODE;
import sorcerer.KeyHook;
import java.util.Random;

public class javaSnake {
    private static char[][] board = {
            "#################################".toCharArray(),
            "#                               #".toCharArray(),
            "#                               #".toCharArray(),
            "#                               #".toCharArray(),
            "#                               #".toCharArray(),
            "#                               #".toCharArray(),
            "#                               #".toCharArray(),
            "#                               #".toCharArray(),
            "#                               #".toCharArray(),
            "#                               #".toCharArray(),
            "#################################".toCharArray()
    };
    private static int width = board[0].length;
    private static int height= board.length;

    private static Snake snake = new Snake('8',5, 5, 100);
    private static Point tempPoint = new Point(0, 0);
    static Point curDirection = new Point(-1, 0);

    private static Food food = new Food('*', 10, height, width);
    private static int score = 0;

    public static void main(String[] args) throws InterruptedException {
        // write your code here
        new KeyListener();
        addNewFood();
        while(true){
            if(checkNextMove() == -1){
                System.out.println("Game Over!");
                return;
            }
            snake.move(curDirection);
            printBoard();
            Thread.sleep(500);
        }
    }

    private static void printBoard(){
        snake.printSnake(board);
        board[food.getX()][food.getY()] = food.getFoodShape();
        for(int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
        board[snake.getTailX()][snake.getTailY()] = ' ';
        System.out.printf("Score: %s \n", score);
    }
    private static int checkNextMove(){
        tempPoint.set(snake.getHeadX(), snake.getHeadY());
        tempPoint.add(curDirection);
        char nextStepShape = board[tempPoint.x][tempPoint.y];
        if(nextStepShape == food.getFoodShape()){
            snake.addNewPart(food.getFoodPosition(), '0');
            addNewFood();
            score += food.getFoodValue();
            return 1;
        }else if(nextStepShape == '#'){
            return -1;
        }
        return 0;
    }
    private static void addNewFood(){
        food.renew();
        while( board[food.getX()][food.getY()] != ' ' ){
            food.renew();
        }
    }
}

class Food{
    private char foodShape;
    private Point foodPosition;
    private int foodValue;
    private int maxHeight;
    private int maxWidth;
    Food(char shape, int value, int MAX_HEIGHT, int MAX_WIDTH){
        foodShape = shape;
        foodValue = value;
        maxHeight = MAX_HEIGHT;
        maxWidth = MAX_WIDTH;
        foodPosition = Point.getRandomPoint(maxHeight, maxWidth);
    }

    char getFoodShape() {
        return foodShape;
    }


    Point getFoodPosition() {
        return foodPosition;
    }

    int getFoodValue() {
        return foodValue;
    }

    void renew(){
        foodPosition = Point.getRandomPoint(maxHeight, maxWidth);
    }

    int getX(){
        return foodPosition.x;
    }

    int getY(){
        return foodPosition.y;
    }
}

class Snake{
    private SnakeBodyPart[] body;
    private int curLength;
    Snake(char shape, int initX, int initY, int MAX_LEN){
        body = new SnakeBodyPart[MAX_LEN];
        body[0] = new SnakeBodyPart(new Point(initX, initY), shape);
        curLength = 1;
    }

    void addNewPart(Point pos, char shape){
        if(body.length == curLength)
            return;
        body[curLength++] = new SnakeBodyPart(pos, shape);
    }

    void move(Point direction){
        body[0].moveToDir(direction);
        for(int i = 1; i < curLength; i++){
            body[i].setPrevPosition();
            body[i].setCurrentPosition(body[i-1].getPrevPosition());
        }
    }

    int getHeadX(){
        return body[0].getX();
    }

    int getHeadY(){
        return body[0].getY();
    }

    int getTailX(){
        return body[curLength-1].getX();
    }

    int getTailY(){
        return body[curLength-1].getY();
    }

    void printSnake(char[][] board){
        for(int i = 0; i < curLength; i++){
            SnakeBodyPart bodyPart = body[i];
            board[bodyPart.getX()][bodyPart.getY()] = bodyPart.getPartShape();
        }
    }
}

class SnakeBodyPart{
    private Point curPosition;
    private Point prevPosition;
    private char partShape;

    SnakeBodyPart(Point pos, char shape){
        curPosition = pos;
        prevPosition= new Point(0,0);
        partShape = shape;
    }

    Point getPrevPosition() {
        return prevPosition;
    }

    void setPrevPosition() {
        prevPosition.set(curPosition);
    }

    int getX() {
        return curPosition.x;
    }

    int getY() {
        return curPosition.y;
    }

    void moveToDir(Point direction){
        prevPosition.set(curPosition);
        curPosition.add(direction);
    }

    void setCurrentPosition(Point p){
        curPosition.set(p);
    }

    public char getPartShape() {
        return partShape;
    }
}

class Point{
    int x;
    int y;
    private static Random randomGenerator = new Random();
    Point(int xPos, int yPos){
        x = xPos;
        y = yPos;
    }

    void add(Point p){
        x += p.x;
        y += p.y;
    }

    void set(int x, int y){
        this.x = x;
        this.y = y;
    }

    void set(Point p){
        x = p.x;
        y = p.y;
    }

    static Point getRandomPoint(int maxHeight, int maxWidth){
        return new Point( randomGenerator.nextInt(maxHeight), randomGenerator.nextInt(maxWidth) );
    }
}

class KeyListener extends KeyHook{

    @Override
    public void getPressedKey(int keyCode) {
        switch (keyCode){
            case KEY_CODE.DOWN:
                Main.curDirection.set(1, 0);
                break;
            case KEY_CODE.UP:
                Main.curDirection.set(-1, 0);
                break;
            case KEY_CODE.LEFT:
                Main.curDirection.set(0, -1);
                break;
            case KEY_CODE.RIGHT:
                Main.curDirection.set(0, 1);
                break;
            case KEY_CODE.SPACE:
                System.out.println("SPACE");
                break;
        }
    }
}
