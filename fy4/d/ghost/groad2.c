
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
                "northwest" : __DIR__"groad1",
                "northeast" : __DIR__"groad3",
                "south" : __DIR__"xting",
	]));
	set("coor/x",-50);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
replace_program(ROOM);

}
