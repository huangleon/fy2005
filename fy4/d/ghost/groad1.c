
inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
·�����ԣ��и�ʽ��������ľ������Щ��֪���Ļ��ݡ����������յ�ʱ����
ɽ��һ��������������ɽ�����ǲ���Ҳ���������յ�ʱ������ɽ���ȵİ�����
����Ҳ����ɢ��ʱ���أ�
LONG
	);
	set("exits", ([
                "west" : __DIR__"ghost",
                "southeast" : __DIR__"groad2",
	]));
	set("objects", ([
                __DIR__"npc/dog" : 1,
	]));
	set("coor/x",-60);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
