inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�뷿");
        set("long", @LONG
�����Ѿ���һ����ɨ��ü����ʩ֬�۵����ˣ������������������ڴ��ڣ���
�յؿ���Ժ�ӡ�������Ҳ������̫������ȴ��˫��˵�����۾������ɵ��졣����
Ȼֻ�Ǿ��������������ȴ��Ȼ���������˵ķ��˺����ʡ�
LONG
        );
        set("exits", ([ 
	"out": __DIR__"xiaojinku2",
	]));
        set("objects", ([
        	__DIR__"npc/cuinong":	1,
	]) );
        set("coor/x",-40);
        set("coor/y",-20);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
