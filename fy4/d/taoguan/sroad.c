inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�ϱ������������������ɽ�����֣�������һ��ɽ�꣬��������ͨ�����Ƴǵ�
�ϱ������������ɽ·��һ�����ѵ�С������չ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"westup" : __DIR__"road1",
  		"eastdown" : AREA_LAOWU"road2",
]));
	set("outdoors", "taoguan");
	set("coor/x",10);
	set("coor/y",-110);
	set("coor/z",-70);
	setup();
	replace_program(ROOM);
}
