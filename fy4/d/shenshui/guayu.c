// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "���Ĺ���¥");
    set("long", @LONG
˵����¥����ʵ�յ���Ҳ��ֻ�ǱȽϸߴ�����Զ������¥��ǰ��һ�����ң�
���飭���Ĺ������֣�¥�г���һ��������һ�����У�������Ψһ�������ƺ�����
������֮�ϱ�Ŀ����
LONG
        );
   	set("exits", ([ 
      "south" : __DIR__"huayuan",
      "north" : __DIR__"shenshui",
   ]));

/*   set("item_desc", ([
      "putuan" : "һ���ذ׶������ɵ����ţ����������õġ�\n",
      "����" : "һ���ذ׶������ɵ����ţ����������õġ�\n",
   ]) );	*/
   
	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}

/*
void init()
{
   add_action("do_sit", "sit");
}

int do_sit(string arg)
{
   object me, obj;

   me = this_player();
   obj = this_object();
   if(obj->query_temp("marks/taken")) return notify_fail("���������ˡ�\n");
   if((int) me->query("sen") <=50) return notify_fail("����񲻹���\n");
   message_vision("$N�ߵ�����֮�����������������۾���\n", me);
   me->start_busy(2);
   obj->set_temp("marks/taken", 1);
      me->set_temp("disable_inputs",1);
      me->add_temp("block_msg/all",1);
      me->set_temp("is_unconcious",1);
      me->set("disable_type",HIG "<������>"NOR);
   call_out("ling", 5, me);
   return 1;   
}

void ling(object me)
{
   int llvl;
   if(!me || me->is_ghost()) return;
   	
   llvl = (int)me->query_kar();
   me->receive_damage("sen",20+random(30));
   if( (int)me->query("bellicosity") > 0)
   me->add("bellicosity", - (random((int)me->query_kar()) + 7 ) );
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
   me->delete_temp("is_unconcious");
   tell_object(me, "�������㵽�����ҵľ��磬ֻ����������һƬ���塣\n");
   this_object()->set_temp("marks/taken", 0);
   return;
}
*/