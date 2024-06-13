#include "qcustomplotwidget.h"
#include "ui_qcustomplotwidget.h"

qCustomPlotWidget::qCustomPlotWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::qCustomPlotWidget)
{
    ui->setupUi(this);

//    //1.
//    // 生成数据，画出的是抛物线
//    QVector<double> x(101), y(101); //初始化向量x和y
//    for (int i=0; i<101; ++i)
//    {
//      x[i] = i/50.0 - 1; // x范围[-1,1]
//      y[i] = x[i]*x[i]; // y=x*x
//    }
//    ui->customPlot->addGraph();//添加数据曲线（一个图像可以有多个数据曲线）

//    // graph(0);可以获取某个数据曲线（按添加先后排序）
//    // setData();为数据曲线关联数据
//    ui->customPlot->graph(0)->setData(x, y);
//    ui->customPlot->graph(0)->setName("第一个示例");// 设置图例名称
//    // 为坐标轴添加标签
//    ui->customPlot->xAxis->setLabel("x");
//    ui->customPlot->yAxis->setLabel("y");
//    // 设置坐标轴的范围，以看到所有数据
//    ui->customPlot->xAxis->setRange(-1, 1);
//    ui->customPlot->yAxis->setRange(0, 1);
//    ui->customPlot->legend->setVisible(true); // 显示图例
//    // 重画图像
//    ui->customPlot->replot();


//    //2.
//    // 增加两个新图形
//    ui->customPlot->addGraph();
//    // line color blue for first graph
//    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
//    // first graph will be filled with translucent blue
//    // 填充曲线到x轴的区域
//    ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
//    // line color blue for second graph
//    ui->customPlot->addGraph();
//    // line color red for second graph
//    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
//    // generate some points of data (y0 for first, y1 for second graph):
//    QVector<double> x(251), y0(251), y1(251);
//    for (int i=0; i<251; ++i)
//    {
//      x[i] = i;
//      // exponentially decaying cosine  e的n次幂*余弦曲线
//      y0[i] = qExp(-i/150.0)*qCos(i/10.0);
//      // exponential envelope  e的n次幂
//      y1[i] = qExp(-i/150.0);
//    }
//    // configure right and top axis to show ticks but no labels: 设置右轴和上轴显示刻度但不显示标签
//    ui->customPlot->xAxis2->setVisible(true);
//    ui->customPlot->xAxis2->setTickLabels(false);
//    ui->customPlot->yAxis2->setVisible(true);
//    ui->customPlot->yAxis2->setTickLabels(false);
//    // make left and bottom axes always transfer their ranges to right and top axes:
//    // 使左轴和下轴始终将其范围转移到右轴和上轴:
//    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
//    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
//    // pass data points to graphs:
//    ui->customPlot->graph(0)->setData(x, y0);
//    ui->customPlot->graph(1)->setData(x, y1);
//    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
//    // 重新缩放与该图表关联的键轴和值轴，以包含所有显示的数据
//    ui->customPlot->graph(0)->rescaleAxes();
//    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
//    ui->customPlot->graph(1)->rescaleAxes(true);
//    // Note: we could have also just called customPlot->rescaleAxes(); instead
//    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
//    // 添加鼠标及滚轮的交互功能
//    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);



    //3.
    // 将 customPlot 对象的区域和语言设置为英国的英语格式
    ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    // 获取当前之间的秒数作为开始时间
    double now = QDateTime::currentDateTime().toTime_t();
    srand(8); // 随机数种子
    // create multiple graphs:
    for (int gi=0; gi<5; ++gi)
    {
      ui->customPlot->addGraph();
      QColor color(20+200/4.0*gi,70*(1.6-gi/4.0), 150, 150);
      // 设置线条样式为折线图
      ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
      ui->customPlot->graph()->setPen(QPen(color.lighter(200)));
      ui->customPlot->graph()->setBrush(QBrush(color));
      // generate random walk data:模拟了一个随时间变化的波动曲线
      QVector<QCPGraphData> timeData(250);
      for (int i=0; i<250; ++i)
      {
        timeData[i].key = now + 24*3600*i;
        if (i == 0)
          timeData[i].value = (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
        else
          timeData[i].value = qFabs(timeData[i-1].value)*(1+0.02/4.0*(4-gi)) + (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
      }
      ui->customPlot->graph()->data()->set(timeData);
    }
    // 配置底部轴显示日期而不是数字:
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    ui->customPlot->xAxis->setTicker(dateTicker);
    // configure left axis text labels:
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTick(10, "a bit\nlow");
    textTicker->addTick(50, "quite\nhigh");
    ui->customPlot->yAxis->setTicker(textTicker);
    // set a more compact font size for bottom and left axis tick labels:
    // 使用当前字体家族，并将字体大小设置为 8
    ui->customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    ui->customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
    // set axis labels:
    ui->customPlot->xAxis->setLabel("Date");
    ui->customPlot->yAxis->setLabel("Random wobbly lines value");
    // make top and right axes visible but without ticks and labels:
    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTicks(false);
    ui->customPlot->yAxis2->setTicks(false);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setTickLabels(false);
    // set axis ranges to show all data:
    ui->customPlot->xAxis->setRange(now, now+24*3600*249);
    ui->customPlot->yAxis->setRange(0, 60);
    // show legend with slightly transparent background brush:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 150));




}

qCustomPlotWidget::~qCustomPlotWidget()
{
    delete ui;
}

