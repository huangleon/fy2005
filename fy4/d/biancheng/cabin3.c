inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ľ��");
        set("long", @LONG
����һ����������һ������ݣ������ü���վ�ž��ѿ촥�����ܡ����ó�������
̫�¾ɣ�������ձ���˥�����ˣ���ʱ���е�����Σ�ա��Ű����õ����顣��ǽ�ϵ�
����С����������ϯ�Ҳݡ��м�����ݵĴ������Ÿ��ˣ���ʱ����ѹ�ֲ�ס����������
LONG
        );
        set("exits", ([ 
	"east": __DIR__"smallroad3",
	]));
        set("objects", ([
        	__DIR__"npc/sickwoman": 1,
		__DIR__"npc/sickman":	1,
	]) );
	set("coor/x",-60);
        set("coor/y",-30);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}
