
inherit ROOM;

void create()
{
	set("short", "ʯӢ��ʯ��");
	set("long", @LONG
��������һ��������ʯӢ�ҽ�����, ���ݵ�������ֲ��һ�Ÿ��ʵ�������̧ͷ
������������������ͦ�ε�ɽ��, ����Ʈ���ɽ���ϴ�����һ����ΰ�İ�ɫ¥��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road4",
  "southdown" : __DIR__"road2",
]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",-40);
	setup();
	replace_program(ROOM);
}
