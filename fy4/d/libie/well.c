
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "ˮ����");
    set("long", @LONG
��ˮ�����������������ܾ��ڻ������֡��������ڲ�������֪��β��ܳ�ȥ��
���л������ģ�����ʲô��û�С������������һ�£�Ҳ���������֡�
LONG
	);
    	set("item_desc", ([
        	"wall": "�������ֵľ��ڡ������������(climb)��ȥ��\n",
        	"����": "�������ֵľ��ڡ������������(climb)��ȥ��\n",
	]) );
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",-90);
	set("corpse",1);
	set("underwater",120);
	set("water_damage",30);
	setup();
}

void init()
{
   	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
	add_action("do_climb", "climb");
    	add_action("do_search", "search");
}


int do_search(string arg)
{
    	object ob;
    
    	ob = this_player();
    	if( ob->is_busy() )
        	return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
	
	message_vision("$N��ϸ�Ĳ鿴���ܵľ��ڣ��ѱ��˸������䡣\n", ob);
    	ob->start_busy(2);
    	call_out("search_obj", 4, ob);
    	return 1;
}

int search_obj(object me)
{
    	int kar;
    	int exp;
    	object corpse;
    
    	if (query("corpse") && !random(3))
    	{
    		tell_object(me,"���Ȼ����һ����������壬���ֱ�������Ȼ�Ѿ���ȥ�����ˡ�����\n");
    		if (corpse = new(__DIR__"obj/lian_corpse"))
    			corpse->move(this_object());
    		me->set_temp("libie/lian_corpse",1);
    		set("corpse",0);
    	}
    	        else message_vision("$Nʲô��û�ҵ���\n", me);
        return 1;
}

int do_climb(string arg)
{
    	object obj, me;
    	int	kar;
    
    	if(!arg || arg=="") return notify_fail("��Ҫ����������\n");
    	me = this_player();
    	if( arg == "wall" || arg == "����" || arg == "up")
    	{
        	if( me->is_busy() )
            		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
        	message_vision("$Nʹ�����̵�������˳�ž���������ȥ��\n", me);
        	me->perform_busy(1);
        	call_out("climb_wall", 2, me);
        	return 1;
    	}
    		return notify_fail("�㲻������"+arg+"��\n");
}       

int climb_wall(object me)
{
    	int kar;
    	if (me->is_ghost()) return 0;
    	kar = (int)me->query_kar();
    	if( kar > 60 ) kar = 60;
    	if( random(60 - kar) < 15 )
    	{
        	me->move(__DIR__"yard.c");
        	message_vision("$N��ˮ��ʪ���ܵ����˳�����\n", me);
    	}
    	else 
    		message_vision("$N����һ��ûץ�ȣ��ֵ���������\n", me);
    	return 1;
}
