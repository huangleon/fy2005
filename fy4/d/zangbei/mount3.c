inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�����");
        set("long", @LONG
����壬�����˽С���ŵ�༪����ˮ��ʯ���ɽ���Ȼ���ţ������꣬�۽���
�㣬������ȡ�ѩ���±���ֱ����̵�ԭʼɭ�֡�ѩɽ���ͱڡ����¡����ӡ�������
�ݳ���ɭ�֡�Ϫ����һƬ���ס����ꡣɽ������һƬ԰�֣������˽���[33m�����[32m��
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"nianqing",
		"northeast":  __DIR__"mugecuo",
		"southdown": __DIR__"happywood",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1680);
        set("coor/y",620);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
