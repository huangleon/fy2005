inherit ROOM;
void create()
{
        set("short", "ʮ����");
        set("long", @LONG
��ʯ�ף���������ֵıؾ�֮·����·��խ��ֱ�϶�ȥ���������񴹹����ˣ�
���µ����ӣ��ֺ�������̰���˼�������������Ϸˣ�Ľݾ���
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"nantian",
  "down" : __DIR__"duisong",
]));
        set("outdoors", "taishan");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",110);
	setup();
}
void init()
{
	add_action("do_go","go");

}

int do_go()
{
if(random(4)){
this_player()->move(this_object());
return 1;
}
}
