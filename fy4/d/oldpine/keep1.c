// Room: /d/oldpine/keep1.c

inherit ROOM;

void create()
{
        set("short", "����կ��");
        set("long", @LONG
����ֻ��һ��ľͷ��ɵĴ��ţ��ſ��Ϲ����ġ�����Ĳ�֪����ʲ�ᶯ���ͷ
�ǣ�ͷ���Ѿ�����ͷ�ˣ�����������һ��Ǭ�ݵ���֦��������һ�����߰�����ɭ��
�ﻹ�治���׷��֡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"west" : __DIR__"pine2",
  		"east" : __DIR__"keep15",
	]));
        set("objects", ([ /* sizeof() == 1 */
  		__DIR__"npc/bandit_guard" : 4,
	]));
        
	set("coor/x",30);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
