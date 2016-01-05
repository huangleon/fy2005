// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "���춫��");
        set("long", @LONG
һ�˶�ߵ���Ģ��һ��Ƭ������ֲ��ı�Ƥ��Ӳ�������ر�Ĵֲڡ�����·��
�����Ǵ�Ģ���п������ģ�·����Ȼ���������Կ�������·һ�����˺ܴ�Ĺ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "north" : __DIR__"ntdl",
		  "south" : __DIR__"dnj",
		]));
        set("indoors", "cave");
		set("coor/x",10);
		set("coor/y",-12);
		set("coor/z",0);
		setup();

}


int valid_leave(object obj, string dir){
	object another;
	seteuid(getuid());
	    	
	message_vision( HIM "·�����ˣ���Ģ��Ʈ���ŵ�����������ϡ�������\n\n"NOR,obj);
    if(!obj->query_condition("mag_mushroom") 
    	&& random(obj->query_skill("perception",1))<50){
        obj->apply_condition("mag_mushroom",random(20)+10);
        message_vision(HIM"$N���ɵ�������һ������\n"NOR,obj);
    } else  
    	message_vision(WHT"$N�����Ķ�����æ��ס������\n"NOR,obj);
    		
	return 1;
}
