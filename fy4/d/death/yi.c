// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ����˾");
        set("long", @LONG
˾�ڳ����������޲�ͬ����ӡ֮���ǹض�ү�������˼�������˶��ģ�����
ǧ����ɩ�������ն������������������������ܸ����壬�����ǲ���֮ͽ����
����Ŀ��ȫ����ء�����ա�����ڣ�רա����֮�ˡ�����������ǰ�������£��㲻
�ɵ�һ���亹��
LONG
        );
        set("exits", ([
		"northwest" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/guan":1,
        ]) );
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
 
