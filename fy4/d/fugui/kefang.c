#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ջ˯��");
        set("long", @LONG
��ջ��һ��˯��������ɸɾ�����һ�Ŵ󴲣�����������Ϣ˯���������и���
�ˣ���ͷ����ģ�����ȥ�����ˡ����䴰�����ţ�������Ǽ�����Ľֵ���
LONG
        );
        set("type","house");
        set("exits",([
                "down":__DIR__"kezhan",
        ]) );
        set("objects",([
                __DIR__"npc/xianggong" : 1,
        ]));
	set("coor/x",10);
	set("coor/y",110);
	set("coor/z",10);
        setup();
}

void init()
{
	object me;

        if( interactive(me = this_player()) ) 
        {
            remove_call_out("greeting");
            call_out("greeting", 1, me);
        }
}

int greeting(object me)
{
		object room;

		if ( !(me) || environment(me)!= this_object()
			|| me->is_ghost() || me->is_busy())	return 1;
			
        if( userp(me) && me->query("age")<16 )
        {
                room = find_object("/d/fugui/xiaojie1");
			if(!objectp(room)) 
				room = load_object("/d/fugui/xiaojie1");
			message_vision(HIY"ͻȻ������$NĪ������ı��˴Ӵ����ӳ�ȥ������\n"NOR,me);
			me->move(room);
			me->set_temp("last_damage_from","�Ӵ��ڵ���ȥˤ���ˡ�\n");
			me->receive_damage("kee",50);
			message_vision(CYN"\n$N������������ֹ���˭�ҵ�С������ôС��ȥ���ֵط�������\n"NOR,me);
			COMBAT_D->report_status(me);
		}
		return 1;
}