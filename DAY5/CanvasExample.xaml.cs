using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace WPFEXAMPLE
{
    /// <summary>
    /// CanvasExample.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class CanvasExample : Window
    {
        public CanvasExample()
        {
            InitializeComponent();
        }

        private Point current = new Point();

        private void Canvas_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            current = e.GetPosition(this);
        }

        private void Canvas_MouseMove(object sender, MouseEventArgs e)
        {
            if ( e.LeftButton == MouseButtonState.Pressed )
            {
                Point pt = e.GetPosition(this);

                // WPF 는 완벽한 객체지향 입니다.
                // => "선을 그려라" 개념이 아닙니다
                // => "선 객체를 만들어서 추가한다"
                Line line = new Line();
                line.Stroke = SystemColors.WindowFrameBrush;

                line.X1 = current.X;
                line.Y1 = current.Y;
                line.X2 = pt.X;
                line.Y2 = pt.Y;

                // canvas에 line 추가. canvas 객체 이름이 있어야 여기서 접근 가능

                canvas.Children.Add(line);

                current = pt;
            }

        }
    }
}
