
inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
    set("short", "��ҶȪ");
    set("long", @LONG
���Ƴ��еķ�ҶȪ�Ƿ�Բ�������������һ����Ȫ��ˮ�����У�Ȫˮ�ʵ���,
�ʶ�������Ҷ����������ȥ����������Ч����˵�����������ٵ����á����ֵ�һ
�������ɶ�ÿ�춼�Դ�Ȫˮ��棨�����裩�����������绨�������ò��
LONG
    );
    set("exits", ([
	"north" : __DIR__"hfenglang3",
      ]));
    set("objects", ([
	__DIR__"npc/xianu": 1,
	__DIR__"npc/troublemaker": 1,
      ]) );
    set("outdoors", "fengyun");
    set("no_fly", 1);
    set("coor/x",-80);
    set("coor/y",-260);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    create_door("north","door","̴ľ��", "south", DOOR_CLOSED);

}

void init()
{
    add_action("do_jump", "wash");

}

int do_jump()
{
    object me;
    int wait;
    me = this_player();
    
    if (me->query("gender")=="����"){
    	tell_object(me, "����ү�ǵ�����Ϲתʲô��С��ײ����ʮ���\n");
    	return 1;
    }
    	
    if (me->query_temp("jiqi/in_pool"))
    		return notify_fail("���Ѿ���ϴ���ˡ�\n");
    
    message_vision(YEL"$N����������У�����һưȪˮ����Ө��ˮ��εδӷ��ҡ����Ϲ��䡣����\n"NOR,me);
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
		msg = WHT"�������شӷ�ҶȪ��վ����������ɫ΢�죬����ʪ���Ե�Խ�����������ף����Ŀɰ���\n"NOR;
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