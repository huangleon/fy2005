#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"��Ũ�μ���"NOR);
        set("long", @LONG
�������ܡ���ɲ��֮�䣬��������ܾ�ȫ�������ˡ��ˡ�����Щ���Ʈ�ɣ���
Щ�������֣������ĺ���֮�ڸ��ǲ�����������Щ���ˡ�Ҳ��֪���Ժη���������
һֱ�����ڣ����ڲ�������������ǲ����ǡ��ˡ�����������ħ������ʮ�ص���ħ��
��ʽ��������ħ�����У����У��һ��У������У�û��һ���ط���������Щ��ħ��
LONG
        );
        set("exits", ([ 
		"south":  __DIR__"dream7",
		"north":  __DIR__"dream5",
	]));
        set("objects", ([
        	__DIR__"npc/evil6": 1,
    	]) );
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


int valid_leave(object me,string dir) {
        object evil;
	
	if( userp(me) && dir == "south") {
		evil=present("evil",this_object());
		if (evil) 
		if (!evil->query("statue")){
			message_vision(HIW+evil->name()+"��ס��$Nǰ���ĵ�·��\n"NOR,me);
			return notify_fail("");
		}
	}
	return 1;
}