using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 连连看
{
    public partial class Form1 : Form
    {
        MapMode mymapmodo;
        Graphics g;
        Rule myRule;
        int grade;
        PictureBox[,] pic;
        bool GameStar = false;//是否开始游戏
        int ClickSum = 0;//点击图片次数
        public Point fpoint;//记录第一次点击的位置
        public Point spoint;//记录第二次点击的位置
        int pbvalue = 100;
        public Form1()
        {
            InitializeComponent();
           
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void Gameprint()
        {
            if (GameStar == false)
            {
                mymapmodo = new MapMode(6);
                myRule = new Rule(ref mymapmodo.mapnum);
                g = CreateGraphics();
                GameStar = true;
                grade = 0;
                pic = new PictureBox[30, 30];
                label1.Text = "得分：0";
                pbvalue = 100;
                //画图
                for (int i = 0; i < mymapmodo.mapwidth; i++)
                {
                    for (int j = 0; j < mymapmodo.mapheight; j++)
                    {
                        pic[i, j] = new PictureBox
                        {
                            Location = new System.Drawing.Point(i * mymapmodo.picwidth, j * mymapmodo.picheight),
                            Name = Convert.ToString(i),
                            Size = new System.Drawing.Size(mymapmodo.picwidth, mymapmodo.picheight),
                            TabIndex = mymapmodo.mapnum[i, j],
                            TabStop = false,
                            Visible = true,
                            Enabled = true,

                            BackgroundImage = mymapmodo.img[mymapmodo.mapnum[i, j]],
                            BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
                        };
                        this.Controls.Add(pic[i, j]);
                        pic[i, j].MouseClick += new MouseEventHandler(Pic_MouseClick);
                    }
                }


                timer1.Start();
              
            }
        }
        private void Button1_Click(object sender, EventArgs e)
        {
            Gameprint();
        }
        private void Pic_MouseClick(object sender, MouseEventArgs e)
        {
            PictureBox pic1;
           
            if (GameStar == false)
            { return; }
            else
            {
                 pic1 = (PictureBox)sender;
                int curx =pic1.Location.X/50;
                int cury = pic1.Location.Y / 64;
                if (curx > mymapmodo.mapwidth || cury > mymapmodo.mapheight) { return; }
                else
                {
                    ClickSum++;
                    switch (ClickSum)
                    {
                        case 1:
                            
                            fpoint = new Point(curx, cury);
                          //   myDraw.DrawRectangle(fpoint,g,pic1);
                            break;
                        case 2:
                           
                            spoint = new Point(curx, cury);
                      //      myDraw.DrawRectangle(spoint,g,pic1);
                             if(myRule.Islink(fpoint.X,fpoint.Y,curx,cury))
                            {
                                ClickSum = 0;
                                //myDraw.DrawLine(fpoint, spoint, myRule.corner, myRule.cornerSum,pic,g);
                                myRule.EraseImage(fpoint, spoint, pic);
                                mymapmodo.mapnum[fpoint.X, fpoint.Y] = -1;
                                mymapmodo.mapnum[spoint.X, spoint.Y] = -1;
                                myRule.map[fpoint.X, fpoint.Y] = -1;
                                myRule.map[spoint.X, spoint.Y] = -1;
                             //   pbvalue = pbvalue + 1;
                                grade = grade + 10;
                                label1.Text = "得分" + grade;
                                if(myRule.CheckWin(ref mymapmodo.mapnum))
                                {
                                    MessageBox.Show("恭喜过关！");
                                    timer1.Stop();
                                    GameStar = false;
                                    Gameprint();
                                }
                       
                            }
                            else
                            {
                                ClickSum = 1;
                                fpoint = new Point(curx, cury);
                            }
                            break;
                        default:break;


                    }
                }
               
            }
            
        }

        /* private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
         {
             
         }*/

        private void Button2_Click(object sender, EventArgs e)
        {
            if(button2.Text== "暂停")
            {
                timer1.Stop();
                GameStar = false;
                button2.Text = "继续";
            }
            else
            {
                timer1.Start();
                GameStar = true;
                button2.Text = "暂停";
            }
        }
        private void Timer1_Tick(object sender, EventArgs e)
        {
            pbvalue = --pbvalue;
            if (pbvalue > 100)
                pbvalue = 100;
            if (pbvalue == 0)
            {
                timer1.Stop();
                MessageBox.Show("游戏失败！");
                GameStar = false;
                return;
            }
            else
            {
                progressBar1.Value = pbvalue;
            }
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }
    }
    class MapMode
    {
        public int picwidth = 50;//单个图片像素宽度
        public int picheight = 64;//单个图片像素高度
        public int mapwidth = 6;//地图横向排列图片的个数、
        public int mapheight = 6;//地图纵向排列图片的个数、
        public int picmax = 6;//图片资源个数
        public int[,] mapnum = new int[6,6 ];//实际的图片矩阵为6*4;
        public int picnum;//本局图片的数量
       // public int picmulti;//一张图片重复出现的次数，一定为偶数
        public Image[] img = new Image[10];

        public MapMode(int _picnum)
        {
            picnum = _picnum;//图片的数量
            for (int i = 0; i < mapwidth; i++)//初始化
            {
                for (int j = 0; j < mapheight; j++)
                {
                    mapnum[i, j] = 0;
                }

            }
            GetRandomMap(picnum);// 随机生成图片 图片的矩阵，本局图片个数

            for (int i = 0; i < picnum+1; i++)
            {
                Image image1 = Image.FromFile(i.ToString() + ".jpeg");
                img[i] = image1;//返回图片对象
            }

        }
      
        private void GetRandomMap(int picnum)//随机生成图片
        {
            ArrayList Randonnum = new ArrayList();
            Random r = new Random();
            for (int i=0;i<(mapheight*mapwidth)/2;i++)
            {
                int j = r.Next(0, picnum);
                Randonnum.Add(j);
                Randonnum.Add(j);
            }
            for(int i=0;i<mapwidth;i++)
            {
                for(int j=0;j<mapheight;j++)
                {
                    int i_list = r.Next(0, Randonnum.Count);
                    int n= (int)Randonnum[i_list];
                    Randonnum.RemoveAt(i_list);
                     mapnum[i, j] = n;
                }
            }
        }

    }
    class Rule
    {
        private int M, N;
        public int[,] map;
        Point[] fArray, sArray;
        int fArrayLen, sArrayLen;
        private int BLANK = -1;
        public int cornerSum = 0;
        public Point[] corner = new Point[2];
        public Rule(ref int[,] mmap)
        {
            M = mmap.GetLength(0);
            N = mmap.GetLength(1);
            map = new int[M, N];
            fArray = new Point[M * N];
            sArray = new Point[M * N];
            for(int i=0;i<M;i++)
            {
                for(int j=0;j<N;j++)
                {
                    map[i, j] = mmap[i,j];
                }
            }
            corner[0] = new Point(0, 0);
            corner[1] = new Point(0, 0);
        }
        public bool Islink(int x1,int y1,int x2,int y2)
        {
            if(x1==x2&&y1==y2)
            {
                return false;
            }
            else
            {
                if(map[x1,y1]==map[x2,y2])
                {
                    if(IsZeroCornerLink(x1,y1,x2,y2))
                    {
                        cornerSum = 0;return true;
                    }
                    else
                    {
                        fArrayLen = FindEmpty(x1, y1, ref fArray);
                        sArrayLen = FindEmpty(x2, y2, ref sArray);
                        if (IsOneCornerLink(ref fArray, fArrayLen, ref sArray, sArrayLen))
                        {
                            cornerSum = 1;
                            return true;
                        }
                        else
                        {
                            return IsTwoCornerLink(x1, y1, x2, y2);
                        }
                    }
                   
                }
                return false;
            }
        }
        public bool IsZeroCornerLink(int x1, int y1, int x2, int y2)
        {
            if (x1 == x2 && y1 != y2)
            {
                int bigger = y1 > y2 ? y1 : y2;
                int smaller = y1 > y2 ? y2 : y1;
                int miny = smaller + 1;
                while (map[x1, miny] == BLANK)
                {
                    miny++;
                    if (miny >= N)
                        break;
                }
                if (miny == bigger)
                    return true;
                else
                    return false;
            }
            else if (x1 != x2 && y1 == y2)
            {
                int bigger = x1 > x2 ? x1 : x2;
                int smaller = x1 > x2 ? x2 : x1;
                int minx = smaller + 1;
                while (map[minx, y1] == BLANK)
                {
                    minx++;
                    if (minx >= N)
                        break;
                }
                if (minx == bigger)
                    return true;
                else
                    return false;
            }
            else
                return false;

        }
        public bool IsOneCornerLink(ref Point[]a1,int a1len,ref Point[] a2,int a2len)
        {
            bool result = false;
            for(int i=0;i<a1len;i++)
            {
                for(int j=0;j<a2len;j++)
                {
                   if(a1[i].X==a2[j].X&&a1[i].Y==a2[j].Y)
                    {
                        corner[0] = new Point(a1[i].X, a1[i].Y);
                        result = true;
                    }
                }
            }
            return result;
        }
        public bool IsTwoCornerLink(int x1, int y1, int x2, int y2)
        {
            int pos = 0;
            Point[] ar1 = new Point[M * N];
            int ar1Len = 0;
            Point[] ar2 = new Point[M * N];
           int ar2Len = 0;
            pos = x1 - 1;
             while(0<=pos&&pos<M&& map[pos, y1]==BLANK)
            {
              ar1Len = FindEmpty(pos, y1, ref ar1);
                ar2Len = FindEmpty(x2, y2, ref ar2);
                if(IsOneCornerLink(ref ar1,ar1Len,ref ar2,ar2Len))
                {
                    cornerSum = 2;
                    corner[1] = new Point(pos, y1);
                    return true;
                }
                pos--;
            }
            pos = x1 +1;
            while (0 <= pos && pos < M && map[pos, y1] == BLANK)
            {
                ar1Len = FindEmpty(pos, y1, ref ar1);
                ar2Len = FindEmpty(x2, y2, ref ar2);
                if (IsOneCornerLink(ref ar1, ar1Len, ref ar2, ar2Len))
                {
                    cornerSum = 2;
                    corner[1] = new Point(pos, y1);
                    return true;
                }
                pos++;
            }
            pos = y1 -1;
            while (0 <= pos && pos < N && map[x1,pos] == BLANK)
            {
                ar1Len = FindEmpty(x1, pos, ref ar1);
                ar2Len = FindEmpty(x2, y2, ref ar2);
                if (IsOneCornerLink(ref ar1, ar1Len, ref ar2, ar2Len))
                {
                    cornerSum = 2;
                    corner[1] = new Point(x1, pos);
                    return true;
                }
                pos--;
            }
            pos = y1 +1;
            while (0 <= pos && pos < N && map[x1, pos] == BLANK)
            {
                ar1Len = FindEmpty(x1, pos, ref ar1);
                ar2Len = FindEmpty(x2, y2, ref ar2);
                if (IsOneCornerLink(ref ar1, ar1Len, ref ar2, ar2Len))
                {
                    cornerSum = 2;
                    corner[1] = new Point(x1, pos);
                    return true;
                }
                pos++;
            }
            return false;
        }
        public bool CheckWin(ref int[,] map)
        {
            bool win = true;
            for(int i=0;i<M;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(map[i,j]!=-1)
                    {
                        win = false;
                    }
                }
            }
            return win;
        }
        public int FindEmpty(int x,int y,ref Point[] arr)
        {
            int count = 0;
            int pos = x - 1;
            while(0<=pos&&map[pos,y]==BLANK)
            {
                arr[count].X = pos;
                arr[count].Y = y;
                pos--;
                count++;
            }
            pos = x + 1;
            while (pos < M && map[pos, y] == BLANK)
            {
                arr[count].X = pos;
                arr[count].Y = y;
                pos++;
                count++;
            }
            pos = y + 1;
            while (pos < N && map[x,pos] == BLANK)
            {
                arr[count].X = x;
                arr[count].Y = pos;
                pos++;
                count++;
            }
            pos = y - 1;
            while (0 <= pos && map[x, pos] == BLANK)
            {
                arr[count].X = x;
                arr[count].Y = pos;
                pos--;
                count++;
            }
            return count;
        }
        public void EraseImage(Point p1, Point p2, PictureBox[,] pic)
        {
            pic[p1.X, p1.Y].Visible = false;
            pic[p2.X, p2.Y].Visible = false;
        }
    }
   
}
