inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",2);

  set ("short", "����¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG
    
    ����Ʈ��̾�¶� �ع������ ���첻�� �������� �������

    ��˼��������� Я�ָ���� �缱��ӿ ���۲�ϵ ��������

LONG);
        set("exits", ([
"217" : __DIR__"userroom/dnc1322306168",
"216" : __DIR__"userroom/dna1322241531",
"215" : __DIR__"userroom/loney1317998381",
"214" : __DIR__"userroom/hhbbchi1311851923",
"213" : __DIR__"userroom/cherbim1308010397",
"212" : __DIR__"userroom/roam1297314667",
"211" : __DIR__"userroom/mscx1286726856",
"210" : __DIR__"userroom/hfr1283426622",
"209" : __DIR__"userroom/cherub1281970018",
"208" : __DIR__"userroom/huoji1281965203",
"207" : __DIR__"userroom/whx1280197537",
"206" : __DIR__"userroom/extasy1277976241",
"205" : __DIR__"userroom/figure1267713606",
"204" : __DIR__"userroom/zijing1267337713",
"203" : __DIR__"userroom/czf1262240599",
"202" : __DIR__"userroom/czar1257384034",
"201" : __DIR__"userroom/fenger1254032143",
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
