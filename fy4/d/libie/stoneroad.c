// Room: stoneroad.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "ʯ��·");

	set("long", @LONG
С�س��б�ֻ��һ��ʯ��·�ɹ�·��������·���������������м����˼ң�ʯ
������̦���̣�һ��С�ı��ˤ����ͷ��Զ����һƬ÷�֣�������Ʈ������������
��÷�ӳ����ζ����	
LONG);

	set("type","road");
	set("exits",([
	"west":__DIR__"stoneroad2",
	"north":__DIR__"yard",
    "east":__DIR__"stoneroad3",
	]) );
	//}}
			    set("objects", ([
        __DIR__"npc/huasiye" : 1,
            ]) );
        set("outdoors", "libie");
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);

	setup();
	replace_program(ROOM);
}
