
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�������ѵ�С·��ͷ���������ɵİ�����棬��һ����ʽ���ϵ�ʯ�ݣ������
����Ҳͬ�����ӣ������¾ɵô�������ɭɭ�ĸо���������������濿ǽ����һ��
��ᣵʹ������裬����ʲô������û�С�
LONG
	);
	set("exits", ([
                "south" : __DIR__"groad6",
	]));
	set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/yexue" : 1,
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
