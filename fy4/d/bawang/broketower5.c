#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�������");

	set("long", @LONG
���Ƕ�������㡣���������ҳ���һ��������ķ��⣬�����ƺ�ʲô��û�С�
���洰���Ϻ�����ֽ�Ѳ����ˣ����紵�á����������������졣Խ�ߵ����棬��Խ
������Խ�죬�����Ҳ����Խ�졣�����ߵ�ľ�ݸ����ưܣ��ƺ���ʱ��������
������
LONG);

	set("type","street");
	set("exits",([
		"up":__DIR__"toptower",
		"down":__DIR__"broketower4",
	]) );
	set("objects", ([
		__DIR__"npc/ghost": 2,
	]));
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",30);
	setup();
}

/*int valid_enter(object me)
{
	tell_object(me,HIM "\n
		
�������ͷ���ϵĶԻ���Խ��Խ������

������Ϊ�Ҳ���������
������������֮�У�����һ���ǲ������ġ���
����������������֮�У����Ʊ�ֻ��һ���ܻ��Ż�ȥ����
\n\n"NOR);
	return 1;
}*/
