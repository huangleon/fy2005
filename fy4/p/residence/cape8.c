inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "���ĺ���¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

    ת��Ʈ��һ�ι飬
    ��Ѱ�¼����˷ǣ�
    �����Ը����Υ��

    ���³�̨����ˮ��
    ��¥��áб�ͣ�
    ���ٲ�ϧ��մ�¡�

    
LONG);
        set("exits", ([
"812" : __DIR__"userroom/popo1305767562",
"811" : __DIR__"userroom/aant1305433956",
"810" : __DIR__"userroom/amonk1305332909",
"809" : __DIR__"userroom/atank1305331933",
"808" : __DIR__"userroom/diger1302152860",
"807" : __DIR__"userroom/xzh1300594212",
"806" : __DIR__"userroom/wxb1297351642",
"805" : __DIR__"userroom/milai1265716696",
"804" : __DIR__"userroom/zhutou1265716505",
"803" : __DIR__"userroom/huazi1261281471",
"802" : __DIR__"userroom/xiangnan1261281326",
"801" : __DIR__"userroom/lutao1261280708",
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
