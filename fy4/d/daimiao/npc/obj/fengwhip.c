#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
	set_name(MAG"������"NOR, ({ "whip" }) );
	set_weight(2000);
	if( clonep() )
			set_default_object(__FILE__);
	else {
			set("unit", "��");
			set("long", "����һ����ɫ��˿����һ�˹��Ÿ���ɫ������");
			set("value", 10000);
			set("material", "silk");
	}
	::init_whip(10);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (userp(me) && query("used"))
		return 0;
	if (!userp(victim))
		return 0;
	if (random(damage_bonus) < 250)
		return 0;
	if (userp(me))
		set("used",1);
	remove_call_out("do_soulcurse");
	call_out("do_soulcurse",1,me,victim);
}
 
void do_soulcurse(object me,object victim)
{
	object corpse,room;
	if(!me||!victim||!me->is_fighting(victim)||environment(victim)!=environment(me))
		return ;
	message_vision(MAG"\n��������â��ʢ��������꣬ת˲��ֻ��$N��ͬ�����һ�㣬ֱͦͦ�ĵ�����ȥ��\n\n" NOR,victim);
	room = environment(victim);
	if(objectp(corpse = CHAR_D->make_corpse(victim, me)))
		corpse->move(room);
//	victim->be_ghost(1);
	victim->move("/d/death/gate");
	return;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

