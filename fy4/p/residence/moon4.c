inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "����¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG
  
    ������Զ�˹�ȥ   Ц����ƾ   ˽������   �������������

    �����̻ڷ�����   ���γɿ�   ��������   ң������˷ѩ��
    
LONG);
        set("exits", ([
"412" : __DIR__"userroom/suki1296525346",
"411" : __DIR__"userroom/sqfy1294493903",
"408" : __DIR__"userroom/txfy1287967780",
"407" : __DIR__"userroom/itxfy1287967755",
"406" : __DIR__"userroom/txstrong1287475828",
"409" : __DIR__"userroom/xgfy1292387730",
"410" : __DIR__"userroom/ctfy1292381357",
"405" : __DIR__"userroom/xgstrong1286722740",
"404" : __DIR__"userroom/hstrong1286601469",
"403" : __DIR__"userroom/fgfy1285488091",
"402" : __DIR__"userroom/gbfy1285394750",
"401" : __DIR__"userroom/maidou1258712899",
  "down" : __DIR__"moon"+(query("floor")-1),
  "up" : __DIR__"moon"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
