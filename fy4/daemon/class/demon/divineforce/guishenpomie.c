// annie 6.27.03
// purge pets.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int check_legit(object ob); 
int purgepets(object me, object obj);

int perform(object me, object target)
{
	int i;
	object env;
	object * inv;

	if( !me->is_fighting())
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//	message_vision(HIY"\n$N���о��ⶸȻ��ʢ��������ȭƽ�٣������ȵ���"NOR MAG"�롢"YEL"�ϡ�"CYN"�ڡ�"RED"����"GRN"��"BLU"�ޡ�"HIR"�ϡ�"NOR WHT"�š�"HIR BLK"��\n" NOR, me);

	
	message_vision(HIY"\n$N������ȭƽ�٣������鱧��ǰ��ü����������һ�������" NOR, me);
	message_vision(HIY"\n$N���о��ⶸȻ��ʢ�������ȵ���"HIR"��"HIY"��\n\n" NOR, me);
	message_vision(HIY"һ�������������$N���ɢ���������ڳ���ÿ���ˣ��û�Ϊ�߲��쾳��\n" NOR, me);
	env = environment(me);
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if (check_legit(inv[i])) continue;
		if (!COMBAT_D->legitimate_kill(me, inv[i])) continue;
		purgepets(me, inv[i]);
	}
	if (userp(me))
		me->start_busy(1);
//	else
//		me->start_busy(1);
	return 1;
}



int purgepets(object me, object obj)
{
	int a=0;
		string *msg = ({
"���","����С��","ˮ����","����ʹ","��������","ʮ������","С����","è��",
});
// �������,����ѩǳ..
	if (base_name(obj) == "/obj/npc/solidghost")		// ������ solidspirit
		a=1;
	if (base_name(obj) == "/obj/npc/wolf")				// ��ɽ wolf
		a=2;
	if (base_name(obj) == "/obj/npc/danei")				// ��͢ alert-guard
		a=3;
	if (base_name(obj) == "/obj/npc/danei_guard")		// ��͢ alert-guard
		a=3;
	if (base_name(obj) == "/obj/npc/shiwei")			// ��͢ yin shiwei
		a=4;
	if (base_name(obj) == "/obj/npc/fighter1")			// ��͢ yue huwei
		a=5;
	if (base_name(obj) == "/obj/npc/huwei")				// ��͢ yue huwei
		a=5;
	if (base_name(obj) == "/obj/npc/zombie")			// ���� zombie
		a=6;
	if (base_name(obj) == "/obj/npc/hell_guard")		// ���� hell guard
		a=7;
	if (base_name(obj) == "/obj/npc/devil_guard")		// ���� heaven soldier
		a=7;
	if (base_name(obj) == "/obj/npc/taoist_guard")		// ���� sq-taoist
		a=8;
	if (base_name(obj) == "/obj/npc/heaven_soldier")	// ���� sq-taoist
		a=8;
	if (base_name(obj) == "/obj/npc/fire_crane")		// ���� fire crane
		a=9;

	switch (a)
	{
	case 0:
		return 1;
		break;
	case 1:
		message_vision(WHT"\nһ���ö��ĳ�ʫ���������д�����\n$N"WHT"ͷ���ϸ��ֳ�һ��СС��Ȧ�����󳤳�һ�Խ�׵ĳ��\n$N"WHT"���ĳ�򣬷�����ղ�����\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 2:
		message_vision(HIG"\n��֪���ﴫ��һ������Ʈ��Ŀ���������\n$N"HIG"�Ķ�����ͻȻ����һ�������������\n$N"HIG"��������ĳ�����һ�ۣ�ҡҡβ��һ���̵��ܵ��ˡ�\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 3:
		message_vision(HIR"\n��Զ����һ�����������˼���ɽ�����ˡ�\nɽ������̽ͷ̽�ԵĿ�����ߣ�����ߴߴ����������ʲô��\nһ�ѹ�ͷ������������ƫ���еĴ���$N"HIR"���ؿڣ��������л���������Զȥ��\n"NOR,obj);
		obj->die();
	//	obj->ccommand("smile");
		break;
	case 4:
		message_vision(HIY"\n���������һ�����ɫ�Ĺ�â������$N"HIY"���ϡ�\n$N"HIY"��Ȼ��ס�����������ţ��ֻ�������\n$N"HIY"�Ҵ�ææ����һ�������ȥ��һ����һ�߸߽У�ϴ�ּ䣬ϴ�ּ䣡\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 5:
		message_vision(HIC"\n����ĺѻ�����д���ʴ�����$N"HIC"�������Լ���ͷ��̧ͷ���˿���ա�\n$N"HIC"˵��������˧Լ�Ҽ����ʱ��쵽�ˣ��һ�����ȥΪ�\n$N"HIC"��ʶ��һ�·��򣬼���ææ���뿪�ˡ�\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 6:
		message_vision(HIR BLK"\n��֪���ﴫ��һ��������ζ��һ˿һ�Ƶ�Ѭ��"HIR BLK"$N��\n"NOR,obj);
		obj->die();
		break;
	case 7:
		message_vision(HIB"\nԶԶ���ƺ��н��������������\n$N"HIB"������������������������µĹ�Ǯ��û��������������\n$N"HIB"ĥ��ĥ��������һ�»���һ�����ⲻ���ˡ�\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 8:
		message_vision(HIR BLK"\n�߲ʵĹ⻪ӳ����$N"HIR BLK"��\n$N"HIR BLK"������üë����˼������"+msg[random(sizeof(msg))]+"���õ�����ʱ��쵽�˰գ�"HIR BLK"\n$N"HIR BLK"����ָ����һ���Լ������Ŷ�������һ�����ڡ�\n"NOR,obj);
		obj->die();
		break;
	case 9:
		message_vision(HIW"\nԶ������������ণ���������ͬ���������\n$N"HIW"������Х����������һ�ۣ���æ��ȥ��\n"NOR,obj);
		obj->die();
		break;
	}

	return 1;
}

int check_legit(object ob) {
	object me, *team, owner;
	me=this_player();
	
	if (ob->is_corpse() || !ob->is_character() || ob==me) return 1;
	
	team=me->query_team();
	if (team) {
		if (member_array(ob,team)!=-1) return 1;
		if (objectp(owner=ob->query("possessed")))
			if (member_array(owner,team)!=-1) return 1;
	}
	return 0;
}
