// Room: pomen.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
���Ǽ�ʮ��ǰ���Ѹò���ķ��ӣ����������������һ�����ܽ������塣
�����������Ĵ��ţ�Ҳ�ǽ������ŵģ��ſڻ������������㻹û���ߵ����ſڣ�
���ŵ�һ�ɳ�����
LONG);
	//{{ --- by MapMaker
	set("type","house");
	set("exits",([
	"east":__DIR__"qiongjie5",
	"west":__DIR__"dufang1",
	]) );
	//}}
	set("objects", ([
	__DIR__"npc/qinge" :1,
	]) );
        set("outdoors", "shanliu");
	set("coor/x",5);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
