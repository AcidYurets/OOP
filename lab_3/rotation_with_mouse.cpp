#include <QtWidgets>

#include "graph.hpp"
#include "react.hpp"
#include "trans.hpp"

//= Для Юры: смотри комментарии, начинающиеся с //=

class Display : public QLabel {

    //= Флаг перемещения
    bool shifting;

    //= Флаг поворота
    bool rotating;

    //= Начальное положение курсора
    QPoint cursor;

public:

    Display(QWidget *parent = nullptr) : QLabel(parent) {
        setAlignment(Qt::AlignCenter);

        shifting = false;
        rotating = false;

        render();
    }

    void load(const char *fileName) {
        Event event;
        Load load;

        load.fileName = fileName;
        eventLoad(event, load);

        update(event);
    }

protected:

    //= Обработчик нажатий на кнопки мыши
    void mousePressEvent(QMouseEvent *mouse) {

        //= Устанавливаем положение
        cursor = mouse->pos();

        //= Если нажата левая кнопка
        if (mouse->button() == Qt::LeftButton)

            //= Устанавливаем флаг перемещения
            shifting = true;

        //= Если нажата правая кнопка
        if (mouse->button() == Qt::RightButton)

            //= Устанавливаем флаг поворота
            rotating = true;

        mouse->accept();
    }

    //= Обработчик прекращения нажатия на кнопки мыши
    void mouseReleaseEvent(QMouseEvent *mouse) {

        //= Сбрасываем флаги
        shifting = false;
        rotating = false;

        mouse->accept();
    }

    //= Обработчик перемещения мыши
    void mouseMoveEvent(QMouseEvent *mouse) {

        //= Вычисляем приращения координат
        double x = mouse->x() - cursor.x();
        double y = mouse->y() - cursor.y();

        //= Обновляем положение
        cursor = mouse->pos();

        Event event;

        //= Применяем процедуру перемещения
        if (shifting) {
            Translate translate;

            translate.x = x;
            translate.y = y;

            eventTranslate(event, translate);
        }

        //= Применяем процедуру поворота
        if (rotating) {
            Rotate rotate;

            rotate.a = 0.01 * x;
            rotate.b = 0.01 * y;

            eventRotate(event, rotate);
        }

        update(event);

        mouse->accept();
    }

    //= Обработчик вращения колеса мыши
    void wheelEvent(QWheelEvent *wheel) {

        //= Вычисляем приращение
        double delta = wheel->angleDelta().y(), k;

        //= Крутим вниз
        if (delta < 0)

            //= Увеличиваем
            k = 4.0 / 3.0;

        //= Крутим вверх
        if (delta > 0)

            //= Уменьшаем
            k = 3.0 / 4.0;

        Event event;
        Scale scale;

        scale.k = k;
        eventScale(event, scale);

        update(event);

        wheel->accept();
    }

private:

    void update(Event &event) {
        Error error = react(event);

        if (error == errorNone)
            render();

        else critical(error);
    }

    void render() {
        QPixmap pixmap(640, 480);
        pixmap.fill(Qt::black);

        QPainter painter(&pixmap);
        painter.setPen(Qt::white);

        Event event;
        Graph graph;

        graphInit(graph, painter);
        eventGraph(event, graph);

        Error error = react(event);

        if (error == errorNone)
            setPixmap(pixmap);

        else critical(error);
    }

    void critical(Error error) {
        QMessageBox::critical(this, "Ошибка", errorMessage(error));
    }
};

class Window : public QMainWindow {
    Display *display;

public:

    Window() {
        display = new Display;
        setCentralWidget(display);

        QAction *openFileAction = new QAction("Открыть", this);
        connect(openFileAction, &QAction::triggered, this, &Window::openFile);

        QMenu *fileMenu = menuBar()->addMenu("Файл");
        fileMenu->addAction(openFileAction);
    }

private:

    void openFile() {
        QString fileName = QFileDialog::getOpenFileName(this, "Открыть модель");
        display->load(fileName.toStdString().c_str());
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Window window;
    window.show();

    return app.exec();
}
