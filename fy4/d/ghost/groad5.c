
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
                "south" : __DIR__"house2",
                "northwest" : __DIR__"groad4",
                "northeast" : __DIR__"groad6",
	]));
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
replace_program(ROOM);

}
