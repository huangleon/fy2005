inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "���ĺ���¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG
    
    �ֻ�л�˴��죬
    ̫�Ҵң�
    ���γ������������硣

    ��֬�ᣬ������
    ��ʱ�ء�
    ������������ˮ������


LONG);
        set("exits", ([
"416" : __DIR__"userroom/pluto1323017542",
"415" : __DIR__"userroom/mjj1323017374",
"414" : __DIR__"userroom/lengyu1323017090",
"413" : __DIR__"userroom/aladin1321941391",
"412" : __DIR__"userroom/fsan1299314846",
"411" : __DIR__"userroom/esan1299314748",
"410" : __DIR__"userroom/dsan1299314668",
"409" : __DIR__"userroom/csan1299314610",
"404" : __DIR__"userroom/bsan1299314434",
"403" : __DIR__"userroom/asan1299314262",
"408" : __DIR__"userroom/rrd1295917499",
"407" : __DIR__"userroom/rrc1295857744",
"406" : __DIR__"userroom/rrf1295445980",
"405" : __DIR__"userroom/rre1295439495",
"402" : __DIR__"userroom/rra1279164404",
"401" : __DIR__"userroom/rrb1279156598",
  "down" : __DIR__"cape"+(query("floor")-1),
  "up" : __DIR__"cape"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
