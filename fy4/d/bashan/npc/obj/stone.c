#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
	set_name(HIW"�춼ˮ��"NOR, ({"moon stone" }));
    set_weight(200);
	if( clonep() )
			set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "һö����ϡ�к�����ˮ���񣬴��ֱ�����\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("no_stack",1); 
	}
	::init_neck();
}

void protect(object me)
{
	int skill;
	object *pros;
	pros = me->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	me->set_temp("protectors",pros);
	set("owner",me);
}

void dest()
{
	object me;
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
	set("protected", 1);
	return 1;
}

string protection_msg()
{
	return WHT"$N����ʽ����$n����Ϊ�춼ˮ����ɢ����һ��΢�����衣\n"NOR;
}


void init()
{
	protect(this_player());
	if (query("owner"))
		if (query("owner") != this_player())
			dest();
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
