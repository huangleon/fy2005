inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "����¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG
  
    �����   ���������࿴   ���������˸�Զ   ���뷽����
        
    ���οմ���Թ   ���ɳ�Եδ��
        
    �����ȪѰ�ٱ�   �����첻��
    
LONG);
        set("exits", ([
"713" : __DIR__"userroom/jadez1323066474",
"712" : __DIR__"userroom/quartz1304841321",
"711" : __DIR__"userroom/zhouwin1303924174",
"710" : __DIR__"userroom/niupi1303830917",
"709" : __DIR__"userroom/khlc1302496826",
"708" : __DIR__"userroom/khlf1302330908",
"707" : __DIR__"userroom/khle1302330554",
"706" : __DIR__"userroom/khla1302330278",
"705" : __DIR__"userroom/khld1302290645",
"704" : __DIR__"userroom/myy1301490981",
"703" : __DIR__"userroom/dumio1255524957",
"702" : __DIR__"userroom/asnow1254754761",
"701" : __DIR__"userroom/shbin1254754648",
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