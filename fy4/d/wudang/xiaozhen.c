
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
С���Ǻܴ󣬵�ȴ�ܷ������������䵱ɽ�ţ����м�ʹ����Сͯ��Ҳ�Ἰ��
̫��ȭ��С�򶫱����һ��֣��һ��ֺ��˵���и�С�壬�����˽���[33m��Դ��[32m������
���ٳ����߶���Ҳ��֪��������С�������ϣ����Ƕ���������[33m�䵱ɽ[32m��
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"xzroad1",
		"north" : __DIR__"bwuroad2",
		"east" : AREA_TAOYUAN"taolin",
	]));
	set("outdoors", "wudang");
	set("objects", ([ 
		__DIR__"npc/xiaotong": 2 
	]) );
	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
