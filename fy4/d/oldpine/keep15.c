// Room: /d/oldpine/keep1.c

inherit ROOM;

void create()
{
        set("short", "ɽկ��Χ");
        set("long", @LONG
����̩ɽ�м���֮��������ɽ�����ƣ���ϼ��������ʯ�����֣����͵��֣�ʵ
���������ѹ�֮�أ�ǧ���������������ֺú�ռɽΪ�������������ж��ҸͶ���
������Ҫ�ɼ�һ�ߣ������Կɼ�����ɽկģ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
 	 "west" : __DIR__"keep1",
  	"east" : __DIR__"keep2",
]));
        set("objects", ([ /* sizeof() == 1 */
  		__DIR__"npc/bandit_guard" : 4,
	]));
        
	set("coor/x",40);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
