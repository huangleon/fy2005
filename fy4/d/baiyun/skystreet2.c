//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "���");
    set("long", @LONG
�߽����ţ�һ�����ֱ�ֱ��ǰ����û��ͤ��֮�С���ֵ�����������ͨ���ĳ���
�������빤ֱ�������о�������һ������ׯ�µ�������������ס��������Ц�⡣
LONG
    );
    set("exits",
      ([
	"north" : __DIR__"3xian",
	"west" : __DIR__"gallery",
	"east" : __DIR__"musicshop",
	"south" : __DIR__"fightdoor",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-180);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
