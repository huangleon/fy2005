//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "���ڵ�");
    set("long", @LONG
���в�Զ��һ����ΰ׳���Ĵ���������ǰ�������������ڿ�����ͥԺ�º͸ߴ�
�Ľ�����ǰ����ν��ߵع㣬����Ȼ����С����Ȼ����һ�֡�Ψ�Ҷ��𡱵���������
����
LONG
    );
    set("exits", 
      ([
	"north" : __DIR__"fightdoor",
	"south" : __DIR__"jietiandian",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-220);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
