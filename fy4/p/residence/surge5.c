inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "ŭ�θ�"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG
  
    ���촺ѩ�����ŵ�÷���롣�ѩ���ˣ���Щ�ó��ҡ�

    ѩ��ƫ������ֻҪ������˭��ѩ�캮����������ů��
    
LONG);
        set("exits", ([
"517" : __DIR__"userroom/laowud1308240892",
"516" : __DIR__"userroom/laowub1307772762",
"515" : __DIR__"userroom/laowua1307164820",
"514" : __DIR__"userroom/wenwan1307102170",
"513" : __DIR__"userroom/senditd1306929111",
"512" : __DIR__"userroom/nongyan1300956378",
"511" : __DIR__"userroom/xuan1300942433",
"510" : __DIR__"userroom/ntek1300898907",
"509" : __DIR__"userroom/nicol1300367568",
"508" : __DIR__"userroom/saite1300254229",
"507" : __DIR__"userroom/xling1299740248",
"506" : __DIR__"userroom/linyan1299665088",
"505" : __DIR__"userroom/han1299489606",
"504" : __DIR__"userroom/hyong1299475371",
"503" : __DIR__"userroom/hyue1299075601",
"502" : __DIR__"userroom/kankan1277332540",
"501" : __DIR__"userroom/blowxiao1275805767",
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
