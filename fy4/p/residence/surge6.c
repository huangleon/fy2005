inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "ŭ�θ�"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG
  
    ��������߾��޻��컧Ƶҡ�����ͺ����ϻ����˯�����Ѿ���

    ���ο���������г�Ũ��ʤ������������ĺ���Ƴ��������ع���ˡ�


LONG);
        set("exits", ([
"616" : __DIR__"userroom/lengfeng1322840549",
"615" : __DIR__"userroom/ssppmm1321158427",
"614" : __DIR__"userroom/freewell1320928496",
"613" : __DIR__"userroom/ppp1307417995",
"612" : __DIR__"userroom/dashi1302615334",
"611" : __DIR__"userroom/chong1302416450",
"610" : __DIR__"userroom/daoba1301666222",
"609" : __DIR__"userroom/jing1301532877",
"608" : __DIR__"userroom/liu1301275454",
"607" : __DIR__"userroom/hanyan1300959147",
"606" : __DIR__"userroom/fgei1297685478",
"605" : __DIR__"userroom/egei1297685434",
"604" : __DIR__"userroom/dgei1297685340",
"603" : __DIR__"userroom/cgei1297685304",
"602" : __DIR__"userroom/bgei1297685264",
"601" : __DIR__"userroom/agei1297685200",
  "down" : __DIR__"surge"+(query("floor")-1),
  "up" : __DIR__"surge"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/