
inherit ROOM;

void create()
{
	set("short", "�䵱ǰԺ");
	set("long", @LONG
��Ժ����������������������Ե��䵱�ɵ���ʷ�ƾá���ʯ���̳ɵĵ��棬��
��������ĺۼ�����Ժ�ľ�ͷ�Ǽ�������ʯ̨�ף�����̨�׾����䵱�����������
����һ����ʯС·��ͨ�����档
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"zhixiao",
		"west" : __DIR__"lingxuyan",
		"northeast" : __DIR__"wuroad1",
		"out" : __DIR__"wudang",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
