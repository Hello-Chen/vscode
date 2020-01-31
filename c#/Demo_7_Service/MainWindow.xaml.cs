/*==============================================================================
* 类名称：MainWindow
* 类描述：
* 创建人：王伟生
* 创建时间：2015/9/2 14:24:00
* 修改人：
* 修改时间：
* 修改备注：
* 版本：v1.0.0.0
*==============================================================================
* Copyright ©  北京新大陆时代教育有限公司 2015 . All rights reserved.
*==============================================================================*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;//引用IPEndPoint命名空间
using System.Net.Sockets;//引用TcpListener命名空间
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Demo_7_Service
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        TcpListener tcp;
        bool isClosing;
        private void btnConnect_Click(object sender, RoutedEventArgs e)
        {
            try
            {

                if (btnConnect.Content.ToString() == "连接")
                {
                    //定实例化终端节点，默认侦听端口8081
                    IPEndPoint ipe = new IPEndPoint(IPAddress.Parse(txtService.Text), 8081);
                    //实例化侦听TCP
                    tcp = new TcpListener(ipe);
                    //开启侦听
                    tcp.Start();
                    //绑定异步连接
                    tcp.BeginAcceptSocket(new AsyncCallback(AcceptSocketCB), tcp);
                    isClosing = false;
                    ShowMsg("开始侦听：" + ipe.Address.ToString() + ":" + ipe.Port.ToString());
                    btnConnect.Content = "断开";
                }
                else
                {
                    //关闭侦听
                    isClosing = true;
                    tcp.Stop();
                    ShowMsg("关闭侦听成功！");
                    btnConnect.Content = "连接";
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        //实例化用于接收数据的byte数组
        static byte[] buff = new byte[60000];
        private void AcceptSocketCB(IAsyncResult ar)
        {
            if (!isClosing)
            {
                //获取异步信息
                TcpListener tcp = (TcpListener)ar.AsyncState;
                //异步连接
                Soc = (Socket)tcp.EndAcceptSocket(ar);
                ShowMsg("用户连接");
                //绑定异步接收数据
                Soc.BeginReceive(buff, 0, buff.Length, SocketFlags.None, new AsyncCallback(Receive), Soc);
                //绑定异步连接
                tcp.BeginAcceptSocket(new AsyncCallback(AcceptSocketCB), tcp);
            }
        }
        //客户端套接字
        Socket Soc = null;
        private void Receive(IAsyncResult ar)
        {
            if (!isClosing)
            {
                //保存客户端套接字
                Socket soc = (Socket)ar.AsyncState;
                int i = 0;
                try
                {
                    //异步状态读取
                    i = soc.EndReceive(ar);
                    //Soc = null;
                    ShowMsg("用户退出");
                }
                catch { }

                if (i == 0)
                {
                    //Soc = null;
                    ShowMsg("用户退出");
                }
                else
                {
                    string readData_str = Encoding.Default.GetString(buff);
                    ShowMsg(" 发言人：客户端" + "时间：" + DateTime.Now.ToString() + "  IP:" + soc.RemoteEndPoint.ToString() + "  内容：" + readData_str.Replace("\0", ""));

                    //发送
                    //string send_Str_ = "收到:" + readData_str;
                    //byte[] buff_ = Encoding.Default.GetBytes(send_Str_);
                    //soc.Send(buff_);

                    //lstMsg.Items.Add("发送的数据：" + send_Str_);
                    buff = new byte[60000];
                    //绑定异步接收数据
                    soc.BeginReceive(buff, 0, buff.Length, SocketFlags.None, new AsyncCallback(Receive), soc);
                }
            }
        }

        private void btnSend_Click(object sender, RoutedEventArgs e)
        {
            if (Soc == null)
            {
                MessageBox.Show("当前没有客户端连接！");
                return;
            }
            byte[] buff_ = Encoding.Default.GetBytes(txtMsg.Text);
            //向客户端发送数据
            Soc.Send(buff_);
        }
        private void ShowMsg(string txt)
        {
            Dispatcher.Invoke(new Action(() =>
            {
                lstMsg.Items.Add(txt);
            }));
        }
    }
}
