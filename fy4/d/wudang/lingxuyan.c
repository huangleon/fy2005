
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������������������ഫ�ƴ������������ڴˡ����������ڹ����о���
������������˯��������˯������˵��һ˯�ɰ��첻�ѡ��������ҹ�ǽ���ϻ��г�
��������������ŵġ����١����֡��˳ơ��Ը�˯�١�������м����ֽ���Сͯ��
�ڲ������䵱�ġ������󡰣�����ͬ��ͬ�ˣ����ؽ��ˡ�
LONG
	);
	set("exits", ([
		"east" : __DIR__"wudang1",
	]));
	set("outdoors", "wudang");
		set("objects", ([
		__DIR__"npc/swordboy1" : 1,
		__DIR__"npc/swordboy2" : 1,
		__DIR__"npc/swordboy3" : 1,
		__DIR__"npc/swordboy4" : 1,
	]));
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
