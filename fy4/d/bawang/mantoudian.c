#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ����ͷ��");

	set("long", @LONG
		����ɽ��������ͷ���� 
ɽ�����Ǽҡ���ɽ����ͷ�ꡱ������ͷ����ʸ��Ѻ��ϣ���������ƣ����������
���ѱ���Ѭ�÷����ˡ�������ϰ塢���á����ӣ�����ͬһ���ˣ������û��ʲô
�ر𣬴�Ҷ�����������ɽ����
LONG);

	set("type","street");
	set("exits",([
        "west":"/d/wudang/xzroad4",
	]) );
	set("objects", ([
		__DIR__"npc/oldshan": 1,
	]));
	set("coor/x",-30);
	set("coor/y",120);
	set("coor/z",-70);

	set("indoors", "bawang");
	setup();
	replace_program(ROOM);
}
