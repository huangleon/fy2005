// corpse.c
#include <ansi.h>
inherit ITEM;
int imbue_event(object me);

void create()
{
        set_name("����", ({ "delve" }) );
        set("long", "һ�����ӣ������ƺ�������������ʲô������������\n");
        set("unit", "��" );
        set_max_encumbrance(800000000);
        set("no_get",1);
        
}

int is_container() { return 1; }

void init()
{
	add_action("do_bury","bury");
}

int do_bury()
{	object me;

	me=this_player();
	if (me->query_temp("libie/���_β��") && 
			(present("yang's corpse", this_object()) && present("lu's corpse", this_object())))
	{
		message_vision("$Nһ��һ��Ľ��������˿��У�����򸾵�ʬ��������������\n",me);
		tell_object(me,"���㽫���һ�������������ʱ����ʹ�У����ƺ�������ʲô����һ��Ī�Ƕ�������ô����\n"NOR);
		if(!REWARD_D->imbue_check(me,"���"))
		{
			me->delete_temp("libie");
			me->start_busy(3);
			imbue_event(me); 			
		}
	} else {
		message_vision("$N�û���������ƽ��\n",me);
	}
	destruct(this_object());
	return 1;
}
	
	
int imbue_event(object me){
	object weapon, ob, *inv, obj;
	string prop;
	int i;
	mapping data;
	
	if(!interactive(me) || environment(me) != environment(this_object())) {
		return 0;
	}

	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(YEL"\nһ�����紵��������һ���ɫ��ɳ����\n"NOR, me);
		} else {
			message_vision(YEL"\nһ�����紵��������һ���ɫ��ɳ����$N��" + obj->name() +
					HIR"�ϣ�ת�ۼ��������һ�㱡���Ļ�ɳ��\n"NOR, me);
		}
	}else{
		if(weapon->query("equipped") == "wielded") {
			tell_object(me, "վ����ƽ�������ԣ������г����п������ɵ��ɿ����е�"+weapon->name()+"��\n");
			weapon->unequip();
		}
		message_vision(YEL"\nһ�����紵��������һ���ɫ��ɳ����$N��" + weapon->name() + YEL"�ϣ�ת�ۼ��������һ�㱡���Ļ�ɳ��\n"NOR,
				me);
		message_vision(HIY"\nһ��ҫ�۵Ļ�ɫ��â��" + weapon->name() + 
HIY"����������ɳ��Ȼ������" + weapon->name()+HIY"��ɼ��ˡ�\n"NOR, me);
	}	
	data = ([
		"name":		"���",
		"target":	me,
		"att_3":	"random",
		"att_3c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);
	destruct(this_object());
}	
