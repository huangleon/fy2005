
inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
ͥԺ�����Ũ����ǡ�ľҶ��в���ҡҷ��ȴ�ĵ���ؼ���Ǽž����쳾��
�����ַ��ţ����ѳ���δ��ͥԺ��
LONG
	);
	set("exits", ([
		"north" : __DIR__"wuroad1",
		"south" : __DIR__"qiongtaiguan",
	]));
	set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
