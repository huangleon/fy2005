inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ��");
        set("long", @LONG
ɽ·������᫣���ʯ���м���Ұ����ǿ�����ͷ����Ⱥɽ����Զ���������ڽ�
��������¼ŵ�ɽ���ȴ���˵ĵ��ϣ���¶���˼����İ�Ϣ��
LONG
        );
        set("exits", ([ 
	"southdown" : AREA_ZANGBEI"yuzhu",
	"northup" : __DIR__"road1",
	]));
        set("objects", ([
        	__DIR__"obj/grass": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
	setup();
	replace_program(ROOM);
}

 