inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��ͨ������ɽׯ�����ɽ�������԰�ݵ������Ϧ���¿�������ƽ�
��صĻƽ�ʯ�����ɵ�С��б���Ϸ���չ������ƽ���е�һ������������ȥ��
�ƺ��м乩·��ЪϢ�İ˽�Сͤ��
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "westup":__DIR__"shandao4",
        "southdown":__DIR__"shandao6",
	]) );
	set("coor/x",10);
	set("coor/y",150);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}
