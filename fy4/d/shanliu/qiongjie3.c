// Room: qiongjie3.c --- by MapMaker

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
	"northeast":__DIR__"qiongjie2",
	"northwest":__DIR__"qiongjie4",
	]) );
	//}}
	set("objects", ([
	__DIR__"npc/snakebeggar" :1,
	]) );
        set("outdoors", "shanliu");
	set("coor/x",25);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
