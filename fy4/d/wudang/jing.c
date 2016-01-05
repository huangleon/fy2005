
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
	set("underwater",120);
	set("water_damage",20);
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
    object sword, box ;
    
    if(!(this_object()->query("marks/û��")))
    {
        kar = (int)me->query_kar();
        if( kar > 40 ) kar = 40;
		
        if( (random(40 - kar) < 5)  
        	&& (REWARD_D->riddle_check(me,"�ž�����") == 4 
        		|| REWARD_D->riddle_check(me,"�ž�����") == 5
        		|| REWARD_D->riddle_check(me,"�ž�����") == 6
        		|| REWARD_D->riddle_check(me,"�ž�����") == 7
        		))	// realistically, killing guo or not shouldn't affect search result.
        {
            this_object()->set("marks/û��", 1);
            message_vision(HIY "$N�ҵ���һ���������У��Ž��˻��\n"NOR, me);
            me->set_temp("marks/���ǽ�", 1);
            me->ccommand("remove all");
            seteuid(geteuid(me));
            sword = new(__DIR__"obj/msword2");
            box = new(__DIR__"obj/box");
            sword->set_temp("marks/owner", me);
            sword->set_temp("marks/owner_name",me->query("id"));
            sword->move(box);
            box->move(me);
			REWARD_D->riddle_set(me,"�ž�����",7);
        }
        else message_vision("$Nʲô��û�ҵ���\n", me);
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
        me->start_busy(1);
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
        me->set_temp("marks/��ʱ", 0);
        me->move(__DIR__"wudang3.c");
        message_vision("$N��ˮ��ʪ���ܵ����˳�����\n", me);
    }
    else message_vision("$N����һ��ûץ�ȣ��ֵ���������\n", me);
    return 1;
}


void reset()
{
    ::reset();
    delete("marks/û��");
}
