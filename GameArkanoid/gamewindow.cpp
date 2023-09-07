#include "gamewindow.h"
#include "ui_gamewindow.h"

class Blocks : public GameWindow
{
public:
    Blocks(unsigned pre_x, unsigned p_y, unsigned p_width, unsigned p_height)
    {
        x = pre_x;
        y = p_y;
        widthBlock = p_width;
        heightBlock = p_height;

    }
    ~Blocks(){}
    void madeRaw(GameWindow *gw)
    {
        int gameWidth = GameWindow::width() - this->x;
        QPainter painter;
        painter.begin(gw);
        for(int i = this->x; i < gameWidth; i += widthBlock){
            painter.drawRect(i,this->y,widthBlock,heightBlock);
        }
        painter.end();
    }
private:
    unsigned x;
    unsigned y;
    unsigned heightBlock;
    unsigned widthBlock;

};
GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    QWidget::setFixedSize(width(),height());
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::paintEvent(QPaintEvent *)
{
    Blocks bl(0,10,40,15);
    Blocks bl1(20,25,40,15);
    bl.madeRaw(this);
    bl1.madeRaw(this);
}
