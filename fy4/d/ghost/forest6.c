
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
		"north" : __DIR__"forest5",
		"south" : __DIR__"forest1",
		"east" : __DIR__"forest6",
		"west" : __DIR__"forest7",
	]));
	set("outdoors", "ghost");
	set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",10);
	setup();
}

void reset()
{
        ::reset();
	set("exits", ([
		"north" : __DIR__"forest5",
		"south" : __DIR__"forest1",
		"east" : __DIR__"forest6",
		"west" : __DIR__"forest7",
	]));
}