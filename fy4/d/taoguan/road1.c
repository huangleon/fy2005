
inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����ǰ��һ����ͨ��ɽ�壬һ������ܿ�Ҳ����ܶ���ɽ���ӱ������������ţ�
�����ɽʯд�ţ�����ɽ���������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		  "northup" : __DIR__"road2",
		  "eastdown" : __DIR__"sroad",
	]));
	set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/tao_1" : 1,
	]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",-60);
	setup();
	replace_program(ROOM);
}
