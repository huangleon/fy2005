// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"���Ǿ���"NOR, ({"wall of ice","ice shield","wall","shield" }));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "��");
			set("long", "һȦ��Ө��͸�ı������������ܵ���������ߡ�\n");
            set("value", 0);
			set("no_get", 1);
			set("no_give", 1);
			set("no_drop", 1);
			set("no_sell", 1);
			set("no_burn", 1);
			set("no_stack",1);
			set("p_amount",10);
        }
	::init_item();
}

void protect(object me,int level)
{
	int skill;
	object *pros;
	skill = me->query_skill("snowforce",1);

	if (level >= 2)
		set("p_amount",20);
	if (level >= 3)	
		set("p_amount",30);
	
	pros = me->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	me->set_temp("protectors",pros);
	set("owner",me);
	skill = 60;
	call_out("dest",skill);
}

void dest()
{
	object me;
	me = query("owner");
	if (me)
		message_vision(HIW"$N��߱������ܽ⣬��ΪһƬˮ��\n"NOR,me);
	destruct(this_object());
}

void rmp(object me)
{
	object *pros;

	if (!me) return;
	pros = me->query_temp("protectors");
	pros -= ({ this_object() });
	me->set_temp("protectors",pros);
	return;	
}

void remove_all_killer()	// ��Ϊdestruct��ʽ�к��������func����itemû��ԭ���壬��˿������������protect��ֹ����
{
	rmp(query("owner"));
//	::remove_all_killer();
	return;
}

int protection() {
	int result;
	
	result = random(100) > query("p_amount") ? 0 : 1;
	set("protected", result);
	return result;
}

string protection_msg()
{
	return query("protected") ? WHT"$n"WHT"΢Ų��ߣ�$N"WHT"������������$n"WHT"������֮�ϡ�\n"NOR : "";
}


void init()
{
	if (query("owner"))
		if (query("owner") != this_player())
			dest();
}

/*
HIW"$N���ֺ�Ŀ����߰������ƣ��������ڣ�������ʱ���������տȻ��\n"NOR,
*/