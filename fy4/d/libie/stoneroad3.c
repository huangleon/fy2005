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
	"south":"/d/fycycle/road5",
    "west":__DIR__"stoneroad",
    "east":__DIR__"stoneroad4",
	"southeast":__DIR__"zhangstall",
	]) );
	//}}

        set("outdoors", "libie");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
