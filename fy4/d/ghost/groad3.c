
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
                "southwest" : __DIR__"groad2",
                "east" : __DIR__"dating",
	]));
	set("coor/x",-40);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
replace_program(ROOM);

}
