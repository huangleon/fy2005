inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    欲上高楼去避愁，愁还随我上高楼。经行几处江山改，多少亲朋尽白头！

    归休去，去归休，不成人总要封侯。浮云出处元无定，得似浮云也自由。
    
LONG);
        set("exits", ([
"712" : __DIR__"userroom/qinyan1305165451",
"711" : __DIR__"userroom/feiyan1305165015",
"710" : __DIR__"userroom/fengyan1304583637",
"709" : __DIR__"userroom/mickk1304098122",
"708" : __DIR__"userroom/xingguo1303034021",
"707" : __DIR__"userroom/daobaaa1303012418",
"706" : __DIR__"userroom/taoguliu1300024597",
"705" : __DIR__"userroom/taoguwu1300024529",
"704" : __DIR__"userroom/taogusi1300024459",
"703" : __DIR__"userroom/taogusan1300024381",
"702" : __DIR__"userroom/taoguer1300024143",
"701" : __DIR__"userroom/taogu1300022845",
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