
inherit ROOM;

void create()
{
	set("short", "ԭʼ����");
	set("long", @LONG
�ޱ��޼ʵĴ�����һƬ�ڰ����������ҵ��չ�Ҳ����͸�����ܵ���Ҷ���ڰ���
�����˸�ʽ������Σ�գ�ÿһ�ֶ����������������ڴ�������ʧ�˷��򣬼��ʾ���
�����������û��ָ���Ļ��������Ŀ�������΢����΢�ġ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest2",
		"south" : __DIR__"forest5",
		"east" : __DIR__"forest6",
		"west" : __DIR__"forest5",
	]));
	set("outdoors", "ghost");
	set("coor/x",-70);
	set("coor/y",30);
	set("coor/z",10);
	setup();
}

void reset()
{
	::reset();
	set("exits", ([
		"north" : __DIR__"forest2",
		"south" : __DIR__"forest5",
		"east" : __DIR__"forest6",
		"west" : __DIR__"forest5",
	]));
}