// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ�����");
        set("long", @LONG
���Ʋҵ�֮��һƬ���������������಻�����˼䣬��˵�������ڴ�·��������
֮�ˣ����ǵظ��а����ؼ������񣬵ظ����ɭ�ϸ����˼䣬ʮ�˲�����ܾ�����
���ˣ����Դ�·����̫ƽ��������˳·ǰ�б����ֹ���

LONG
        );
        set("exits", ([
                "north" : __DIR__"gate",
		"south" : __DIR__"naihe2",
        ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	set("no_fight",1);
	set("no_magic",1);
	setup();
        replace_program(ROOM);
}
 
