// Room: qiongjie4.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "���");

	set("long", @LONG
�����������̸����ֶ�����Ҫüͷ���壬��Ϊ�����ֱ����ؤ�����ã�����
�Ĵ����ǳ���������󣬵���ֵ���ȴ������Щ�������ӳ��������Ȼ����Ǵ�
��������������ɥ�����ߣ���Ϊ��Զ�������ڽ�����С��������"����Ӷķ�"��
LONG);
	//{{ --- by MapMaker
	set("exits",([
	"southeast":__DIR__"qiongjie3",
	"southwest":__DIR__"qiongjie5",
	"northwest":__DIR__"nilu1",
	]) );
	//}}
	set("objects", ([
	__DIR__"npc/leprabeggar" :1,
	]) );
        set("outdoors", "shanliu");
	set("coor/x",15);
	set("coor/y",5);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
