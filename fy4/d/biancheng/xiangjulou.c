inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���¥");
        set("long", @LONG
��ط�����û�����֣���ȴ�Ǹ���������֮���������ĵط��������а���ʮ��
�����ӣ�������ѡ����һ�����������������������ܵ���õľƲˣ�������Ҫ����
��ģ��͵����š�����������ʮ�����š����������������߽�ȥ�����������ڣ�
Ҳ����ʧ���������ĺ��滹�е��ܸߵ�¥�ݡ�û����֪��¥����ʲô�ط���Ҳû��
����¥ȥ������Ϊ�����������¥����������Ҫ����ʲô��¥�¶��С�
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"road5",
	"up": __DIR__"xiangjulou2",
	]));
        set("objects", ([
        	__DIR__"npc/bieli": 1,
        	__DIR__"npc/dinglinglin":	1,
        	__DIR__"npc/dinglingzhong":	1,
        	__DIR__"npc/dinglingjia":	1,
        	__DIR__"npc/dingyunhe":		1,
	]) );
        set("coor/x",-40);
        set("coor/y",10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
