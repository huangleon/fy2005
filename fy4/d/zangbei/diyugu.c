inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����������");
        set("long", @LONG
���๱�����ɹ���������ǰ�������㿴��������֦��һ���ޱ��޼ʵ�ɡ����ס
�����⣬��ס����գ����ó�ʪ����Ҷ�ڽ��·�����֨�����������ܵ���֦������
��Ұ�ݲ�ʱ��סȥ·������ÿ��һ��·��Ҫͣ����ЪһЪ����������Ũ�ص���ʪ��
Ϣ������������
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"diyugu2",
	]));
        set("objects", ([
        	__DIR__"npc/wolf":	4,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1720);
        set("coor/y",620);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

int valid_leave(object obj, string dir){
                        
        message_vision( MAG "·�����ˣ����������ʪ֮��Ѭ���˻����˯������\n"NOR,obj);
        if (userp(obj))
        if(!obj->query_condition("mag_mushroom") 
        	&& random(obj->query_skill("perception",1))<50){
            obj->apply_condition("mag_mushroom",random(20)+5);
            message_vision(HIM"$N���ɵ�������һ������\n"NOR,obj);
        } else  
        	message_vision( HIW"$N�����Ķ�����æ��ס������\n"NOR,obj);
        return 1;
}
