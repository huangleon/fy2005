// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�Ϲ�Ǯׯ");
        set("long", @LONG
��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����˼�Ǯׯ���Һ��֣������Ϲ�
��ҵ֮һ���Ϲ�Ǯׯ����Ʊ�������ã����ϱ����ɶ��֡����Ǹ��ɵй��Ľ�Ǯ
�Ҳ���������Ǯׯ������һ��ľ��̨�����˶�ߣ������ƣ�����һ�顣
LONG
        );
	set("exits",([
  		"west" : __DIR__"nandajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}