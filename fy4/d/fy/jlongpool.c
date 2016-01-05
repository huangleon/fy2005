inherit DOOR_ROOM;
#include <room.h>
#include <ansi.h>

void create()
{
    set("short", "����ԡ��");
    set("long", @LONG
һ���ţ��������棬�װ׵�ˮ�����̰�Χ���㡣����ϡ����һ���޴��̴ľˮ��,
ˮ�ʱ��̣�ɢ����һ�����ص�ҩ�㣬ˮ���ϻ�Ư��һƬƬ���Ļ������������һ��
�����������𣩽�ȥ�������۾��úõķ���һ�¡�
LONG
    );
    set("exits", ([
	"south" : __DIR__"jlonglang3",
      ]));
    set("objects", ([
	__DIR__"npc/xianu": 1,
	__DIR__"npc/troublemaker": 1,
      ]) );
    set("no_fly", 1);
    set("coor/x",-80);
    set("coor/y",-140);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    create_door("south", "door","̴ľ��", "north", DOOR_CLOSED);

}

void init()
{
    add_action("do_jump", "jump");

}

int do_jump()
{
    object me;
    int wait;
    me = this_player();
    
    if (me->query("gender")=="Ů��") {
    	tell_object(me,"��ô������˿��ţ�����ô����˼ϴ���أ�\n");
    	return 1;
    }
    	
    if (me->query_temp("jiqi/in_pool"))
    		return notify_fail("���Ѿ���ϴ���ˡ�\n");
    
    message_vision(YEL"$N��ͨһ������Ȫ�У���ˮ�����������˵�����$N��������Ħ��������\n"NOR,me);
    if(!me->query("����B/�䵱_��Ҷ") && !random(10))
		call_out("give_maple_leaf",5,me);
    me->set_temp("jiqi/in_pool",1);
	me->add_temp("jiqi/pool_num",1);
	
	call_out("done_pool",20, me);
	return 1;
}


int give_maple_leaf(object me)
{
    object leaf;

    if(!me || !present(me,this_object()))
	return 1;
    tell_object(me,"һƬ���ķ�ҶƮ�˹����������Ľ���ʰ��������\n");
    leaf=new("/d/fy/obj/mapleleaf");
    leaf->move(me);
    return 1;
}


void done_pool(object me)
{
    int gin,kee,sen;
    string msg;
    
    if(!me)	return;
    	
    if ( me->is_ghost() || environment(me)!= this_object()) 
    {
    		me->delete_temp("jiqi");
    		return;
    }
    
       	
    if (me->query_temp("jiqi/pool_num")>=3) {
		msg = WHT"��ӷ�ҶȪ��һԾ���𣬻����������ڣ�͸���ò���ľ�����\n"NOR;
		tell_object(me, msg);
		me->delete_temp("jiqi");
		me->full_me();
	} 
	else {
		tell_object(me,"��е�ȫ���ޱȵ���̩���̲�ס�����ϴһ�Ρ�������\n");
		me->delete_temp("jiqi/in_pool");
	}
	
    return;
}


int valid_leave(object me, string dir){
	
	me->delete_temp("jiqi");
	return ::valid_leave( me, dir);

}