inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "ժ��¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG
    
    ������   ������   ҶҶ�����Ǳ���   �꼱�˸���

    �潭��   ������   ��ˮǧɽԶ·��   ���������

LONG);
        set("exits", ([
"414" : __DIR__"userroom/rxy1312683760",
"413" : __DIR__"userroom/rcy1312570407",
"412" : __DIR__"userroom/blw1296569368",
"411" : __DIR__"userroom/ldw1296568902",
"410" : __DIR__"userroom/tgw1296567328",
"406" : __DIR__"userroom/fyue1295362815",
"405" : __DIR__"userroom/eyue1295362771",
"404" : __DIR__"userroom/dyue1295362701",
"403" : __DIR__"userroom/cyue1295362637",
"408" : __DIR__"userroom/ray1293977639",
"409" : __DIR__"userroom/thor1291006437",
"407" : __DIR__"userroom/roy1293977963",
"402" : __DIR__"userroom/byue1295362563",
"401" : __DIR__"userroom/ayue1295362180",
  "down" : __DIR__"star"+(query("floor")-1),
  "up" : __DIR__"star"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
