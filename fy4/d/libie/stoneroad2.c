// Room: stoneroad2.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "ʯ��·");

	set("long", @LONG
��ֻ��һ��������С�سǣ�����û�����˼ң�ֻ��һ��ʯ��·�ɹ�·��������
ʯ������̦���̣�һ��С�ı��ˤ����ͷ��·��һ���Ǽ�С�س������ֺŵġ���
����ջ������һ�������������������Ҿɵİ��	
LONG);

	//{{ --- by MapMaker
	set("type","street");
	set("exits",([
	"east":__DIR__"stoneroad",
	"south":__DIR__"yuelai",
	"north":__DIR__"darklane1",
	]) );
	//}}
		    set("objects", ([
        __DIR__"npc/oldman" : 1,
    ]) );
        set("outdoors", "libie");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);


	setup();
	replace_program(ROOM);
}
